#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t t_row;
static size_t t_column;
static uint8_t t_color;
static uint16_t* t_buffer;

void t_initialize(void) {
	t_row = 0;
	t_column = 0;
	t_color = vga_entry_color(VGA_LIGHT_GREY, VGA_BLACK);
	t_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			t_buffer[index] = vga_entry(' ', t_color);
		}
	}
}

void t_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	t_buffer[index] = vga_entry(c, color);
}

void t_putchar(char c) {
	unsigned char uc = c;
	switch(uc){
	case '\n':
		t_column = -1;
		++t_row;
		break;
	case '\b':
		t_column--;
		t_putentryat(' ', t_color, t_column, t_row);
		t_column--;
		break;
	default:
		t_putentryat(uc, t_color, t_column, t_row);
		break;
	}

	if (++t_column == VGA_WIDTH) {
		t_column = 0;
		if (++t_row == VGA_HEIGHT)
			t_row = 0;
	}

	update_cursor(t_column, t_row);
}

void t_seperator(unsigned char c){
	for (int x = 0; x<VGA_WIDTH; x++){
		t_putchar(c);
	}
}

void t_newline(){
	t_row++;
	t_column = 0;
}

void t_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		t_putchar(data[i]);
}

void t_setcolor(uint8_t fg, uint8_t bg){
	t_color = fg | bg << 4;
}

void t_writestring(const char* data) {
	t_write(data, strlen(data));
}

/* Updates the hardware cursor: the little blinking line
*  on the screen under the last character pressed! */

/* Clears the screen */
void cls()
{
    for (int x = 0; x < VGA_WIDTH; ++x)
    {
    	for (int y = 0; y < VGA_HEIGHT; ++y)
    	{
    		t_buffer[x+y] = 0;
    	}
    }
    /* Update out virtual cursor, and then move the
    *  hardware cursor */
    t_column = 0;
    t_row = 0;
}

/* Scrolls the screen */
void scroll()
{
    memmove(t_buffer-80, t_buffer, VGA_WIDTH*VGA_HEIGHT);
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void update_cursor(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

uint16_t get_cursor_position()
{
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
}

void t_setpos(int x, int y){
	t_column = x;
	t_row = y;
	update_cursor(t_column, t_row);
}