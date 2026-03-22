#include "../s21_sprintf.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

/*
    SPEC D
*/
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


/*
    SPEC U
*/
START_TEST(test_u_positive_num)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 123;
    s21_sprintf(my_buff, "Some %utext", num);
    sprintf(orig_buff, "Some %utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_zero)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 0;
    s21_sprintf(my_buff, "Some %utext", num);
    sprintf(orig_buff, "Some %utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

// Специфично для u — большое значение, которое у d было бы отрицательным
START_TEST(test_u_large_num)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 4294967295U; // UINT_MAX
    s21_sprintf(my_buff, "Some %utext", num);
    sprintf(orig_buff, "Some %utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_width)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 42;
    s21_sprintf(my_buff, "Some %5utext", num);
    sprintf(orig_buff, "Some %5utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_precision)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 42;
    s21_sprintf(my_buff, "Some %.5utext", num);
    sprintf(orig_buff, "Some %.5utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_precision_zero)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 0;
    s21_sprintf(my_buff, "Some %.0utext", num);
    sprintf(orig_buff, "Some %.0utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_width_and_precision)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 8;
    s21_sprintf(my_buff, "Some %4.2utext", num);
    sprintf(orig_buff, "Some %4.2utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_minus_flag)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 42;
    s21_sprintf(my_buff, "Some %-5utext", num);
    sprintf(orig_buff, "Some %-5utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

// Проверяем что + и пробел игнорируются для u
START_TEST(test_u_plus_flag_ignored)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 42;
    s21_sprintf(my_buff, "Some %+utext", num);
    sprintf(orig_buff, "Some %+utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_space_flag_ignored)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 42;
    s21_sprintf(my_buff, "Some % utext", num);
    sprintf(orig_buff, "Some % utext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_h_length)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned short num = 123;
    s21_sprintf(my_buff, "Some %hutext", num);
    sprintf(orig_buff, "Some %hutext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_l_length)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned long num = 123456UL;
    s21_sprintf(my_buff, "Some %lutext", num);
    sprintf(orig_buff, "Some %lutext", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_u_combination)
{
    char my_buff[100];
    char orig_buff[100];
    unsigned int num = 42;
    s21_sprintf(my_buff, "Val: %-8.5u end", num);
    sprintf(orig_buff, "Val: %-8.5u end", num);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

/*
    SPEC C
*/
START_TEST(test_c_width)
{
    char my_buff[100];
    char orig_buff[100];
    char ch = 'w';

    s21_sprintf(my_buff, "Some %5c text", ch);
    sprintf(orig_buff, "Some %5c text", ch);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_c_minus_flag)
{
    char my_buff[100];
    char orig_buff[100];
    char ch = 'w';

    s21_sprintf(my_buff, "Some %-5c text", ch);
    sprintf(orig_buff, "Some %-5c text", ch);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

/*
    SPEC S
*/
START_TEST(test_s_width)
{
    char my_buff[100];
    char orig_buff[100];
    char *str = "other";

    s21_sprintf(my_buff, "Some %3s text", str);
    sprintf(orig_buff, "Some %3s text", str);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_s_width_more)
{
    char my_buff[100];
    char orig_buff[100];
    char *str = "other";

    s21_sprintf(my_buff, "Some %6s text", str);
    sprintf(orig_buff, "Some %6s text", str);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_s_precision)
{
    char my_buff[100];
    char orig_buff[100];
    char *str = "other";

    s21_sprintf(my_buff, "Some %.3s text", str);
    sprintf(orig_buff, "Some %.3s text", str);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_s_precision_and_width)
{
    char my_buff[100];
    char orig_buff[100];
    char *str = "other";

    s21_sprintf(my_buff, "Some %6.3s text", str);
    sprintf(orig_buff, "Some %6.3s text", str);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_s_minus_flag)
{
    char my_buff[100];
    char orig_buff[100];
    char *str = "other";

    s21_sprintf(my_buff, "Some %-5s text", str);
    sprintf(orig_buff, "Some %-5s text", str);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

START_TEST(test_s_default)
{
    char my_buff[100];
    char orig_buff[100];
    char *str = "other";

    s21_sprintf(my_buff, "Some %s text", str);
    sprintf(orig_buff, "Some %s text", str);
    ck_assert_str_eq(my_buff, orig_buff);
}
END_TEST

/*
    COMMON
*/
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

    TCase *spec_u = tcase_create("specifier_u");
    tcase_add_test(spec_u, test_u_positive_num);
    tcase_add_test(spec_u, test_u_zero);
    tcase_add_test(spec_u, test_u_large_num);
    tcase_add_test(spec_u, test_u_width);
    tcase_add_test(spec_u, test_u_precision);
    tcase_add_test(spec_u, test_u_precision_zero);
    tcase_add_test(spec_u, test_u_width_and_precision);
    tcase_add_test(spec_u, test_u_minus_flag);
    tcase_add_test(spec_u, test_u_plus_flag_ignored);
    tcase_add_test(spec_u, test_u_space_flag_ignored);
    tcase_add_test(spec_u, test_u_h_length);
    tcase_add_test(spec_u, test_u_l_length);
    tcase_add_test(spec_u, test_u_combination);

    TCase *spec_c = tcase_create("specifier_c");
    tcase_add_test(spec_c, test_c_width);
    tcase_add_test(spec_c, test_c_minus_flag);

    TCase *spec_s = tcase_create("specifier_s");
    tcase_add_test(spec_s, test_s_default);
    tcase_add_test(spec_s, test_s_width);
    tcase_add_test(spec_s, test_s_width_more);
    tcase_add_test(spec_s, test_s_minus_flag);
    tcase_add_test(spec_s, test_s_precision);
    tcase_add_test(spec_s, test_s_precision_and_width);

    TCase *common = tcase_create("common");
    tcase_add_test(common, test_skipping_sequence);

    // Добавляем Test Case в Suite
    suite_add_tcase(s, spec_d);
    suite_add_tcase(s, spec_u);
    suite_add_tcase(s, spec_c);
    suite_add_tcase(s, spec_s);
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