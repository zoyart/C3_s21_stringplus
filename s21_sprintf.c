#include "s21_string.h"
#include "specifiers.h"
#include "s21_sprintf.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/*
    Функционал:
        Форматирует строку и записывает её не в консоль, а в указанный буфер
    Принимает: 
        char *str - буфер, куда будет записан результат
        const char *format — строка формата ("Hello %d")
        ... - переменное число аргументов (числа, строки и т.д.)
    Возвращает: 
        Количество записанных символов (без \0)
    Важный момент:
        sprintf НЕ проверяет размер буфера
*/
int s21_sprintf(char *str, const char *format, ...) {
    int ch_count = 0;
    va_list args;

    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        Spec spec = {0};
        char ch = format[i];

        if (ch == '%') {
            parsing_specifiers(&i, format, &spec);
            switch(spec.specifier) {
                case 'd':
                    perform_d(spec, str, &ch_count, &args);
                    break;
                case 'c':
                    perform_c(spec, str, &ch_count, &args);
                    break;
                case 's':
                    perform_s(spec, str, &ch_count, &args);
                    break;
                case 'f':
                    perform_f(spec, str, &ch_count, &args);
                    break;
                case 'u':
                    perform_u(spec, str, &ch_count, &args);
                    break;
                case '%':
                    str[ch_count++] = '%';
                    break;
            }
        } else {
            str[ch_count++] = ch; // Не спецификатор, добавляем в буффер
        }
    }
    
    str[ch_count] = '\0';
    va_end(args);
    return ch_count;
}

/*
    Функционал:
        Парсит спецификаторы после %
    Возвращает:
        Есть ли ошибка
    Шаблон:
        %[flags][width][.precision][length]specifier
*/
void parsing_specifiers(int *idx, const char *format, Spec *spec) {
    bool has_error = 0;
    (*idx)++; // Чтобы повторно не считывать %

    while (format[*idx] == '-' || format[*idx] == '+' || format[*idx] == ' ') {
        if (format[*idx] == '-') spec->flag_minus = true;
        else if (format[*idx] == '+') spec->flag_plus = true;
        else if (format[*idx] == ' ') spec->flag_space = true;
        (*idx)++;
    }

    // Кол-во отступов
    while (isdigit(format[*idx])) {
        spec->width = spec->width * 10 + (format[*idx] - '0');
        (*idx)++;
    }

    // Точность
    if (format[*idx] == '.') {
        (*idx)++;
        spec->precision = 0;
        spec->has_precision = true;
        while (isdigit(format[*idx])) {
            spec->precision = spec->precision * 10 + (format[*idx] - '0');
            (*idx)++;
        }
    }

    // Ддина
    if (format[*idx] == 'h' || format[*idx] == 'l' || format[*idx] == 'L') {
        spec->length = format[*idx];
        (*idx)++;
    }

    // Спецификатор
    char allow_specifiers[] = "cdfsu%";
    if (strchr(allow_specifiers, format[*idx])) {
        spec->specifier = format[*idx];
    }
}

/*
    Функционал:
        С помощью рекурсии преобразуем число в символ 
*/
void write_digits(char *str, int *ch_count, long num) {
    if (num >= 10) {
        write_digits(str, ch_count, num / 10);
    }

    str[(*ch_count)++] = '0' + (num % 10);
}

/*
    Функционал:
        С помощью рекурсии считаем кол-во символов
*/
int count_digits(long num) {
    if (num < 0) num = -num; // минус не считаем
    
    if (num < 10) {
        return 1;
    }
    
    return 1 + count_digits(num / 10);  // Текущая цифра + остальные
}

void write_int(Spec spec, char *str, int *ch_count, long num) {
    int digits_in_num = count_digits(num);

    // Учитываем символ '+' или ' ' в ширине и если число отрицательное
    int sign_width = (num < 0 || spec.flag_plus || spec.flag_space) ? 1 : 0;

    int real_width = (spec.has_precision && spec.precision > digits_in_num) 
        ? spec.precision + sign_width  // precision задаёт минимум цифр
        : digits_in_num + sign_width;  // иначе просто цифры числа

    // Пробелы слева (без флага -)
    if (spec.width && !spec.flag_minus) {
        for (int k = 0; k < spec.width - real_width; k++) {
            str[(*ch_count)++] = ' ';
        }
    }

    set_space(spec, str, ch_count, num);
    set_plus(spec, str, ch_count, num);

    if (num < 0) {
        str[(*ch_count)++] = '-';
        num = -num;
    }

    if (spec.has_precision) {
        for (int k = 0; k < spec.precision - digits_in_num; k++) {
            str[(*ch_count)++] = '0';
        }
    }

    // Сочетание precision = 0 и значение = 0 - даёт пропуск
    if (!(spec.has_precision && spec.precision == 0 && num == 0)) {
        write_digits(str, ch_count, num);
    }

    // Пробелы справа (флаг -)
    if (spec.width && spec.flag_minus) {
        for (int k = 0; k < spec.width - real_width; k++) {
            str[(*ch_count)++] = ' ';
        }
    }
}

