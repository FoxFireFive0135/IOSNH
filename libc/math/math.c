#include <math.h>

/* Absolute value */
double fabs(double x) {
    return x < 0 ? -x : x;
}

/* Power function: x^y */
double pow(double base, double exp_) {
    if (exp_ == 0) return 1;
    if (exp_ < 0) return 1 / pow(base, -exp_);

    double result = 1;
    while (exp_ >= 1) {
        result *= base;
        exp_--;
    }

    double fraction = exp_; // Handle fractional part of exponent
    if (fraction > 0) {
        result *= exp(fraction * log(base));
    }

    return result;
}

/* Square root using Newton's method */
double sqrt(double x) {
    if (x < 0) return -1; // Return -1 for invalid input (negative numbers)
    double guess = x / 2.0;
    double epsilon = 1e-9;

    while (fabs(guess * guess - x) > epsilon) {
        guess = (guess + x / guess) / 2.0;
    }

    return guess;
}

/* Trigonometric functions using Taylor series */
double sin(double x) {
    double result = 0;
    double term = x;

    for (int i = 1; fabs(term) > 1e-9; i++) {
        result += term;
        term *= -1 * x * x / ((2 * i) * (2 * i + 1));
    }

    return result;
}

double cos(double x) {
    double result = 0;
    double term = 1;

    for (int i = 1; fabs(term) > 1e-9; i++) {
        result += term;
        term *= -1 * x * x / ((2 * i - 1) * (2 * i));
    }

    return result;
}

double tan(double x) {
    return sin(x) / cos(x);
}

/* Exponential function using Taylor series */
double exp(double x) {
    double result = 1;
    double term = 1;

    for (int n = 1; fabs(term) > 1e-9; n++) {
        term *= x / n;
        result += term;
    }

    return result;
}

/* Natural logarithm using approximation (Newton's method) */
double log(double x) {
    if (x <= 0) return -1; // Undefined for x <= 0

    double guess = x / 2.0;
    double epsilon = 1e-9;

    while (fabs(exp(guess) - x) > epsilon) {
        guess -= (exp(guess) - x) / exp(guess);
    }

    return guess;
}

/* Base-10 logarithm */
double log10(double x) {
    return log(x) / M_LN10;
}

/* Rounding down */
double floor(double x) {
    int as_int = (int)x;
    return x < as_int ? as_int - 1 : as_int;
}

/* Rounding up */
double ceil(double x) {
    int as_int = (int)x;
    return x > as_int ? as_int + 1 : as_int;
}

/* Floating-point modulus */
double fmod(double x, double y) {
    if (y == 0) return 0; // Modulus by zero is undefined
    return x - y * (int)(x / y);
}
