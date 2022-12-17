#include "s21_math.h"

long double s21_floor(double x) {
  if (x * -1 < x) {
    x = (int)x;
  } else if (x != (int)x) {
    x = (int)x;
    x--;
  }
  return x;
}
