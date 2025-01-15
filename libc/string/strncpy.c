#ifndef STRNCPY_H
#define STRNCPY_H

#include <stddef.h>

char* strncpy(char* dest, const char* src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    // If src is shorter than n, fill the remaining space with '\0'
    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return dest;
}

#endif // STRNCPY_H
