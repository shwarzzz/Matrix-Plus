#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  bool res = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    res = false;
  } else {
    for (int i = 0; i < this->rows_ && res; i++) {
      for (int j = 0; j < this->cols_ && res; j++) {
        if (this->matrix_[i][j] - other.matrix_[i][j] > 0.0000001) {
          res = false;
        }
      }
    }
  }
  return res;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  return this->EqMatrix(other);
}