#include "s21_math.h"

long double s21_cos(double x) {
  // handling errors
  if (s21_isnan(x) || s21_isinf(x)) {
    return S21_NAN;
  }

  x = s21_fmod(x, 2 * S21_PI_VALUE);
  long double result = 0.0, num_memb = 0.0, taylor_mem = 1.0,
              factorial_memb = 1.0;
  while (s21_fabs(taylor_mem) > EPSILON) {
    result += taylor_mem;
    num_memb++;
    factorial_memb = 2 * num_memb * (2 * num_memb - 1);
    taylor_mem *= -x * x / factorial_memb;
  }
  return result;
}
