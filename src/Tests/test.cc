#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// Дефолтный констркутор
TEST(TestDefaultConstructor, TestDefault) {
  S21Matrix a;
  ASSERT_EQ(a.getRows(), 3);
  ASSERT_EQ(a.getColumns(), 3);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), 0.0);
    }
  }
}
// Конструктор с парметрами
TEST(TestParametrConstructor, TestParametr_1) {
  S21Matrix a(1, 1);
  ASSERT_EQ(a.getRows(), 1);
  ASSERT_EQ(a.getColumns(), 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), 0.0);
    }
  }
}

TEST(TestParametrConstructor, TestParametr_2) {
  S21Matrix a(1, 2);
  ASSERT_EQ(a.getRows(), 1);
  ASSERT_EQ(a.getColumns(), 2);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), 0.0);
    }
  }
}

TEST(TestParametrConstructor, TestParametr_3) {
  S21Matrix a(5, 3);
  ASSERT_EQ(a.getRows(), 5);
  ASSERT_EQ(a.getColumns(), 3);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), 0.0);
    }
  }
}

TEST(TestParametrConstructor, TestParametr_4) {
  S21Matrix a(6, 6);
  ASSERT_EQ(a.getRows(), 6);
  ASSERT_EQ(a.getColumns(), 6);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), 0.0);
    }
  }
}

TEST(TestParametrConstructor, TestParametr_5) {
  ASSERT_THROW(S21Matrix a(1, 0), std::length_error);
}

TEST(TestParametrConstructor, TestParametr_6) {
  ASSERT_THROW(S21Matrix a(0, 2), std::length_error);
}

TEST(TestParametrConstructor, TestParametr_7) {
  ASSERT_THROW(S21Matrix a(-2, -3), std::length_error);
}
// Констркутор копирования
TEST(TestCopyConstructor, TestCopy_1) {
  S21Matrix a;
  S21Matrix b(a);
  ASSERT_EQ(b.getRows(), 3);
  ASSERT_EQ(b.getColumns(), 3);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), 0.0);
    }
  }
}

TEST(TestCopyConstructor, TestCopy_2) {
  S21Matrix a(10, 12);
  S21Matrix b(a);
  ASSERT_EQ(b.getRows(), 10);
  ASSERT_EQ(b.getColumns(), 12);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), 0.0);
    }
  }
}
// Констркутор перемещения
TEST(TestMoveConstructor, TestMove_1) {
  S21Matrix a(10, 10);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j;
    }
  }
  S21Matrix b = std::move(a);
  ASSERT_EQ(b.getRows(), 10);
  ASSERT_EQ(b.getColumns(), 10);
  ASSERT_EQ(a.getRows(), 0);
  ASSERT_EQ(a.getColumns(), 0);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), i + j);
    }
  }
}

TEST(TestMoveConstructor, TestMove_2) {
  S21Matrix a(3, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j;
    }
  }
  S21Matrix b = std::move(a);
  ASSERT_EQ(b.getRows(), 3);
  ASSERT_EQ(b.getColumns(), 1);
  ASSERT_EQ(a.getRows(), 0);
  ASSERT_EQ(a.getColumns(), 0);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), i + j);
    }
  }
}
// Оператор перемещения
TEST(TestMoveOperator, TestMOperator_1) {
  S21Matrix a(10, 10);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j;
    }
  }
  S21Matrix b(1, 1);
  b = std::move(a);
  ASSERT_EQ(b.getRows(), 10);
  ASSERT_EQ(b.getColumns(), 10);
  ASSERT_EQ(a.getRows(), 0);
  ASSERT_EQ(a.getColumns(), 0);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), i + j);
    }
  }
}

TEST(TestMoveOperator, TestMOperator_2) {
  S21Matrix a(3, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j;
    }
  }
  S21Matrix b;
  b = std::move(a);
  ASSERT_EQ(b.getRows(), 3);
  ASSERT_EQ(b.getColumns(), 1);
  ASSERT_EQ(a.getRows(), 0);
  ASSERT_EQ(a.getColumns(), 0);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), i + j);
    }
  }
}
// Оператор копирования
TEST(TestCopyOperator, TestCOperator_1) {
  S21Matrix a;
  S21Matrix b(100, 2);
  b = a;
  ASSERT_EQ(b.getRows(), 3);
  ASSERT_EQ(b.getColumns(), 3);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), 0.0);
      ASSERT_DOUBLE_EQ(a(i, j), b(i, j));
    }
  }
}

TEST(TestCopyOperator, TestCOperator_2) {
  S21Matrix a(10, 12);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j;
    }
  }
  S21Matrix b;
  b = a;
  ASSERT_EQ(b.getRows(), 10);
  ASSERT_EQ(b.getColumns(), 12);
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(b(i, j), i + j);
      ASSERT_DOUBLE_EQ(b(i, j), a(i, j));
    }
  }
}
// Getters
TEST(TestGetters, TestRows_1) {
  S21Matrix a;
  ASSERT_EQ(a.getRows(), 3);
}

TEST(TestGetters, TestRows_2) {
  S21Matrix a(15, 2);
  ASSERT_EQ(a.getRows(), 15);
}

