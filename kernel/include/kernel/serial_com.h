#ifndef KERNEL_SERIAL_COM_H
#define KERNEL_SERIAL_COM_H

#include <stdint.h>
#include <stddef.h>
#include <kernel/io.h>
#include <stdio.h>
#include <kernel/video.h>
#include <kernel/tty.h>
#include <ktypes.h>

#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8
#define COM5 0x5F8
#define COM6 0x4F8
#define COM7 0x5E8
#define COM8 0x4E8

static char* portToCom(uint PORT){
	switch(PORT){
	case COM1:
		return "COM1";
		break;
	case COM2:
		return "COM2";
		break;
	case COM3:
		return "COM3";
		break;
	case COM4:
		return "COM4";
		break;
	case COM5:
		return "COM5";
		break;
	case COM6:
		return "COM6";
		break;
	case COM7:
		return "COM7";
		break;
	case COM8:
		return "COM8";
		break;
	default:
		return "Not a port.";
	}
}

static int start_serial(uint PORT) {
	outb(PORT + 1, 0x00);    // Disable all interrupts
	outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
	outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
	outb(PORT + 1, 0x00);    //                  (hi byte)
	outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
	outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
	outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
	outb(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
	outb(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

	// Check if serial is faulty (i.e: not same byte as sent)
	if(inb(PORT + 0) != 0xAE) {
		t_setcolor(VGA_RED, VGA_BLACK);
		printf("%s - Faulty or non-existant port\n",portToCom(PORT));
		t_setcolor(VGA_WHITE, VGA_BLACK);
	   return 1;
	}

	// If serial is not faulty set it in normal operation mode
	// (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
	outb(PORT + 4, 0x0F);
	printf("%s has been initialized:\n 38400 baud,\n 8 bits,\n no parity,\n one stop bit.\n", portToCom(PORT));
	return 0;
}

static int serial_received(uint PORT) {
   return inb(PORT + 5) & 1;
}

static char read_serial(uint PORT) {
   while (serial_received(PORT) == 0);

   return inb(PORT);
}

static int is_transmit_empty(uint PORT) {
   return inb(PORT + 5) & 0x20;
}

static void write_serial(char a, uint PORT) {
   while (is_transmit_empty(PORT) == 0);

   outb(PORT,a);
}

#endif