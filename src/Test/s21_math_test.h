#ifndef S21_MATH_TEST
#define S21_MATH_TEST

#include <check.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../s21_math.h"

#define ACCURACY 1e-6
#define NUM_OF_TESTS 100
#define s21_bool int
s21_bool s21_ldeq(long double a, long double b);

Suite *suite_s21_abs(void);
Suite *suite_s21_acos(void);
Suite *suite_s21_asin(void);
Suite *suite_s21_atan(void);
Suite *suite_s21_ceil(void);
Suite *suite_s21_cos(void);
Suite *suite_s21_exp(void);
Suite *suite_s21_fabs(void);
Suite *suite_s21_floor(void);
Suite *suite_s21_fmod(void);
Suite *suite_s21_log(void);
Suite *suite_s21_pow(void);
Suite *suite_s21_sin(void);
Suite *suite_s21_sqrt(void);
Suite *suite_s21_tan(void);

void run_tests(void);
void run_testcase(Suite *testcase);

double RandomReal(double low, double high);
double fRand(double fMin, double fMax);

#endif  //  S21_MATH_TEST