TEST(TestGetters, TestColumns_1) {
  S21Matrix a;
  ASSERT_EQ(a.getColumns(), 3);
}

TEST(TestGetters, TestColumns_2) {
  S21Matrix a(15, 2);
  ASSERT_EQ(a.getColumns(), 2);
}

// Setters
TEST(TestSetters, TestRows_1) {
  S21Matrix a;
  ASSERT_EQ(a.getRows(), 3);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j + 2.5;
    }
  }
  a.setRows(1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), i + j + 2.5);
    }
  }
  ASSERT_EQ(a.getRows(), 1);
}

TEST(TestSetters, TestRows_2) {
  S21Matrix a(5, 5);
  ASSERT_EQ(a.getRows(), 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j + 1.33;
    }
  }
  a.setRows(10);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      if (i < 5) {
        ASSERT_DOUBLE_EQ(a(i, j), i + j + 1.33);
      } else {
        ASSERT_DOUBLE_EQ(a(i, j), 0.0);
      }
    }
  }
  ASSERT_EQ(a.getRows(), 10);
}

TEST(TestSetters, TestRows_3) {
  S21Matrix a(5, 5);
  ASSERT_THROW(a.setRows(0), std::length_error);
}

TEST(TestSetters, TestRows_4) {
  S21Matrix a;
  ASSERT_THROW(a.setRows(-1), std::length_error);
}

TEST(TestSetters, TestColumns_1) {
  S21Matrix a;
  ASSERT_EQ(a.getColumns(), 3);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j + 1.1;
    }
  }
  a.setColumns(1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), i + j + 1.1);
    }
  }
  ASSERT_EQ(a.getColumns(), 1);
}

TEST(TestSetters, TestColumns_2) {
  S21Matrix a(5, 5);
  ASSERT_EQ(a.getColumns(), 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j + 12;
    }
  }
  a.setColumns(10);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      if (j < 5) {
        ASSERT_DOUBLE_EQ(a(i, j), i + j + 12);
      } else {
        ASSERT_DOUBLE_EQ(a(i, j), 0.0);
      }
    }
  }
  ASSERT_EQ(a.getColumns(), 10);
}

TEST(TestSetters, TestColumns_3) {
  S21Matrix a(5, 5);
  ASSERT_THROW(a.setColumns(0), std::length_error);
}

TEST(TestSetters, TestColumns_4) {
  S21Matrix a;
  ASSERT_THROW(a.setColumns(-1), std::length_error);
}

// Индексация
TEST(TestBrackets, Test_1) {
  S21Matrix a;
  a(0, 0) = 5.23;
  ASSERT_DOUBLE_EQ(a(0, 0), 5.23);
  ASSERT_DOUBLE_EQ(a(2, 2), 0.0);
}

TEST(TestBrackets, Test_2) {
  S21Matrix a(1, 1);
  ASSERT_THROW(a(1, 1), std::out_of_range);
}

TEST(TestBrackets, Test_3) {
  S21Matrix a(2, 5);
  ASSERT_THROW(a(1, -1), std::out_of_range);
}

TEST(TestBrackets, Test_4) {
  S21Matrix a;
  ASSERT_THROW(a(-2, 1), std::out_of_range);
}

TEST(TestBrackets, Test_5) {
  S21Matrix a(1, 1);
  ASSERT_THROW(a(2, 0), std::out_of_range);
}

TEST(TestBrackets, Test_6) {
  S21Matrix a(1, 1);
  ASSERT_THROW(a(0, 2), std::out_of_range);
}

// Сравнение матриц
TEST(TestEqual, Test_1) {
  S21Matrix a(3, 3);
  S21Matrix b;
  ASSERT_EQ(a.EqMatrix(b), true);
}

TEST(TestEqual, Test_2) {
  S21Matrix a(1, 3);
  S21Matrix b;
  ASSERT_EQ(a.EqMatrix(b), false);
}

TEST(TestEqual, Test_3) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 5);
  ASSERT_EQ(a.EqMatrix(b), false);
}

TEST(TestEqual, Test_4) {
  S21Matrix a(3, 3);
  S21Matrix b;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a(i, j) = -1234.892345567;
      b(i, j) = -1234.892345581;
    }
  }
  ASSERT_EQ(a.EqMatrix(b), true);
}

TEST(TestEqual, Test_5) {
  S21Matrix a(1, 6);
  S21Matrix b(6, 1);
  ASSERT_EQ(a.EqMatrix(b), false);
}

TEST(TestEqual, Test_6) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);

  a(0, 0) = 0;
  a(0, 1) = -135552135556.12345678;
  a(1, 0) = -23523414445556;
  a(1, 1) = -1;

  b(0, 0) = 0;
  b(0, 1) = -135552135556.12345678;
  b(1, 0) = -23523414445556;
  b(1, 1) = -1;

  ASSERT_EQ(a.EqMatrix(b), true);
}

