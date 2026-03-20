#ifndef SPECIFIERS_H
#define SPECIFIERS_H

#include <stdbool.h>

typedef struct {
    char specifier;
    bool has_precision; // int precision может быть 0, по этому нужно явно знать, это 0 или это отсутствие precision
    int precision; // %.3d 9 -> 009
    int width;
    char length;
    bool flag_space;
    bool flag_plus;
    bool flag_minus;
} Spec;

#endif

