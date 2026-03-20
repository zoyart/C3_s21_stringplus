#include "s21_string.h"

#include <stdio.h>

int main () {
    char buff1[100];
    char str1[] = "So%8.5d";
    int a = -42;
    s21_sprintf(buff1, str1, a);
    printf("Res is: %s\n", buff1);
    
    return 0;
}