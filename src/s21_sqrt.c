#include "s21_math.h"

long double s21_sqrt(double x) {
  long double temp = x;
  long double result = 0;
  if (x >= 0) {
    while (s21_fabs(temp - result) > EPSILON) {
      result = temp;
      temp = (x / temp + temp) / 2;
    }
  } else {
    result = S21_NAN;
  }
  return result;
}
