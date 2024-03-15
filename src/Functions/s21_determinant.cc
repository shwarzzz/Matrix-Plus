#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  double res = 0;
  if (rows_ != cols_) {
    throw std::logic_error(
        "Error: The number of columns must be equal to the rows number!");
  } else {
    res = FindDet(*this);
  }
  return res;
}

double S21Matrix::FindDet(S21Matrix& other) {
  double d = 0;
  if (other.rows_ == 1) {
    d = other.matrix_[0][0];
  } else if (other.rows_ == 2) {
    d = other.matrix_[0][0] * other.matrix_[1][1] -
        other.matrix_[0][1] * other.matrix_[1][0];
  } else {
    S21Matrix tmp(other.rows_ - 1, other.cols_ - 1);
    for (int k = 0; k < other.rows_; k++) {
      for (int i = 1; i < other.rows_; i++) {
        int t = 0;
        for (int j = 0; j < other.rows_; j++) {
          if (j != k) {
            tmp.matrix_[i - 1][t] = other.matrix_[i][j];
            t++;
          }
        }
      }
      d += pow(-1, k) * other.matrix_[0][k] * FindDet(tmp);
    }
  }
  return d;
}