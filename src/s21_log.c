#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0, temp = 1;
  int exp_pow = 0;

  if (x == 0) {
    result = -S21_INF;
  } else if (x == 1) {
    result = 0;
  } else if (x < 0) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == S21_NAN) {
    result = S21_NAN;
  } else {
    for (exp_pow = 0; x >= S21_EXP_VALUE; x /= S21_EXP_VALUE, exp_pow++)
      continue;

    for (int i = 0; i < 100; i++) {
      temp = result;
      result = temp + 2 * ((x - s21_exp(temp)) / (x + s21_exp(temp)));
    }
  }
  return result + exp_pow;
}