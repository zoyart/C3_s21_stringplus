#ifndef S21_STRING_H
#define S21_STRING_H

// Замена unsigned long на s21_size в коде
typedef unsigned long s21_size;

// Создаёт константу нулевого указателя
#define S21_NULL ((void *)0) // #define S21_NULL NULL Можно ли сделать так?

// Артур
int s21_sprintf(char *str, const char *format, ...);

// Егор
void *s21_memchr(const void *str, int c, s21_size n);
void *s21_memcpy(void *dest, const void *src, s21_size n);
void *s21_memset(void *str, int c, s21_size n);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);

// Никита
int s21_memcmp(const void *str1, const void *str2, s21_size n);
char *s21_strncpy(char *dest, const char *src, s21_size n);
char *s21_strncat(char *dest, const char *src, s21_size n);
s21_size s21_strcspn(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size n);

// Данил
s21_size s21_strlen(const char *str);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);

#endif