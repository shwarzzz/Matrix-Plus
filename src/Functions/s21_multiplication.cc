#include "../s21_matrix_oop.h"

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

S21Matrix& S21Matrix::operator*=(const double num) noexcept {
  this->MulNumber(num);
  return *this;
}

S21Matrix operator*(const double& num, const S21Matrix& other) noexcept {
  S21Matrix res = other;
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(const S21Matrix& other, const double& num) noexcept {
  S21Matrix res = num * other;
  return res;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_) {
    throw std::logic_error(
        "Error: The number of columns of the first matrix must be equal to the "
        "number of rows of the second matrix");
  } else {
    S21Matrix result(this->rows_, other.cols_);
    for (int k = 0; k < result.rows_; k++) {
      for (int i = 0; i < result.cols_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          result.matrix_[k][i] += this->matrix_[k][j] * other.matrix_[j][i];
        }
      }
    }
    *this = result;
  }
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}