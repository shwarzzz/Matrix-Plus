#include "../s21_matrix_oop.h"

double &S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
    throw std::out_of_range("Error: Index out of bounds");
  } else {
    return this->matrix_[i][j];
  }
}