TEST(TestEqual, Test_7) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);

  a(0, 0) = 0;
  a(0, 1) = -135552135556.12345678;
  a(1, 0) = -23523414445556;
  a(1, 1) = 1;

  b(0, 0) = 0;
  b(0, 1) = -135552135556.12345678;
  b(1, 0) = -23523414445556;
  b(1, 1) = -1;

  ASSERT_EQ(a.EqMatrix(b), false);
}
// Оператор сравнения
TEST(TestEqualOperator, Test_1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);

  a(0, 0) = 0;
  a(0, 1) = -135552135556.12345678;
  a(1, 0) = -23523414445556;
  a(1, 1) = -1;

  b(0, 0) = 0;
  b(0, 1) = -135552135556.12345678;
  b(1, 0) = -23523414445556;
  b(1, 1) = -1;

  ASSERT_EQ(a == b, true);
}

TEST(TestEqualOperator, Test_2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);

  a(0, 0) = 0;
  a(0, 1) = -135552135556.12345678;
  a(1, 0) = -23523414445556;
  a(1, 1) = 1;

  b(0, 0) = 0;
  b(0, 1) = -135552135556.12345678;
  b(1, 0) = -23523414445556;
  b(1, 1) = -1;

  ASSERT_EQ(a == b, false);
}

TEST(TestEqualOperator, Test_3) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);

  ASSERT_EQ(a == b, true);
}

TEST(TestEqualOperator, Test_4) {
  S21Matrix a(1, 2);
  S21Matrix b(2, 1);

  ASSERT_EQ(a == b, false);
}

TEST(TestEqualOperator, Test_5) {
  S21Matrix a(2, 1);
  S21Matrix b(1, 2);

  ASSERT_EQ(a == b, false);
}
// Сложение матриц
TEST(TestSumMatrix, TestSum_1) {
  S21Matrix a(15, 12);
  S21Matrix b(12, 15);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 4;
      b(j, i) = i + j * 4;
    }
  }
  ASSERT_THROW(a.SumMatrix(b), std::logic_error);
}

TEST(TestSumMatrix, TestSum_2) {
  S21Matrix a(5, 12);
  S21Matrix b(5, 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 4;
    }
  }
  ASSERT_THROW(a.SumMatrix(b), std::logic_error);
}

TEST(TestSumMatrix, TestSum_3) {
  S21Matrix a(5, 5);
  S21Matrix b(2, 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 4;
    }
  }
  ASSERT_THROW(a.SumMatrix(b), std::logic_error);
}

TEST(TestSumMatrix, TestSum_4) {
  S21Matrix a(2, 5);
  S21Matrix b(2, 5);
  S21Matrix check(2, 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -4;
      b(i, j) = (i + j) * 12.3;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  b.SumMatrix(a);
  ASSERT_EQ(b.EqMatrix(check), true);
}

TEST(TestSumMatrix, TestSum_5) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  b.SumMatrix(a);
  ASSERT_EQ(b.EqMatrix(check), true);
}

TEST(TestSumMatrix, TestSum_6) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  S21Matrix check(1, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = 2352135 * 133.12;
      b(i, j) = 55123 * 5.9862352134;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  b.SumMatrix(a);
  ASSERT_EQ(b.EqMatrix(check), true);
}

TEST(TestSumMatrix, TestSum_7) {
  S21Matrix a(5, 1);
  S21Matrix b(5, 1);
  S21Matrix check(5, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 133.12;
      b(i, j) = (i + j) * 5.98;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  b.SumMatrix(a);
  ASSERT_EQ(b.EqMatrix(check), true);
}
// Оператор '+'
TEST(TestPlusOperator, Test_1) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  ASSERT_EQ(check == a + b, true);
}

TEST(TestPlusOperator, Test_2) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  ASSERT_EQ(check == a + b, true);
}

TEST(TestPlusOperator, Test_3) {
  S21Matrix a(20, 12);
  S21Matrix b(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(j, i) = (i + j) * -0.98;
    }
  }
  ASSERT_THROW(a + b, std::logic_error);
}
// Оператор '+='
TEST(TestPlusEq, Test_1) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  a += b;
  ASSERT_EQ(a.EqMatrix(check), true);
}

TEST(TestPlusEq, Test_2) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) + b(i, j);
    }
  }
  b += a;
  ASSERT_EQ(check == b, true);
}

TEST(TestPlusEq, Test_3) {
  S21Matrix a(20, 12);
  S21Matrix b(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(j, i) = (i + j) * -0.98;
    }
  }
  ASSERT_THROW(a += b, std::logic_error);
}
// Вычитание матриц
TEST(TestSubMatrix, TestSub_1) {
  S21Matrix a(15, 12);
  S21Matrix b(12, 15);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 4;
      b(j, i) = i + j * 4;
    }
  }
  ASSERT_THROW(a.SubMatrix(b), std::logic_error);
}

TEST(TestSubMatrix, TestSub_2) {
  S21Matrix a(5, 12);
  S21Matrix b(5, 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 4;
    }
  }
  ASSERT_THROW(a.SubMatrix(b), std::logic_error);
}

TEST(TestSubMatrix, TestSub_3) {
  S21Matrix a(5, 5);
  S21Matrix b(2, 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 4;
    }
  }
  ASSERT_THROW(a.SubMatrix(b), std::logic_error);
}

