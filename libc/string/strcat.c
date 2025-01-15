#include <string.h>
#include <stddef.h>  // For NULL

// Concatenates src string to the end of dest string
char* strcat(char *dest, const char *src) {
    char *dest_orig = dest;  // Keep track of the beginning of dest

    // Move dest to the end of the current string
    while (*dest != '\0') {
        dest++;
    }

    // Append each character of src to dest
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    // Null-terminate the concatenated string
    *dest = '\0';

    return dest_orig;  // Return the original dest pointer
}

// Copies the string pointed to by src (including the null terminator) to dest
char* strcpy(char *dest, const char *src) {
    char *dest_orig = dest;  // Save the original destination pointer

    // Copy each character from src to dest until we encounter the null terminator
    while (*src != '\0') {
        *dest = *src;  // Copy the character
        dest++;         // Move to the next position in dest
        src++;          // Move to the next character in src
    }

    // Null-terminate the copied string
    *dest = '\0';

    return dest_orig;  // Return the original dest pointer
}