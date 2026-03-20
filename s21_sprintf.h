#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "specifiers.h"
#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...);

int parsing_specifiers(int *idx, const char *format, Spec *specifiers_data);

void write_digits(char *str, int *ch_count, long long num);
int count_digits(long long num);

void set_plus(Spec spec, char *str, int *ch_count, long long num);
void set_space(Spec spec, char *str, int *ch_count, long long num);
void write_int(Spec spec, char *str, int *ch_count, long long num);

void perform_d(Spec spec, char *str, int *ch_coun, va_list args);
void perform_c(Spec spec, char *str, int *ch_count, va_list args);
void perform_s(Spec spec, char *str, int *ch_count, va_list args);
void perform_f(Spec spec, char *str, int *ch_count, va_list args);

#endif