TEST(TestSubMatrix, TestSub_4) {
  S21Matrix a(2, 5);
  S21Matrix b(2, 5);
  S21Matrix check(2, 5);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -4;
      b(i, j) = (i + j) * 12.3;
      check(i, j) = b(i, j) - a(i, j);
    }
  }
  b.SubMatrix(a);
  ASSERT_EQ(b.EqMatrix(check), true);
}

TEST(TestSubMatrix, TestSub_5) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) - b(i, j);
    }
  }
  a.SubMatrix(b);
  ASSERT_EQ(a.EqMatrix(check), true);
}

TEST(TestSubMatrix, TestSub_6) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  S21Matrix check(1, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = 2352135 * -133.12;
      b(i, j) = 55123 * 5.9862352134;
      check(i, j) = a(i, j) - b(i, j);
    }
  }
  a.SubMatrix(b);
  ASSERT_EQ(a.EqMatrix(check), true);
}

TEST(TestSubMatrix, TestSub_7) {
  S21Matrix a(5, 1);
  S21Matrix b(5, 1);
  S21Matrix check(5, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * 133.12;
      b(i, j) = (i + j) * 5.98;
      check(i, j) = a(i, j) - b(i, j);
    }
  }
  a.SubMatrix(b);
  ASSERT_EQ(a.EqMatrix(check), true);
}
// Оператор '-'
TEST(TestSubOperator, Test_1) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) - b(i, j);
    }
  }
  ASSERT_EQ(check == a - b, true);
}

TEST(TestSubOperator, Test_2) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) - b(i, j);
    }
  }
  ASSERT_EQ(check == a - b, true);
}

TEST(TestSubOperator, Test_3) {
  S21Matrix a(20, 12);
  S21Matrix b(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(j, i) = (i + j) * -0.98;
    }
  }
  ASSERT_THROW(a - b, std::logic_error);
}
// Оператор '-='
TEST(TestSubEq, Test_1) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = a(i, j) - b(i, j);
    }
  }
  a -= b;
  ASSERT_EQ(a.EqMatrix(check), true);
}

TEST(TestSubEq, Test_2) {
  S21Matrix a(12, 20);
  S21Matrix b(12, 20);
  S21Matrix check(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(i, j) = (i + j) * -0.98;
      check(i, j) = b(i, j) - a(i, j);
    }
  }
  b -= a;
  ASSERT_EQ(check == b, true);
}

TEST(TestSubEq, Test_3) {
  S21Matrix a(20, 12);
  S21Matrix b(12, 20);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j * -35.1234;
      b(j, i) = (i + j) * -0.98;
    }
  }
  ASSERT_THROW(a -= b, std::logic_error);
}
// Умножение матрицы на число
TEST(TestMulNumb, Test_1) {
  S21Matrix a(1, 1);
  S21Matrix c(1, 1);
  double d = -1235.234;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = i + j + 123521;
      c(i, j) = a(i, j) * d;
    }
  }
  a.MulNumber(d);
  ASSERT_EQ(a == c, true);
}

TEST(TestMulNumb, Test_2) {
  S21Matrix a(5, 11);
  S21Matrix c(5, 11);
  double d = 0.12323;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1521.552;
      c(i, j) = a(i, j) * d;
    }
  }
  a.MulNumber(d);
  ASSERT_EQ(a == c, true);
}

TEST(TestMulNumb, Test_3) {
  S21Matrix a(12, 12);
  S21Matrix c(12, 12);
  double d = 5.0;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * 51.5;
      c(i, j) = a(i, j) * d;
    }
  }
  a.MulNumber(d);
  ASSERT_EQ(a == c, true);
}

TEST(TestMulNumb, Test_4) {
  S21Matrix a(9, 4);
  S21Matrix c(9, 4);
  double d = 225;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -11.3333333;
      c(i, j) = a(i, j) * d;
    }
  }
  a.MulNumber(d);
  ASSERT_EQ(a == c, true);
}

TEST(TestMulNumb, Test_5) {
  S21Matrix a(3, 1);
  S21Matrix c(3, 1);
  double d = 9972.213512;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1;
      c(i, j) = a(i, j) * d;
    }
  }
  a.MulNumber(d);
  ASSERT_EQ(a == c, true);
}
// Оператор '*='
TEST(TestMulEqOperator, Test_1) {
  S21Matrix a(5, 11);
  S21Matrix c(5, 11);
  double d = 0.12323;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1521.552;
      c(i, j) = a(i, j) * d;
    }
  }
  a *= d;
  ASSERT_EQ(a == c, true);
}

TEST(TestMulEqOperator, Test_2) {
  S21Matrix a(3, 1);
  S21Matrix c(3, 1);
  double d = 9972.213512;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1;
      c(i, j) = a(i, j) * d;
    }
  }
  a *= d;
  ASSERT_EQ(a == c, true);
}
// Оператор '*'
TEST(TestMulOperator, TestNumbMatrix_1) {
  S21Matrix a(5, 11);
  S21Matrix c(5, 11);
  double d = 0.12323;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1521.552;
      c(i, j) = a(i, j) * d;
    }
  }
  ASSERT_EQ(c.EqMatrix(d * a), true);
}

