#ifndef KERNEL_AUDIO_H
#define KERNEL_AUDIO_H

#include <stdint.h>
#include <stddef.h>
#include <kernel/io.h>
#include <kernel/system.h>

//Play sound using built-in speaker
static void pcs_play_sound(uint32_t nFrequence) {
	uint32_t Div;
	uint8_t tmp;

    //Set the PIT to the desired frequency
	Div = 1193180 / nFrequence;
	outb(0x43, 0xb6);
	outb(0x42, (uint8_t) (Div) );
	outb(0x42, (uint8_t) (Div >> 8));

    //And play the sound using the PC speaker
	tmp = inb(0x61);
 	if (tmp != (tmp | 3)) {
		outb(0x61, tmp | 3);
	}
}

//make it shut up
static void pcs_nosound() {
	uint8_t tmp = inb(0x61) & 0xFC;
	outb(0x61, tmp);
}

//Make a beep
static void pcs_beep() {
	 pcs_play_sound(1000);
	 timer_wait(4);
	 pcs_nosound();
}

//Make a beep
static void pcs_play_note(uint32_t note, uint32_t length) {
	 pcs_play_sound(note);
	 timer_wait(length);
	 pcs_nosound();
}

#endif