void write_unsigned_int(Spec spec, char *str, int *ch_count, unsigned long num) {
    int digits_in_num = count_digits(num);

    int real_width = (spec.has_precision && spec.precision > digits_in_num) 
        ? spec.precision  // precision задаёт минимум цифр
        : digits_in_num;  // иначе просто цифры числа

    // Пробелы слева (без флага -)
    if (spec.width && !spec.flag_minus) {
        for (int k = 0; k < spec.width - real_width; k++) {
            str[(*ch_count)++] = ' ';
        }
    }

    if (spec.has_precision) {
        for (int k = 0; k < spec.precision - digits_in_num; k++) {
            str[(*ch_count)++] = '0';
        }
    }

    // Сочетание precision = 0 и значение = 0 - даёт пропуск
    // TODO: баг с нулём при default значении, нужно проверять ещё num
    if (!(spec.has_precision && spec.precision == 0 && num == 0)) {
        write_digits(str, ch_count, num);
    }

    // Пробелы справа (флаг -)
    if (spec.width && spec.flag_minus) {
        for (int k = 0; k < spec.width - real_width; k++) {
            str[(*ch_count)++] = ' ';
        }
    }
}

void set_plus(Spec spec, char *str, int *ch_count, long num) {
    if (spec.flag_plus && num >= 0) {
        str[(*ch_count)++] = '+';
    }
}

void set_space(Spec spec, char *str, int *ch_count, long num) {
    // NOTE: у плюса больше приоритет над пробелом
    if (spec.flag_space && !spec.flag_plus && num >= 0) {
        str[(*ch_count)++] = ' ';
    }
}

void perform_d(Spec spec, char *str, int *ch_count, va_list *args) {
    long num; // Делаем самый большой тип, чтобы была возможность ужать
    if (spec.length == 'l') {
        num = va_arg(*args, long);
    } else if (spec.length == 'h') {
        num = (short)va_arg(*args, int);
    } else {
        num = va_arg(*args, int);
    }

    write_int(spec, str, ch_count, num);  
}

/*
    NOTE: тяжело сделать одну функцию (write_...) для u и d, 
    так как width и precision логически сильно связаны
*/
void perform_u(Spec spec, char *str, int *ch_count, va_list *args) {
    unsigned long num; // Делаем самый большой тип, чтобы была возможность ужать
    if (spec.length == 'l') {
        num = va_arg(*args, unsigned long);
    } else if (spec.length == 'h') {
        num = (unsigned short)va_arg(*args, int);
    } else {
        num = va_arg(*args, unsigned int);
    }

    write_unsigned_int(spec, str, ch_count, num);  
}

void perform_c(Spec spec, char *str, int *ch_count, va_list *args) {
    // NOTE: char автоматически повышается до int при передаче через ..., 
    // поэтому va_arg(*args, int), а потом кастовать обратно в char.
    char ch = (char)va_arg(*args, int);
    int ch_len = 1;

    // Пробелы слева (без флага -)
    if (spec.width && !spec.flag_minus) {
        for (int k = 0; k < spec.width - ch_len; k++) {
            str[(*ch_count)++] = ' ';
        }
    }

    str[(*ch_count)++] = ch;

    // Пробелы справа (флаг -)
    if (spec.width && spec.flag_minus) {
        for (int k = 0; k < spec.width - ch_len; k++) {
            str[(*ch_count)++] = ' ';
        }
    }
}

/*
    NOTE:  точность применяется ДО ширины
    printf("%10.5s", "HelloWorld");

    Hello -> сначала точность
         Hello -> потом добавляется ширина
*/
void perform_s(Spec spec, char *str, int *ch_count, va_list *args) {
    char *arg_str = va_arg(*args, char *);
    int arg_str_len = strlen(arg_str);

    if (spec.has_precision && spec.precision < arg_str_len) {
        arg_str_len = spec.precision;
    }

    // Пробелы слева (без флага -)
    if (spec.width && !spec.flag_minus) {
        for (int k = 0; k < spec.width - arg_str_len; k++) {
            str[(*ch_count)++] = ' ';
        }
    }

    for (int i = 0; i < arg_str_len; i++) {
        str[(*ch_count)++] = arg_str[i];
    }
    
    // Пробелы справа (флаг -)
    if (spec.width && spec.flag_minus) {
        for (int k = 0; k < spec.width - arg_str_len; k++) {
            str[(*ch_count)++] = ' ';
        }
    }
}

// ne Danil lessss go!!!
void perform_f(Spec spec, char *str, int *ch_count, va_list *args) {

}