TEST(TestMulOperator, TestNumbMatrix_2) {
  S21Matrix a(5, 11);
  S21Matrix c(5, 11);
  double d = 0.12323;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1521.552;
      c(i, j) = a(i, j) * d;
    }
  }
  ASSERT_EQ(d * a == c, true);
}

TEST(TestMulOperator, TestMatrixNumb_1) {
  S21Matrix a(5, 11);
  S21Matrix c(5, 11);
  double d = 0.12323;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1521.552;
      c(i, j) = a(i, j) * d;
    }
  }
  ASSERT_EQ(c.EqMatrix(a * d), true);
}

TEST(TestMulOperator, TestMatrixNumb_2) {
  S21Matrix a(5, 11);
  S21Matrix c(5, 11);
  double d = 0.12323;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * -1521.552;
      c(i, j) = a(i, j) * d;
    }
  }
  ASSERT_EQ(a * d == c, true);
}
// Умножение матрицы на другую матрицу
TEST(TestMulMatrix, Test_1) {
  S21Matrix a(5, 1);
  S21Matrix b(5, 2);
  ASSERT_THROW(a.MulMatrix(b), std::logic_error);
}

TEST(TestMulMatrix, Test_2) {
  S21Matrix a(5, 5);
  S21Matrix b(1, 5);
  ASSERT_THROW(a.MulMatrix(b), std::logic_error);
}

TEST(TestMulMatrix, Test_3) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  S21Matrix c(1, 1);
  a(0, 0) = 234.23;
  b(0, 0) = -1;
  c(0, 0) = -234.23;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulMatrix, Test_4) {
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  S21Matrix c(4, 4);
  double num = 1;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      b(i, j) = num;
      num++;
    }
  }
  c(0, 0) = 90.0;
  c(0, 1) = 100.0;
  c(0, 2) = 110.0;
  c(0, 3) = 120.0;
  c(1, 0) = 202.0;
  c(1, 1) = 228.0;
  c(1, 2) = 254.0;
  c(1, 3) = 280.0;
  c(2, 0) = 314.0;
  c(2, 1) = 356.0;
  c(2, 2) = 398.0;
  c(2, 3) = 440.0;
  c(3, 0) = 426.0;
  c(3, 1) = 484.0;
  c(3, 2) = 542.0;
  c(3, 3) = 600.0;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulMatrix, Test_5) {
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  S21Matrix c(4, 4);
  double num_f = 1;
  double num_s = -5;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num_f;
      b(i, j) = num_s;
      num_f++;
      num_s++;
    }
  }
  c(0, 0) = 30.0;
  c(0, 1) = 40.0;
  c(0, 2) = 50.0;
  c(0, 3) = 60.0;
  c(1, 0) = 46.0;
  c(1, 1) = 72.0;
  c(1, 2) = 98.0;
  c(1, 3) = 124.0;
  c(2, 0) = 62.0;
  c(2, 1) = 104.0;
  c(2, 2) = 146.0;
  c(2, 3) = 188.0;
  c(3, 0) = 78.0;
  c(3, 1) = 136.0;
  c(3, 2) = 194.0;
  c(3, 3) = 252.0;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulMatrix, Test_6) {
  S21Matrix a(4, 2);
  S21Matrix b(2, 4);
  S21Matrix c(4, 4);
  double num = -5;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  num = 1;
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      b(i, j) = num;
      num++;
    }
  }
  c(0, 0) = -25.0;
  c(0, 1) = -34.0;
  c(0, 2) = -43.0;
  c(0, 3) = -52.0;
  c(1, 0) = -13.0;
  c(1, 1) = -18.0;
  c(1, 2) = -23.0;
  c(1, 3) = -28.0;
  c(2, 0) = -1.0;
  c(2, 1) = -2.0;
  c(2, 2) = -3.0;
  c(2, 3) = -4.0;
  c(3, 0) = 11.0;
  c(3, 1) = 14.0;
  c(3, 2) = 17.0;
  c(3, 3) = 20.0;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulMatrix, Test_7) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 1);
  S21Matrix c(3, 1);
  double num = 1;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  num = 5;
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      b(i, j) = num;
      num += 5;
    }
  }
  c(0, 0) = 25.0;
  c(1, 0) = 55.0;
  c(2, 0) = 85.0;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulMatrix, Test_8) {
  S21Matrix a(2, 3);
  S21Matrix b(3, 3);
  S21Matrix c(2, 3);
  double num = -9;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  num = 10;
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      b(i, j) = num;
      num++;
    }
  }
  c(0, 0) = -306.0;
  c(0, 1) = -330.0;
  c(0, 2) = -354.0;
  c(1, 0) = -189.0;
  c(1, 1) = -204.0;
  c(1, 2) = -219.0;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulMatrix, Test_9) {
  S21Matrix a(1, 7);
  S21Matrix b(7, 5);
  S21Matrix c(1, 5);
  double num = 2;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num += 2;
    }
  }
  num = 1;
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      b(i, j) = num;
      num++;
    }
  }
  c(0, 0) = 1176.0;
  c(0, 1) = 1232.0;
  c(0, 2) = 1288.0;
  c(0, 3) = 1344.0;
  c(0, 4) = 1400.0;
  a.MulMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), true);
}
// Оператор '*='
TEST(TestMulEqOperatorMatrix, Test_1) {
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  S21Matrix c(4, 4);
  double num_f = 1;
  double num_s = -5;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num_f;
      b(i, j) = num_s;
      num_f++;
      num_s++;
    }
  }
  c(0, 0) = 30.0;
  c(0, 1) = 40.0;
  c(0, 2) = 50.0;
  c(0, 3) = 60.0;
  c(1, 0) = 46.0;
  c(1, 1) = 72.0;
  c(1, 2) = 98.0;
  c(1, 3) = 124.0;
  c(2, 0) = 62.0;
  c(2, 1) = 104.0;
  c(2, 2) = 146.0;
  c(2, 3) = 188.0;
  c(3, 0) = 78.0;
  c(3, 1) = 136.0;
  c(3, 2) = 194.0;
  c(3, 3) = 252.0;
  a *= b;
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulEqOperatorMatrix, Test_2) {
  S21Matrix a(4, 2);
  S21Matrix b(2, 4);
  S21Matrix c(4, 4);
  double num = -5;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  num = 1;
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      b(i, j) = num;
      num++;
    }
  }
  c(0, 0) = -25.0;
  c(0, 1) = -34.0;
  c(0, 2) = -43.0;
  c(0, 3) = -52.0;
  c(1, 0) = -13.0;
  c(1, 1) = -18.0;
  c(1, 2) = -23.0;
  c(1, 3) = -28.0;
  c(2, 0) = -1.0;
  c(2, 1) = -2.0;
  c(2, 2) = -3.0;
  c(2, 3) = -4.0;
  c(3, 0) = 11.0;
  c(3, 1) = 14.0;
  c(3, 2) = 17.0;
  c(3, 3) = 20.0;
  a *= b;
  ASSERT_EQ(a.EqMatrix(c), true);
}

