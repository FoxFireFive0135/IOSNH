#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <kernel/io.h>

void t_initialize(void);
void t_putchar(char c);
void t_write(const char* data, size_t size);
void t_writestring(const char* data);
void t_seperator(unsigned char c);
void t_setcolor(uint8_t fg, uint8_t bg);
void t_newline(void);
void cls(void);
void move_csr(void);
void scroll(void);
void t_setpos(int x, int y);
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void disable_cursor(void);
void update_cursor(int x, int y);
uint16_t get_cursor_position(void);

#endif
