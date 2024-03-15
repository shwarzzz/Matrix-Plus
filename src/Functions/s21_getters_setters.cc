#include "../s21_matrix_oop.h"

// Getters
int S21Matrix::getRows() { return rows_; }

int S21Matrix::getColumns() { return cols_; }
// Setters
void S21Matrix::setRows(int row) {
  S21Matrix newMatrix(row, cols_);
  for (int i = 0; i < row && i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      newMatrix.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = std::move(newMatrix);
}

void S21Matrix::setColumns(int column) {
  S21Matrix newMatrix(rows_, column);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < column && j < cols_; j++) {
      newMatrix.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = std::move(newMatrix);
}