TEST(TestMulEqOperatorMatrix, Test_3) {
  S21Matrix a(5, 1);
  S21Matrix b(5, 2);
  ASSERT_THROW(a *= b, std::logic_error);
}
// Оператор '*'
TEST(TestMulOperatorMatrix, Test_1) {
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  S21Matrix c(4, 4);
  double num_f = 1;
  double num_s = -5;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num_f;
      b(i, j) = num_s;
      num_f++;
      num_s++;
    }
  }
  c(0, 0) = 30.0;
  c(0, 1) = 40.0;
  c(0, 2) = 50.0;
  c(0, 3) = 60.0;
  c(1, 0) = 46.0;
  c(1, 1) = 72.0;
  c(1, 2) = 98.0;
  c(1, 3) = 124.0;
  c(2, 0) = 62.0;
  c(2, 1) = 104.0;
  c(2, 2) = 146.0;
  c(2, 3) = 188.0;
  c(3, 0) = 78.0;
  c(3, 1) = 136.0;
  c(3, 2) = 194.0;
  c(3, 3) = 252.0;
  ASSERT_EQ(c == a * b, true);
}

TEST(TestMulOperatorMatrix, Test_2) {
  S21Matrix a(4, 2);
  S21Matrix b(2, 4);
  S21Matrix c(4, 4);
  double num = -5;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  num = 1;
  for (int i = 0; i < b.getRows(); i++) {
    for (int j = 0; j < b.getColumns(); j++) {
      b(i, j) = num;
      num++;
    }
  }
  c(0, 0) = -25.0;
  c(0, 1) = -34.0;
  c(0, 2) = -43.0;
  c(0, 3) = -52.0;
  c(1, 0) = -13.0;
  c(1, 1) = -18.0;
  c(1, 2) = -23.0;
  c(1, 3) = -28.0;
  c(2, 0) = -1.0;
  c(2, 1) = -2.0;
  c(2, 2) = -3.0;
  c(2, 3) = -4.0;
  c(3, 0) = 11.0;
  c(3, 1) = 14.0;
  c(3, 2) = 17.0;
  c(3, 3) = 20.0;
  ASSERT_EQ(c == a * b, true);
}

TEST(TestMulOperatorMatrix, Test_3) {
  S21Matrix a(5, 1);
  S21Matrix b(5, 2);
  ASSERT_THROW(a * b, std::logic_error);
}
// Транспонирование матрицы
TEST(TestTransposeMatrix, Test_1) {
  S21Matrix a;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * 22.11;
    }
  }
  S21Matrix b = a.Transpose();
  ASSERT_EQ(a.getColumns(), b.getRows());
  ASSERT_EQ(a.getRows(), b.getColumns());
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), b(j, i));
    }
  }
}

TEST(TestTransposeMatrix, Test_2) {
  S21Matrix a(2, 6);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) + 3.11 * j;
    }
  }
  S21Matrix b = a.Transpose();
  ASSERT_EQ(a.getColumns(), b.getRows());
  ASSERT_EQ(a.getRows(), b.getColumns());
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), b(j, i));
    }
  }
}

TEST(TestTransposeMatrix, Test_3) {
  S21Matrix a(5, 2);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) * 2222;
    }
  }
  S21Matrix b = a.Transpose();
  ASSERT_EQ(a.getColumns(), b.getRows());
  ASSERT_EQ(a.getRows(), b.getColumns());
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), b(j, i));
    }
  }
}

