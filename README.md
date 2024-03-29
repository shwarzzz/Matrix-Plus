# Matrix+

В данном проекте была реализована библиотека для работы с матрицами, используя объектно-ориентированный подход. Объектно-ориентированный подход позволяет реализовать библиотеку для работы с матрицами в виде отдельного класса, над объектами которого определены операции, представленные как методами, так и стандартными операторами +, -, * и т.д.

### Реализованные методы

| Операция                                 | Описание                                                                    | Исключительные ситуации                                           |
| ---------------------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| `bool EqMatrix(const S21Matrix& other)`  | Проверяет матрицы на равенство между собой                                  |                                                                   |
| `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицы к текущей                                         | различная размерность матриц                                      |
| `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую                                          | различная размерность матриц                                      |
| `void MulNumber(const double num)`       | Умножает текущую матрицу на число                                           |                                                                   |
| `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую                                          | число столбцов первой матрицы не равно числу строк второй матрицы |
| `S21Matrix Transpose()`                  | Создает новую транспонированную матрицу из текущей и возвращает ее          |                                                                   |
| `S21Matrix CalcComplements()`            | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее | матрица не является квадратной                                    |
| `double Determinant()`                   | Вычисляет и возвращает определитель текущей матрицы                         | матрица не является квадратной                                    |
| `S21Matrix InverseMatrix()`              | Вычисляет и возвращает обратную матрицу                                     | определитель матрицы равен 0                                      |

### Реализованные конструкторы и деструктор

| Метод                               | Описание                                                                              |
| ----------------------------------- | ------------------------------------------------------------------------------------- |
| `S21Matrix()`                       | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью |
| `S21Matrix(int rows, int cols)`     | Параметризированный конструктор с количеством строк и столбцов                        |
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования                                                               |
| `S21Matrix(S21Matrix&& other)`      | Конструктор переноса                                                                  |
| `~S21Matrix()`                      | Деструктор                                                                            |

### Перегруженные операторы

| Оператор         | Описание                                          | Исключительные ситуации                                           |
| ---------------- | ------------------------------------------------- | ----------------------------------------------------------------- |
| `+`              | Сложение двух матриц                              | различная размерность матриц                                      |
| `-`              | Вычитание одной матрицы из другой                 | различная размерность матриц                                      |
| `*`              | Умножение матриц и умножение матрицы на число     | число столбцов первой матрицы не равно числу строк второй матрицы |
| `==`             | Проверка на равенство матриц (`EqMatrix`)         |                                                                   |
| `=`              | Присвоение матрице значений другой матрицы        |                                                                   |
| `+=`             | Присвоение сложения (`SumMatrix`)                 | различная размерность матриц                                      |
| `-=`             | Присвоение разности (`SubMatrix`)                 | различная размерность матриц                                      |
| `*=`             | Присвоение умножения (`MulMatrix`/`MulNumber`)    | число столбцов первой матрицы не равно числу строк второй матрицы |
| `(int i, int j)` | Индексация по элементам матрицы (строка, колонка) | индекс за пределами матрицы                                       |

## Требования к проекту 

- Программа должна быть разработана на языке C++ стандарта C++17;
- При написании кода необходимо придерживаться Google Style
- Подготовить полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest
- Предусмотреть Makefile для сборки библиотеки и тестов.

## Запуск проекта

- Для сборки статической библиотеки необходимо выполнить команду:
```bash
make all
```
- Для запуска тестов выполните следующие команды:
```bash
make test
./test
```
- Для просмотра покрытия кода в терминале выполните команду:
```bash
make gcov_report
```