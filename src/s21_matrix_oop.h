#ifndef S21_MATRIX_OOP_HPP

#define S21_MATRIX_OOP_HPP

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_ = 0;
  int cols_ = 0;
  double** matrix_ = nullptr;

  double FindDet(S21Matrix& other);
  double MinorDet(int i, int j);

 public:
  // Конструкторы
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other) noexcept;
  S21Matrix(S21Matrix&& other) noexcept;

  // Деструктор
  ~S21Matrix();

  // Аксесор и мутатор
  int getRows();
  int getColumns();

  void setRows(int row);
  void setColumns(int column);

  // Операции над матрицами
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Перегрузка операторов
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);

  bool operator==(const S21Matrix& other) noexcept;

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);

  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);

  S21Matrix& operator*=(const double num) noexcept;
  S21Matrix& operator*=(const S21Matrix& other);

  S21Matrix operator*(const S21Matrix& other);

  friend S21Matrix operator*(const double& num,
                             const S21Matrix& other) noexcept;
  friend S21Matrix operator*(const S21Matrix& other,
                             const double& num) noexcept;

  double& operator()(int i, int j);
};

#endif