TEST(TestTransposeMatrix, Test_4) {
  S21Matrix a(1, 6);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) + 552.112;
    }
  }
  S21Matrix b = a.Transpose();
  ASSERT_EQ(a.getColumns(), b.getRows());
  ASSERT_EQ(a.getRows(), b.getColumns());
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), b(j, i));
    }
  }
}

TEST(TestTransposeMatrix, Test_5) {
  S21Matrix a(6, 1);
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = (i + j) + 99901.1;
    }
  }
  S21Matrix b = a.Transpose();
  ASSERT_EQ(a.getColumns(), b.getRows());
  ASSERT_EQ(a.getRows(), b.getColumns());
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(a(i, j), b(j, i));
    }
  }
}
// Детерминант
TEST(TestDeterminant, Tets_1) {
  S21Matrix a(2, 1);
  ASSERT_THROW(a.Determinant(), std::logic_error);
}

TEST(TestDeterminant, Test_2) {
  S21Matrix a(2, 3);
  ASSERT_THROW(a.Determinant(), std::logic_error);
}

TEST(TestDeterminant, Test_3) {
  S21Matrix a(1, 1);
  a(0, 0) = -5123.3421;
  double det = a.Determinant();
  ASSERT_DOUBLE_EQ(det, -5123.3421);
}

TEST(TestDeterminant, Test_4) {
  S21Matrix a(7, 7);
  double num = 1;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  double det = a.Determinant();
  ASSERT_DOUBLE_EQ(det, 0);
}

TEST(TestDeterminant, Test_5) {
  S21Matrix a;
  a(0, 0) = 15;
  a(0, 1) = -12.34;
  a(0, 2) = 5512;
  a(1, 0) = 0;
  a(1, 1) = 235;
  a(1, 2) = 34;
  a(2, 0) = -15;
  a(2, 1) = 16.3333;
  a(2, 2) = 1;
  double det = a.Determinant();
  ASSERT_DOUBLE_EQ(det, 19431288.417);
}

TEST(TestDeterminant, Test_6) {
  S21Matrix a;
  a(0, 0) = 4000.87;
  a(0, 1) = 454.0;
  a(0, 2) = 4.0;
  a(1, 0) = 2.0;
  a(1, 1) = 1.897;
  a(1, 2) = 3.0;
  a(2, 0) = 0.000087;
  a(2, 1) = 2.5668;
  a(2, 2) = 1.0;
  double det = a.Determinant();
  ASSERT_DOUBLE_EQ(det, -24105.996724156);
}
// Матрица алгебраических дополнений
TEST(TestCalcComplements, Test_1) {
  S21Matrix a(1, 2);
  ASSERT_THROW(a.CalcComplements(), std::logic_error);
}

TEST(TestCalcComplements, Test_2) {
  S21Matrix a(2, 1);
  ASSERT_THROW(a.CalcComplements(), std::logic_error);
}

TEST(TestCalcComplements, Test_3) {
  S21Matrix a(4, 4);
  a(0, 0) = 112.0;
  a(0, 1) = 243.0;
  a(0, 2) = 3.0;
  a(0, 3) = -8.0;
  a(1, 0) = 47.0;
  a(1, 1) = 51.0;
  a(1, 2) = -66.0;
  a(1, 3) = 99.0;
  a(2, 0) = -74.0;
  a(2, 1) = 85.0;
  a(2, 2) = 97.0;
  a(2, 3) = 63.0;
  a(3, 0) = -13.0;
  a(3, 1) = 79.0;
  a(3, 2) = -99.0;
  a(3, 3) = -121.0;
  S21Matrix c(4, 4);
  c(0, 0) = -2879514.0;
  c(0, 1) = -1236631.0;
  c(0, 2) = -1685096.0;
  c(0, 3) = 880697.0;
  c(1, 0) = 1162090.0;
  c(1, 1) = -714015.0;
  c(1, 2) = 4046255.0;
  c(1, 3) = -3901600.0;
  c(2, 0) = 4362897.0;
  c(2, 1) = -2049432.0;
  c(2, 2) = -532912.0;
  c(2, 3) = -1370781.0;
  c(3, 0) = 3412773.0;
  c(3, 1) = -1569493.0;
  c(3, 2) = 3144517.0;
  c(3, 3) = 1284666.0;
  ASSERT_EQ(a.CalcComplements() == c, true);
}

TEST(TestCalcComplements, Test_4) {
  S21Matrix a(4, 4);
  a(0, 0) = -1.0;
  a(0, 1) = 2.0;
  a(0, 2) = 7.0;
  a(0, 3) = 9.0;
  a(1, 0) = 1.0;
  a(1, 1) = 0.0;
  a(1, 2) = 0.0;
  a(1, 3) = 0.0;
  a(2, 0) = 47.0;
  a(2, 1) = 13.0;
  a(2, 2) = 17.0;
  a(2, 3) = 21.0;
  a(3, 0) = 22.0;
  a(3, 1) = 7.0;
  a(3, 2) = 1.0;
  a(3, 3) = 3.0;

  S21Matrix c(4, 4);
  c(0, 0) = 0.0;
  c(0, 1) = -30.0;
  c(0, 2) = -108.0;
  c(0, 3) = 106.0;
  c(1, 0) = 138.0;
  c(1, 1) = -726.0;
  c(1, 2) = -1137.0;
  c(1, 3) = 1061.0;
  c(2, 0) = 0.0;
  c(2, 1) = 12.0;
  c(2, 2) = 57.0;
  c(2, 3) = -47.0;
  c(3, 0) = 0.0;
  c(3, 1) = 6.0;
  c(3, 2) = -75.0;
  c(3, 3) = 57.0;
  ASSERT_EQ(a.CalcComplements() == c, true);
}

