#include "s21_math_test.h"

START_TEST(abs_test_zero) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(abs_loop_test_int) {
  int n = rand();
  if (rand() % 2) n = -n;
  ck_assert_int_eq(s21_abs(n), abs(n));
}
END_TEST

Suite *suite_s21_abs(void) {
  Suite *s = suite_create("modul_int");
  TCase *tc = tcase_create("modul_int_tc");

  tcase_add_test(tc, abs_test_zero);
  tcase_add_loop_test(tc, abs_loop_test_int, 0, NUM_OF_TESTS);

  suite_add_tcase(s, tc);
  return s;
}