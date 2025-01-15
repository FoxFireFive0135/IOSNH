#ifndef KERNEL_SYSTEM_H
#define KERNEL_SYSTEM_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <kernel/io.h>
#include <ktypes.h>

/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

extern bool write_to_input_buffer;
extern uchar input_buffer[128];
extern uchar last_key;
extern uint kbd_inp_buf_index;

extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install(void);

extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install(void);

extern void isr_install(void);

extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
extern void irq_uninstall_handler(int irq);
extern void irq_install(void);

extern void timer_wait(uint32_t ticks);
extern void timer_install(void);

extern void keyboard_install(void);
extern void clear_input_buffer(void);
extern int input_num(char* prompt);

#endif