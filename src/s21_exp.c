#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0, tailor_mem = 1.0, n = 1.0;
  if (s21_isnan(x)) {
    result = S21_NAN;
  } else if (s21_isinf(x) && x < 0.0) {
    result = 0.0;
  } else if ((s21_isinf(x) && x > 0.0) || x >= 710.0) {
    result = S21_INF;
  } else {
    long double long_x = s21_fabs(x);
    while (tailor_mem > PRESISION) {
      tailor_mem *= (long_x / n);
      result += tailor_mem;
      n++;
    }
    if (x < 0.0) {
      result = 1.0 / result;
    }
  }
  return result;
}