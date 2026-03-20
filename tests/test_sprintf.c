#include "../s21_sprintf.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_d_positive_num)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 123;

    s21_sprintf(my_buff, "Some %dtext", num);
    sprintf(orig_buff, "Some %dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_negative_num)
{
    char my_buff[100];
    char orig_buff[100];
    int num = -123;

    s21_sprintf(my_buff, "Some %dtext", num);
    sprintf(orig_buff, "Some %dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_width)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Some %5dtext", num);
    sprintf(orig_buff, "Some %5dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_width_negative_num)
{
    char my_buff[100];
    char orig_buff[100];
    int num = -42;

    s21_sprintf(my_buff, "Some %5dtext", num);
    sprintf(orig_buff, "Some %5dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_precision)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Some %.5dtext", num);
    sprintf(orig_buff, "Some %.5dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_precision_zero)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 0;

    s21_sprintf(my_buff, "Some %.0dtext", num);
    sprintf(orig_buff, "Some %.0dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_width_and_precision)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 8;

    s21_sprintf(my_buff, "Some %4.2dtext", num);
    sprintf(orig_buff, "Some %4.2dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_minus_flag)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Some %-5dtext", num);
    sprintf(orig_buff, "Some %-5dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_plus_flag)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Some %+dtext", num);
    sprintf(orig_buff, "Some %+dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_plus_flag_negative)
{
    char my_buff[100];
    char orig_buff[100];
    int num = -42;

    s21_sprintf(my_buff, "Some %+dtext", num);
    sprintf(orig_buff, "Some %+dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_space_flag)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Some % dtext", num);
    sprintf(orig_buff, "Some % dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_space_flag_plus)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Some %+ dtext", num);
    sprintf(orig_buff, "Some %+ dtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_h_length)
{
    char my_buff[100];
    char orig_buff[100];
    short num = 123;

    s21_sprintf(my_buff, "Some %hdtext", num);
    sprintf(orig_buff, "Some %hdtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_l_length)
{
    char my_buff[100];
    char orig_buff[100];
    long num = 123456L;

    s21_sprintf(my_buff, "Some %ldtext", num);
    sprintf(orig_buff, "Some %ldtext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_combination)
{
    char my_buff[100];
    char orig_buff[100];
    int num = 42;

    s21_sprintf(my_buff, "Val: %+8.5d end", num);
    sprintf(orig_buff, "Val: %+8.5d end", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_d_combination_negative)
{
    char my_buff[100];
    char orig_buff[100];
    int num = -42;

    s21_sprintf(my_buff, "Val:%+8.5d end", num);
    sprintf(orig_buff, "Val:%+8.5d end", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_skipping_sequence)
{
    char my_buff[100];
    char orig_buff[100];
    int num = -42;

    s21_sprintf(my_buff, "Val: %%", num);
    sprintf(orig_buff, "Val: %%", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

// SUITE (набор тестов)
Suite *sprintf_suite(void) {
    // Общая группа тестов
    Suite *s = suite_create("sprintf");

    // Подгруппа внутри Suite
    TCase *spec_d = tcase_create("specifier_d");
    tcase_add_test(spec_d, test_d_positive_num);
    tcase_add_test(spec_d, test_d_negative_num);
    tcase_add_test(spec_d, test_d_width);
    tcase_add_test(spec_d, test_d_width_negative_num);
    tcase_add_test(spec_d, test_d_precision);
    tcase_add_test(spec_d, test_d_precision_zero);
    tcase_add_test(spec_d, test_d_width_and_precision);
    tcase_add_test(spec_d, test_d_minus_flag);
    tcase_add_test(spec_d, test_d_plus_flag);
    tcase_add_test(spec_d, test_d_plus_flag_negative);
    tcase_add_test(spec_d, test_d_space_flag);
    tcase_add_test(spec_d, test_d_space_flag_plus);
    tcase_add_test(spec_d, test_d_h_length);
    tcase_add_test(spec_d, test_d_l_length);
    tcase_add_test(spec_d, test_d_combination);
    tcase_add_test(spec_d, test_d_combination_negative);

    TCase *common = tcase_create("common");
    tcase_add_test(common, test_skipping_sequence);
    
    // Добавляем Test Case в Suite
    suite_add_tcase(s, spec_d);
    suite_add_tcase(s, common);
    return s;
}

// Запуск всех тестов
int main(void)
{
    // Создаем Suite с тестами
    Suite *s = sprintf_suite();

    // Создаем Test Runner — движок, который запустит тесты
    SRunner *sr = srunner_create(s);

    // Запускаем все тесты
    srunner_run_all(sr, CK_NORMAL);

    // Получаем количество упавших тестов
    int failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (failed == 0) ? 0 : 1;
}