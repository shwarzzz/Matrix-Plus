#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      res.matrix_[i][j] = this->matrix_[j][i];
    }
  }
  return res;
}