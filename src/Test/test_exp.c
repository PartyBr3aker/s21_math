#include "s21_math_test.h"

START_TEST(exp_real) {
  double x = RandomReal(-25, 25);
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), ACCURACY);
}
END_TEST

START_TEST(exp_0) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), ACCURACY);
}
END_TEST

START_TEST(exp_minus_inf) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), ACCURACY);
}
END_TEST

START_TEST(exp_inf) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(expl(INFINITY));
}
END_TEST

START_TEST(exp_nan) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(expl(NAN));
}
END_TEST

Suite *suite_s21_exp(void) {
  Suite *s = suite_create("exponenta");
  TCase *tc = tcase_create("exponenta_tc");

  tcase_add_loop_test(tc, exp_real, 0, NUM_OF_TESTS);
  tcase_add_test(tc, exp_0);
  tcase_add_test(tc, exp_minus_inf);
  tcase_add_test(tc, exp_inf);
  tcase_add_test(tc, exp_nan);

  suite_add_tcase(s, tc);
  return s;
}