TEST(TestCalcComplements, Test_5) {
  S21Matrix a(1, 1);
  a(0, 0) = -53123.1235;
  S21Matrix c(1, 1);
  c(0, 0) = -53123.1235;
  ASSERT_EQ(a.CalcComplements() == c, true);
}
// Обратная матрица
TEST(TestInverseMatrix, Test_1) {
  S21Matrix a(1, 2);
  ASSERT_THROW(a.InverseMatrix(), std::logic_error);
}

TEST(TestInverseMatrix, Test_2) {
  S21Matrix a(5, 1);
  ASSERT_THROW(a.InverseMatrix(), std::logic_error);
}

TEST(TestInverseMatrix, Test_3) {
  S21Matrix a(1, 1);
  a(0, 0) = 2;
  double d = 1.0 / 2.0;
  ASSERT_DOUBLE_EQ(a.InverseMatrix()(0, 0), d);
}

TEST(TestInverseMatrix, Test_4) {
  S21Matrix a;
  double num = 1;
  for (int i = 0; i < a.getRows(); i++) {
    for (int j = 0; j < a.getColumns(); j++) {
      a(i, j) = num;
      num++;
    }
  }
  ASSERT_THROW(a.InverseMatrix(), std::logic_error);
}

TEST(TestInverseMatrix, Test_5) {
  S21Matrix a;
  a(0, 0) = 512;
  a(0, 1) = -3.5;
  a(0, 2) = 12;
  a(1, 0) = 55;
  a(1, 1) = 123.55;
  a(1, 2) = -0.89;
  a(2, 0) = 1;
  a(2, 1) = 991;
  a(2, 2) = 23;
  S21Matrix c(3, 3);
  c(0, 0) = 744728 / 512702339.0;
  c(0, 1) = 2394500 / 512702339.0;
  c(0, 2) = -295897 / 512702339.0;
  c(1, 0) = -253178 / 512702339.0;
  c(1, 1) = 2352800 / 512702339.0;
  c(1, 2) = 223136 / 512702339.0;
  c(2, 0) = 10876290 / 512702339.0;
  c(2, 1) = -101479100 / 512702339.0;
  c(2, 2) = 12690020 / 512702339.0;
  S21Matrix res = a.InverseMatrix();
  ASSERT_EQ(res.EqMatrix(c), true);
}

TEST(TestInverseMatrix, Test_6) {
  S21Matrix a(2, 2);
  a(0, 0) = 0.333;
  a(0, 1) = -15.2;
  a(1, 0) = 12.52521;
  a(1, 1) = 52.22;
  S21Matrix c(2, 2);
  c(0, 0) = 13055000 / 51943113.0;
  c(0, 1) = 3800000 / 51943113.0;
  c(1, 0) = -695845 / 11542914.0;
  c(1, 1) = 9250 / 5771457.0;
  ASSERT_EQ(a.InverseMatrix() == c, true);
}

TEST(TestInverseMatrix, Test_7) {
  S21Matrix a(4, 4);
  a(0, 0) = -1.0;
  a(0, 1) = 2.0;
  a(0, 2) = 7.0;
  a(0, 3) = 9.0;
  a(1, 0) = 1.0;
  a(1, 1) = 0.0;
  a(1, 2) = 0.0;
  a(1, 3) = 0.0;
  a(2, 0) = 47.0;
  a(2, 1) = 13.0;
  a(2, 2) = 17.0;
  a(2, 3) = 21.0;
  a(3, 0) = 22.0;
  a(3, 1) = 7.0;
  a(3, 2) = 1.0;
  a(3, 3) = 3.0;
  S21Matrix c(4, 4);
  c(0, 0) = 0.0;
  c(0, 1) = 1.0;
  c(0, 2) = 0.0;
  c(0, 3) = 0.0;
  c(1, 0) = -5.0 / 23.0;
  c(1, 1) = -121.0 / 23.0;
  c(1, 2) = 2.0 / 23.0;
  c(1, 3) = 1.0 / 23.0;
  c(2, 0) = -18.0 / 23.0;
  c(2, 1) = -379.0 / 46.0;
  c(2, 2) = 19.0 / 46.0;
  c(2, 3) = -25.0 / 46.0;
  c(3, 0) = 53.0 / 69.0;
  c(3, 1) = 1061.0 / 138.0;
  c(3, 2) = -47.0 / 138.0;
  c(3, 3) = 19.0 / 46.0;
  ASSERT_EQ(a.InverseMatrix() == c, true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}