#ifndef STRING_H
#define STRING_H

#include <sys/cdefs.h>

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);
char* strncpy(char* dest, const char* src, size_t n);
char* strcat(char *dest, const char *src);
char* strcpy(char *dest, const char *src);

#ifdef __cplusplus
}
#endif

#endif
