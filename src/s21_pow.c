#include "s21_math.h"

long double s21_pow_fast(double base, int exp) {
  long double result = 1;
  if ((int)exp >= 0) {
    while (exp) {
      if ((int)exp % 2 == 0) {
        exp /= 2;
        base *= base;
      } else {
        exp--;
        result *= base;
      }
    }
  } else {
    result = 1 / s21_pow_fast(base, -exp);
  }
  return result;
}

long double s21_pow(double base, double exp) {
  int b_n = s21_isnan(base);
  int b_f = !s21_isinf(base);
  int e_n = s21_isnan(exp);
  int e_f = !s21_isinf(exp);
  int e_i = s21_fabs(exp - s21_floor(exp)) <= EPSILON;

  //  pow(+0, exp), where exp is a negative odd integer, returns +∞ and raises
  //  FE_DIVBYZERO
  if (b_f && !b_n && base > 0 && base <= EPSILON && (int)exp < 0 &&
      (int)exp % 2 != 0 && e_i) {
    return S21_INF;
  }

  //  pow(-0, exp), where exp is a negative odd integer, returns -∞ and raises
  //  FE_DIVBYZERO
  if (base < 0 && base >= -EPSILON && (int)exp < 0 && (int)exp % 2 != 0 &&
      e_i) {
    return -S21_INF;
  }

  //  pow(±0, exp), where exp is negative, finite, and is an even integer or a
  //  non-integer, returns +∞ and raises FE_DIVBYZERO
  if (s21_fabs(base) <= EPSILON && e_f &&
      ((e_i && (int)exp % 2 == 0) || !e_i)) {
    return S21_INF;
  }

  //  pow(±0, -∞) returns +∞ and may raise FE_DIVBYZERO
  if (s21_fabs(base) <= EPSILON && !e_f && !e_n && exp < 0) {
    return S21_INF;
  }

  //  pow(+0, exp), where exp is a positive odd integer, returns +0
  if (base > 0 && base <= EPSILON && e_i && (int)exp > 0 && (int)exp % 2 != 0) {
    return +0;
  }

  //  pow(-0, exp), where exp is a positive odd integer, returns -0
  if (base < 0 && base >= -EPSILON && e_i && (int)exp > 0 &&
      (int)exp % 2 != 0) {
    return -0;
  }

  //  pow(±0, exp), where exp is positive non-integer or a positive even
  //  integer, returns +0
  if (s21_fabs(base) <= EPSILON && exp > 0 &&
      (!e_i || ((int)exp % 2 == 0 && e_i))) {
    return +0;
  }

  //  pow(-1, ±∞) returns 1
  if (base == -1 && !e_f && !e_n) {
    return 1;
  }

  //  pow(+1, exp) returns 1 for any exp, even when exp is NaN
  if (base == 1) {
    return 1;
  }

  //  pow(base, ±0) returns 1 for any base, even when base is NaN
  if (s21_fabs(exp) <= EPSILON) {
    return 1;
  }

  //  pow(base, exp) returns NaN and raises FE_INVALID if base is finite and
  //  negative and exp is finite and non-integer
  if (b_f && base < 0 && e_f && !e_i) {
    return S21_NAN;
  }

  //  pow(base, -∞) returns +∞ for any |base|<1
  if (!e_f && !e_n && exp < 0 && s21_fabs(base) < 1) {
    return S21_INF;
  }

  //  pow(base, -∞) returns +0 for any |base|>1
  if (!e_f && !e_n && exp < 0 && s21_fabs(base) > 1) {
    return +0;
  }

  //  pow(base, +∞) returns +0 for any |base|<1
  if (!e_f && !e_n && exp > 0 && s21_fabs(base) < 1) {
    return +0;
  }

  //  pow(base, +∞) returns +∞ for any |base|>1
  if (!e_f && !e_n && exp > 0 && s21_fabs(base) > 1) {
    return S21_INF;
  }

  //  pow(-∞, exp) returns -0 if exp is a negative odd integer
  if (!b_f && !b_n && base < 0 && exp < 0 && (int)exp % 2 != 0 && e_i) {
    return -0;
  }

  //  pow(-∞, exp) returns +0 if exp is a negative non-integer or negative even
  //  integer
  // if (!b_f && !b_n && base < 0 && exp < 0 && (!e_i || (e_i && (int) exp % 2
  // == 0))) {
  if (!b_f && !b_n && base < 0 && exp < 0 && (!e_i || (int)exp % 2 == 0)) {
    return +0;
  }

  //  pow(-∞, exp) returns -∞ if exp is a positive odd integer
  if (!b_f && !b_n && base < 0 && exp > 0 && (int)exp % 2 != 0 && e_i) {
    return -S21_INF;
  }

  //  pow(-∞, exp) returns +∞ if exp is a positive non-integer or positive even
  //  integer
  if (!b_f && !b_n && base < 0 && exp > 0 && (!e_i || (int)exp % 2 == 0)) {
    return S21_INF;
  }

  //  pow(+∞, exponent) returns +0 for any negative exponent
  if (!b_f && !b_n && base > 0 && exp < 0) {
    return +0;
  }

  //  pow(+∞, exponent) returns +∞ for any positive exponent
  if (!b_f && !b_n && base > 0 && exp > 0) {
    return S21_INF;
  }

  //  except where specified above, if any argument is NaN, NaN is returne
  if (b_n || e_n) {
    return S21_NAN;
  }

  long double result;
  if (base >= 0) {
    result = s21_exp(exp * s21_log(base));
  } else {
    result = s21_pow_fast(base, exp);
  }
  return result;
}