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


//printf("1 - Play a snippet of Doom(1998) E1M1");
//printf("2 - Worlds Worst Calculator");
//printf("3 - Random text FG+BG");
//printf("4 - Reset text FG+BG");
//printf("5 - TV Typewriter");
//printf("6 - Test serial ports");
//printf("7 - Music Machine");
//printf("8 - beep the pc speaker");
//printf("9 - Warnings");
//printf("0 - Why IOSNH is a good Operating System");

//byte MIDI[8] = { 0x00, 0x90, 0x3C, 0x64, 0x0C, 0x80, 0x3C, 0x00 };

uint8_t userColor[2] = {VGA_WHITE, VGA_BLACK};

void WWC(){
	cls();
	printf("Welcome to the worlds worst calculator!!!\n\n");
	printf("1 - Add, 2 - Subtract, 3 - Multiply, 4 - Divide\n");
	int opI = input_num("> ");
	t_newline();
	int opA = input_num("A << ");
	t_newline();
	int opB = input_num("B << ");
	t_newline();
	switch(opI){
	case 1:
		//Add
		printf("%d\n", opA+opB);
		break;
	case 2:
		//Sub
		printf("%d\n", opA-opB);
		break;
	case 3:
		//Mult
		printf("%d\n", opA*opB);
		break;
	case 4:
		//Div
		printf("%d\n", opA/opB);
		break;
	}
	printf("Press enter to go back...\n");
	int a = input_num("> ");
}

void SetTextFG_BG(){
	int fg = input_num("Text color >> ");
	int bg = input_num("BG color >> ");
	userColor[0] = fg;
	userColor[1] = bg;
	t_setcolor(fg,bg);
}

void ResetTextFG_BG(){
	userColor[0] = VGA_WHITE;
 	userColor[1] = VGA_BLACK;
	t_setcolor(VGA_WHITE,VGA_BLACK);
}

void TVTypewriter(){
	cls();
	printf("To leave TV Typewriter press the F12 key\n");
	t_seperator('-');
	t_newline();
	while(last_key != 0xFF){int a = inb(0x60);}
}

void TestSerialPorts(){
	cls();
	start_serial(COM1);
	start_serial(COM2);
	start_serial(COM3);
	start_serial(COM4);
	start_serial(COM5);
	start_serial(COM6);
	start_serial(COM7);
	start_serial(COM8);
	int a = input_num("Press enter to go back > ");
}

void Warnings(){
	cls();
	printf("Please be careful with pressing backspace and enter\n");
	printf("it can lcok-up the OS.\n");
	printf("Use them when absolutely needed!\n\n");
	int a = input_num("Press enter to go back > ");
}

void INFO(){
	cls();
	printf("IOSNH is a good OS because\n");
	printf("Allan, please add details.\n\n");
	int a = input_num("Press enter to go back > ");
}

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

	while(1){
		cls();
		t_setcolor(VGA_LIGHT_CYAN, VGA_BLACK);
		enable_cursor(15,15);
		printf("\nWelcome to IOSNH!\n");
		t_setcolor(userColor[0], userColor[1]);
		t_seperator('/');
		clear_input_buffer();
		printf("Choose an option:\n");
		printf("1 - Play a snippet of Doom(1998) E1M1\n");
		printf("2 - Worlds Worst Calculator\n");
		printf("3 - Set text FG+BG\n");
		printf("4 - Reset text FG+BG\n");
		printf("5 - TV Typewriter\n");
		printf("6 - Test serial ports\n");
		printf("7 - Unused\n");
		printf("8 - beep the pc speaker\n");
		printf("9 - Warnings\n");
		printf("0 - Why IOSNH is a good Operating System\n");

		int usrInp = input_num("> ");
		switch(usrInp){
		case 0:
			INFO();
			break;
		case 1:
			DOOM(1);
			break;
		case 2:
			WWC();
			break;
		case 3:
			SetTextFG_BG();
			break;
		case 4:
			ResetTextFG_BG();
			break;
		case 5:
			TVTypewriter();
			break;
		case 6:
			TestSerialPorts();
			break;
		case 7:
			break;
		case 8:
			pcs_beep();
			break;
		case 9:
			Warnings();
			break;
		}
	}

	for(;;){;}
}