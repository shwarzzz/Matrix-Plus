#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix res(cols_, rows_);
  if (rows_ != cols_) {
    throw std::logic_error(
        "Error: The number of columns must be equal to the rows number!");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        res(i, j) = pow(-1, i + j) * MinorDet(i, j);
      }
    }
  }
  return res;
}

double S21Matrix::MinorDet(int i, int j) {
  double det = 0;
  if (cols_ == 1) {
    det = this->matrix_[0][0];
  } else {
    S21Matrix tmp(rows_ - 1, cols_ - 1);
    int q = 0;
    for (int x = 0; x < rows_; x++) {
      int t = 0;
      if (x == i) continue;
      for (int y = 0; y < cols_; y++) {
        if (y != j) {
          tmp.matrix_[q][t] = this->matrix_[x][y];
          t++;
        }
      }
      q++;
    }
    det = FindDet(tmp);
  }
  return det;
}