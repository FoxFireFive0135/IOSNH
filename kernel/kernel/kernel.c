#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/io.h>
#include <kernel/system.h>
#include <kernel/video.h>
#include <kernel/audio.h>
#include <kernel/audio_notes.h>
#include <kernel/serial_com.h>

void DOOM(int BPM){
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(D4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(C4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(AS3,3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(B3, 3*BPM);
	pcs_play_note(C4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(D4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(C4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(AS3,9*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(D4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(C4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(AS3,3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(B3, 3*BPM);
	pcs_play_note(C4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(D4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(C4, 3*BPM);
	pcs_play_note(E3, 3*BPM);
	pcs_play_note(E3, 3*BPM);
}


byte MIDI[8] = { 0x00, 0x90, 0x3C, 0x64, 0x0C, 0x80, 0x3C, 0x00 };

void kernel_main(void) {

	gdt_install();
	idt_install();
	isr_install();
	irq_install();
	t_initialize();
	timer_install();
    keyboard_install();

    //LOL this makes the whole os work.
	__asm__ __volatile__ ("sti");

	t_setcolor(VGA_LIGHT_CYAN, VGA_BLACK);
	enable_cursor(15,15);
	printf("Welcome to IOSNH!\n");
	t_setcolor(VGA_WHITE, VGA_BLACK);
	t_seperator('/');

	bool irqcheck = are_interrupts_enabled();
	if(irqcheck){
		t_setcolor(VGA_GREEN, VGA_BLACK);
		printf("interrupts are enabled!\n");
	}else{
		t_setcolor(VGA_RED, VGA_BLACK);
		printf("interrupts are not enabled!\n");
	}
	t_setcolor(VGA_WHITE, VGA_BLACK);

	int videotype = get_bios_area_video_type();
	switch(videotype){
	case 0x00:
		printf("No video type detected...\n\n");
		break;
	case 0x20:
		//To-Do: make text rainbow
		printf("Color monitor detected\n\n");
		break;
	case 0x30:
		printf("Monochrome monitor detected\n\n");
		break;
	default:
		break;
	}
	t_setcolor(VGA_WHITE, VGA_BLACK);

	//start_serial(COM1);

	
	while(1){
		clear_input_buffer();
		int a = input_num("Input a number: ");
		int b = 2;
		printf("%d\n", a * b);
	}

	for(;;){;}
}