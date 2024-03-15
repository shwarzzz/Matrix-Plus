#include "../s21_matrix_oop.h"

// Констркутор без парметров
S21Matrix::S21Matrix() noexcept {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

// Деструктор
S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
    matrix_[i] = nullptr;
  }
  delete[] matrix_;
  matrix_ = nullptr;
  cols_ = 0;
  rows_ = 0;
}
// Констркутор с параметрами
S21Matrix::S21Matrix(int row, int col) : rows_(row), cols_(col) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::length_error(
        "Error: The number of rows and columns must be greater than zero!");
  }
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}
// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix &other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
    std::memcpy(this->matrix_[i], other.matrix_[i], cols_ * sizeof(double));
  }
}
// Конструктор перемещения
S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}
// Оператор перемещения
S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}
// Оператор копирования
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    matrix_ = new double *[this->rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]();
      std::memcpy(this->matrix_[i], other.matrix_[i],
                  this->cols_ * sizeof(double));
    }
  }
  return *this;
}