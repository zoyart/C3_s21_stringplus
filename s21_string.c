#include "s21_string.h"

s21_size s21_strlen(const char *str) { return 1; }

void *s21_memcpy(void *dest, const void *src, s21_size n) {}

void *s21_memchr(const void *str, int c, s21_size n) {}

int s21_memcmp(const void *str1, const void *str2, s21_size n) {
  /*
   * Функция для сравния первых n байтов str1 и str2
   * Если str1 и str2 идентичны
   * возвращает 0 - как в стандартной функции
   * Если str1 и str2 разные
   * возвращает разность байтов - как в стандартной функции
   */
  int result = 0;
  /*
   * Если (str1 == str2) не пустые
   * Если адреса одинаковые (str1 == str2)
   * и
   * Размер n = 0 — сравнивать нечего
   * Выходим из функции c result = 0
   * Функция завершается мгновенно
   * Не создаем переменные
   * Экономим память и время процессора
   */
  if (str1 != S21_NULL && str2 != S21_NULL && str1 != str2 && n != 0) {
    /*
     * Приравниваем void к char добавляем unsigned что бы байты считались от 0
     * до 255 а не (-)128 - 127 критично для кирилици
     * Использование const для гарантирует неизменность исходных данных.
     * Это делает функцию безопасной: мы только читаем символы,
     * не модифицируя их, что подтверждается контрактом функции.
     */
    const unsigned char *string1 = str1;
    const unsigned char *string2 = str2;
    s21_size i = 0;
    /*
     * Составное условие выхода i < n && result == 0
     */
    for (i = 0; i < n && result == 0; i++) {
      if (string1[i] != string2[i]) {
        /*
         * Делаем явное приведение типов к int
         */
        result = (int)string1[i] - (int)string2[i];
      }
    }
  }
  return result;
}

void *s21_memset(void *str, int c, s21_size n) {}

char *s21_strncat(char *dest, const char *src, s21_size n) {
  /*
   * Функция добавляет строку, на которую указывает src, в конец строки, на
   * которую указывает dest, длиной до n символов
   * char *s21_strncat возвращает адрес dest т.к. после char стоил указатель (*)
   * char *dest - можно изменять
   * const char *src - изменять запрещено
   * Использование const гарантирует неизменность исходных данных.
   * Это делает функцию безопасной: мы только читаем символы,
   * не модифицируя их, что подтверждается контрактом функции.
   * Если n = 0 то добавлять нечего мы сразу
   * возвращаем dest
   * Функция завершается мгновенно
   * Не создаем переменные
   * Экономим память и время процессора
   */
  if (dest != S21_NULL && src != S21_NULL && n != 0) {
    /*
     * Необходима функция s21_strlen в противном случае надо написать свою
     * функцию подсчета котичества символов до '\0' что выльется в дублирования
     * кода с s21_strlen
     */
    s21_size destLen = s21_strlen(dest);
    /*
     * Выносим i за цикл для определения длины получившейся строки и
     * добавления символа конца строки за циклом '\0'
     * Используем принцип защитного программирования и не оставляем не
     * инициализированные переменные
     */
    s21_size i = 0;
    /*
     * Добавляем в dest строку src
     * Если строка src длинее n то src целиком не влезет
     * Если n больше длины src то мы запишим всю строку src
     * остановимся игнорируя n
     * i = 0 - снова инициализируем для красоты цикла for() хотя можно бойтись и
     * пустым значением for (; i < n && src[i] != '\0'; i++)
     */
    for (i = 0; i < n && src[i] != '\0'; i++) {
      dest[destLen + i] = src[i];
    }
    /*
     * Добавляем символ конца строки '\0'
     */
    dest[destLen + i] = '\0';
  }
  return dest;
}

char *s21_strchr(const char *str, int c) { return S21_NULL; }

int s21_strncmp(const char *str1, const char *str2, s21_size n) {
  /*
   * Сравнивает не более первых n байтов str1 и str2.
   * мое
   */
  return 1;
}

char *s21_strncpy(char *dest, const char *src, s21_size n) {
  /*
   * Копирует до n символов из строки, на которую указывает src, в dest.
   * мое
   */
  return S21_NULL;
}

s21_size s21_strcspn(const char *str1, const char *str2) {
  /*
   * Вычисляет длину начального сегмента str1, который полностью состоит из
   * символов, не входящих в str2. мое
   */
  return 1;
}

char *s21_strerror(int errnum) { return S21_NULL; }

char *s21_strpbrk(const char *str1, const char *str2) { return S21_NULL; }

char *s21_strrchr(const char *str, int c) { return S21_NULL; }

char *s21_strtok(char *str, const char *delim) { return S21_NULL; }

char *s21_strstr(const char *haystack, const char *needle) { return S21_NULL; }