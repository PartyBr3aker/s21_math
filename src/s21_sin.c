#include "s21_math.h"

long double s21_sin(double x) {
  // handling errors
  if (s21_isnan(x) || s21_isinf(x)) {
    return S21_NAN;
  }

  x = s21_fmod(x, 2 * S21_PI_VALUE);
  long double result = 0.0, num_memb = 0.0, tailor_mem = (long double)x,
              factorial_memb = 1.0;
  while (s21_fabs(tailor_mem) > EPSILON) {
    result += tailor_mem;
    num_memb++;
    factorial_memb = 2 * num_memb * (2 * num_memb + 1);
    tailor_mem *= -x * x / factorial_memb;
  }
  return result;
}
