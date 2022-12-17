#include "s21_math.h"

long double s21_acos(double x) {
  long double result = S21_NAN;
  if (x >= -1 && x <= 1) {
    result = s21_atan(s21_sqrt(1 - x * x) / s21_fabs(x));
    if (x < 0) {
      result = S21_PI_VALUE - result;
    }
  } else {
    errno = EDOM;
  }
  return s21_fabs(result);
}
