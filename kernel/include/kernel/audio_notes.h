#ifndef KERNEL_AUDIO_NOTES_H
#define KERNEL_AUDIO_NOTES_H

#include <stdint.h>
#include <stddef.h>
#include <kernel/io.h>
#include <kernel/system.h>

#define C0	16
#define CS0	17
#define D0	18
#define DS0	19
#define E0	20
#define F0	21
#define FS0	23
#define G0	24
#define GS0	25
#define A0	27
#define AS0	29
#define B0	30

#define C1	32
#define CS1	34
#define D1	36
#define DS1	38
#define E1	41
#define F1	43
#define FS1	46
#define G1	49
#define GS1	51
#define A1	55
#define AS1	58
#define B1	61

#define C2	65
#define CS2	69
#define D2	73
#define DS2	77
#define E2	82
#define F2	87
#define FS2	92
#define G2	98
#define GS2	103
#define A2	110
#define AS2	116
#define B2	123

#define C3	130
#define CS3	138
#define D3	146
#define DS3	155
#define E3	164
#define F3	174
#define FS3	185
#define G3	196
#define GS3	207
#define A3	220
#define AS3	233
#define B3	246

#define C4	261
#define CS4	277
#define D4	293
#define DS4	311
#define E4	329
#define F4	349
#define FS4	369
#define G4	392
#define GS4	415
#define A4	440
#define AS4	466
#define B4	493

#define C5	523
#define CS5	554
#define D5	587
#define DS5	622
#define E5	659
#define F5	698
#define FS5	739
#define G5	783
#define GS5	830
#define A5	880
#define AS5	932
#define B5	987

#define C6	1046
#define CS6	1108
#define D6	1174
#define DS6	1244
#define E6	1318
#define F6	1396
#define FS6	1479
#define G6	1567
#define GS6	1661
#define A6	1760
#define AS6	1864
#define B6	1975

#define C7	2093
#define CS7	2217
#define D7	2349
#define DS7	2489
#define E7	2637
#define F7	2793
#define FS7	2959
#define G7	3135
#define GS7	3322
#define A7	3520
#define AS7	3729
#define B7	3951

#define C8	4186
#define CS8	4434
#define D8	4698
#define DS8	4978
#define E8	5274
#define F8	5587
#define FS8	5919
#define G8	6271
#define GS8	6644
#define A8	7040
#define AS8	7458
#define B8	7902

uint16_t MIDI_Note[] = {
	1,    1,	1,	  1,	1,	  1,    1,    1,    1,    1,    1,    1,
	16,   17,   18,   19,   20,   21,   23,   24,   25,   27,   29,   30,
	32,   34,   36,   38,   41,   43,   46,   49,   51,   55,   58,   61,
	65,   69,   73,   77,   82,   87,   92,   98,   103,  110,  116,  123,
	130,  138,  146,  155,  164,  174,  185,  196,  207,  220,  233,  246,
	261,  277,  293,  311,  329,  349,  369,  392,  415,  440,  466,  493,
	523,  554,  587,  622,  659,  698,  739,  783,  830,  880,  932,  987,
	1046, 1108, 1174, 1244, 1318, 1396, 1479, 1567, 1661, 1760, 1864, 1975,
	2093, 2217, 2349, 2489, 2637, 2793, 2959, 3135, 3322, 3520, 3729, 3951,
	4186, 4434, 4698, 4978, 5274, 5587, 5919, 6271, 6644, 7040, 7458, 7902
};

#endif