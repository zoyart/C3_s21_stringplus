#include "s21_string.h"

s21_size s21_strlen(const char *str) { return 1; }

void *s21_memcpy(void *dest, const void *src, s21_size n) {}

void *s21_memchr(const void *str, int c, s21_size n) {}

/*
 * @brief Сравнивает первые n байтов двух блоков памяти.
 *
 * @details Функция выполняет побайтовое сравнение. Использует unsigned char
 * для корректной обработки значений от 0 до 255 (важно для кириллицы).
 *
 * @param str1 Указатель на первый блок памяти (const void*).
 * @param str2 Указатель на второй блок памяти (const void*).
 * @param n Количество байтов для сравнения (s21_size).
 *
 * @return Разность первых несовпавших байтов (int).
 *         0 — если блоки идентичны или n = 0.
 *
 * @note Если адреса str1 и str2 совпадают, функция возвращает 0 мгновенно.
 */
int s21_memcmp(const void *str1, const void *str2, s21_size n) {
  int result = 0;

  // Предворительная проверка для оптимизации и безопасности
  if (str1 != S21_NULL && str2 != S21_NULL && str1 != str2 && n != 0) {
    const unsigned char *string1 = str1;
    const unsigned char *string2 = str2;
    s21_size i = 0;

    // Составное условие выхода i < n && result == 0
    for (i = 0; i < n && result == 0; i++) {
      if (string1[i] != string2[i]) {
        // Делаем явное приведение типов к int
        result = (int)string1[i] - (int)string2[i];
      }
    }
  }
  return result;
}

void *s21_memset(void *str, int c, s21_size n) {}

/*
 * @brief Добавляет до n символов из строки src в конец строки dest.
 *
 * @details Находит конец строки dest и копирует туда символы из src.
 * Процесс останавливается, если скопировано n символов или встречен '\0' в src.
 * Всегда добавляет терминальный нулевой символ '\0' в конец результата.
 *
 * @param dest Указатель на строку назначения (куда приклеиваем). (char *)
 * @param src Указатель на исходную строку (откуда берем). (const char*)
 * @param n  Максимальное количество символов для копирования. (s21_size)
 *
 * @return Указатель на строку назначения (dest).
 *
 * @note Если n = 0 или один из указателей S21_NULL, функция возвращает dest без
 * изменений.
 * @see s21_strlen — используется для определения текущего размера буфера dest.
 *
 * @warning Вызывающий обязан гарантировать, что в dest достаточно места для
 * новой строки.
 */
char *s21_strncat(char *dest, const char *src, s21_size n) {
  // Предворительная проверка для оптимизации и безопасности
  if (dest != S21_NULL && src != S21_NULL && n != 0) {
    // Используем s21_strlen для поиска точки входа в конец строки dest
    s21_size destLen = s21_strlen(dest);
    s21_size i = 0;

    // Копируем символы из src, соблюдая лимит n и проверяя конец src
    for (i = 0; i < n && src[i] != '\0'; i++) {
      dest[destLen + i] = src[i];
    }

    // Принудительно закрываем строку нулевым символом
    dest[destLen + i] = '\0';
  }
  return dest;
}

char *s21_strchr(const char *str, int c) { return S21_NULL; }

/*
 * @brief  Сравнивает не более первых n байтов str1 и str2.
 * МОЕ
 */
int s21_strncmp(const char *str1, const char *str2, s21_size n) { return 1; }

/*
 * @brief  Копирует до n символов из строки, на которую указывает src, в dest.
 * МОЕ
 */
char *s21_strncpy(char *dest, const char *src, s21_size n) { return S21_NULL; }

/*
 * @brief Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов, не входящих в str2.
 * МОЕ
 */
s21_size s21_strcspn(const char *str1, const char *str2) { return 1; }

char *s21_strerror(int errnum) { return S21_NULL; }

char *s21_strpbrk(const char *str1, const char *str2) { return S21_NULL; }

char *s21_strrchr(const char *str, int c) { return S21_NULL; }

char *s21_strtok(char *str, const char *delim) { return S21_NULL; }

char *s21_strstr(const char *haystack, const char *needle) { return S21_NULL; }