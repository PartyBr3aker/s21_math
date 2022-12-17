#include "s21_math.h"

long double s21_ceil(double x) {
  // Handling errors
  if (s21_isnan(x) || s21_fabs(x) > s21_pow(2, 62) || s21_isinf(x)) {
    return x;
  }

  long double result = (long long int)x;
  if (s21_fabs(result) < EPSILON && x < 0.0) {
    result = -0.0;
  } else if (x > 0.0 && (s21_fabs(result - x) > EPSILON)) {
    result++;
  }
  return result;
}