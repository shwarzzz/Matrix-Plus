#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (fabs(det) < 0.0000001) {
    throw std::logic_error(
        "Error: The determinant of the matrix is ​​zero!");
  }
  det = 1.0 / det;
  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result(0, 0) = det;
  } else {
    result = (this->CalcComplements().Transpose()) * det;
  }
  return result;
}