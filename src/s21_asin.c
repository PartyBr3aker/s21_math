#include "s21_math.h"

long double s21_asin(double x) {
  long double result = S21_NAN;
  long double sign = 1.0;
  if (x >= -1.0 && x <= 1.0) {
    if (x < 0) {
      sign *= -1.0;
      x = s21_fabs(x);
    }
    result = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    errno = EDOM;
  }
  return result * sign;
}
