#include "../s21_string.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

/*
    КАК ДОБАВЛЯТЬ ТЕСТЫ:

    1. Один тест = один кейс
    2. Не используйте test1, test2 — давайте осмысленные имена:
       test_strstr_found
       test_strstr_not_found
    3. На каждый новый кейс — новый START_TEST
    4. Не забывайте добавлять новые тесты в свои подгруппы

    Так не делайте )))
    START_TEST(all_tests)
    {
        // 20 проверок подряд 💀
    }
*/

/*
    Тесты для strstr
*/
START_TEST(test1)
{

}
END_TEST

/*
    Тесты для memchr
*/
START_TEST(test2)
{

}
END_TEST

/*
    Тесты для memset
*/
START_TEST(test3)
{

}
END_TEST

/*
    Тесты для strrchr
*/
START_TEST(test4)
{

}
END_TEST

/*
    Тесты для memcpy
*/
START_TEST(test5)
{

}
END_TEST

/*
    Тесты для memcmp
*/
START_TEST(test6)
{

}
END_TEST

/*
    Тесты для strncpy
*/
START_TEST(test7)
{

}
END_TEST

/*
    Тесты для strncat
*/
START_TEST(test8)
{

}
END_TEST

/*
    Тесты для strncmp
*/
START_TEST(test9)
{

}
END_TEST

/*
    Тесты для strcspn
*/
START_TEST(test10)
{

}
END_TEST

/*
    Тесты для strchr
*/
START_TEST(test11)
{

}
END_TEST

/*
    Тесты для strlen
*/
START_TEST(test12)
{

}
END_TEST

/*
    Тесты для strpbrk
*/
START_TEST(test13)
{

}
END_TEST

/*
    Тесты для strtok
*/
START_TEST(test14)
{

}
END_TEST

/*
    Тесты для strerror
*/
START_TEST(test15)
{

}
END_TEST

Suite *string_suite(void) {
    Suite *s = suite_create("string");

    // strstr подгруппа
    TCase *strstr = tcase_create("strstr");
    tcase_add_test(strstr, test1);

    // memchr подгруппа
    TCase *memchr = tcase_create("memchr");
    tcase_add_test(memchr, test2);

    // memset подгруппа
    TCase *memset = tcase_create("memset");
    tcase_add_test(memset, test3);

    // strrchr подгруппа
    TCase *strrchr = tcase_create("strrchr");
    tcase_add_test(strrchr, test4);

    // memcpy
    TCase *memcpy = tcase_create("memcpy");
    tcase_add_test(memcpy, test5);

    // memcmp
    TCase *memcmp = tcase_create("memcmp");
    tcase_add_test(memcmp, test6);

    // strncpy
    TCase *strncpy = tcase_create("strncpy");
    tcase_add_test(strncpy, test7);

    // strncat
    TCase *strncat = tcase_create("strncat");
    tcase_add_test(strncat, test8);

    // strncmp
    TCase *strncmp = tcase_create("strncmp");
    tcase_add_test(strncmp, test9);

    // strcspn
    TCase *strcspn = tcase_create("strcspn");
    tcase_add_test(strcspn, test10);

    // strchr
    TCase *strchr = tcase_create("strchr");
    tcase_add_test(strchr, test11);

    // strlen
    TCase *strlen = tcase_create("strlen");
    tcase_add_test(strlen, test12);

    // strpbrk
    TCase *strpbrk = tcase_create("strpbrk");
    tcase_add_test(strpbrk, test13);

    // strtok
    TCase *strtok = tcase_create("strtok");
    tcase_add_test(strtok, test14);

    // strerror
    TCase *strerror = tcase_create("strerror");
    tcase_add_test(strerror, test15);

    suite_add_tcase(s, strstr);
    suite_add_tcase(s, memchr);
    suite_add_tcase(s, memset);
    suite_add_tcase(s, strrchr);
    suite_add_tcase(s, memcpy);
    suite_add_tcase(s, memcmp);
    suite_add_tcase(s, strncpy);
    suite_add_tcase(s, strncat);
    suite_add_tcase(s, strncmp);
    suite_add_tcase(s, strcspn);
    suite_add_tcase(s, strchr);
    suite_add_tcase(s, strlen);
    suite_add_tcase(s, strpbrk);
    suite_add_tcase(s, strtok);
    suite_add_tcase(s, strerror);

    return s;
}

// Запуск всех тестов
int main(void)
{
    // Создаем Suite с тестами
    Suite *s = string_suite();

    // Создаем Test Runner — движок, который запустит тесты
    SRunner *sr = srunner_create(s);

    // Запускаем все тесты
    srunner_run_all(sr, CK_NORMAL);

    // Получаем количество упавших тестов
    int failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (failed == 0) ? 0 : 1;
}