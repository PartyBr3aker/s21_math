#include "s21_math.h"

long double s21_atan(double x) {
  long double sign = 1.0;

  if (x < 0) {
    sign = -1.0;
    x = s21_fabs(x);
  }

  long double result = x;
  if (x == S21_INF) {
    result = S21_HALF_PI_VALUE;

  } else if (x == -S21_INF) {
    result = -S21_HALF_PI_VALUE;

  } else if (s21_fabs(x - 1.0) < 10e-6) {
    // the derivative of atan(x) = 1 / (1 + х^2)
    // atan(1) = pi/4
    // dy/dx = 1/2 ==> dy = dx/2 ==> dy = (x - 1) / 2
    result = S21_HALF_PI_VALUE / 2.0 + (x - 1) / 2;

  } else if (s21_fabs(x) > 1.0) {
    result = S21_HALF_PI_VALUE - s21_atan(1 / x);

  } else {
    long double term = x, tailor_member = 1.0;
    for (int num = 2; s21_fabs(tailor_member) > PRESISION; num++) {
      term *= (-1) * x * x;
      tailor_member = term / (2 * num - 1.0);
      result += tailor_member;
    }
  }
  return result * sign;
}
