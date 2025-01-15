#ifndef _CTYPE_H
#define _CTYPE_H

#include <stdbool.h>  // For bool, true, false

#ifdef __cplusplus
extern "C" {
#endif

// Checks if the character is an uppercase letter (A-Z)
int isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

// Checks if the character is a lowercase letter (a-z)
int islower(int c) {
    return (c >= 'a' && c <= 'z');
}

// Checks if the character is a letter (A-Z or a-z)
int isalpha(int c) {
    return (isupper(c) || islower(c));
}

// Checks if the character is a digit (0-9)
int isdigit(int c) {
    return (c >= '0' && c <= '9');
}

// Checks if the character is alphanumeric (A-Z, a-z, 0-9)
int isalnum(int c) {
    return (isalpha(c) || isdigit(c));
}

// Checks if the character is a space character (whitespace)
int isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

// Converts a character to uppercase
int toupper(int c) {
    if (islower(c)) {
        return c - 'a' + 'A';
    }
    return c;  // Return the character unchanged if it's not lowercase
}

// Converts a character to lowercase
int tolower(int c) {
    if (isupper(c)) {
        return c - 'A' + 'a';
    }
    return c;  // Return the character unchanged if it's not uppercase
}

// Checks if the character is a punctuation character
int ispunct(int c) {
    return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) ||
           (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

// Checks if the character is a control character
int iscntrl(int c) {
    return (c < 32 || c == 127);
}

#ifdef __cplusplus
}
#endif

#endif /* _CTYPE_H */
