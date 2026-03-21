#include "s21_string.h"

#include <stdio.h>

int main () {
    char buff1[100];
    char str1[] = "Some %s aga";
    char str[] = "text";
    s21_sprintf(buff1, str1, str);
    printf("Res is: %s\n", buff1);
    
    return 0;
}