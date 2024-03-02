// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


// You don't have to use the struct. Can help you with MlpNetwork.h
struct matrix_dims {
    int rows, cols;
};


// Insert Matrix class here...
class Matrix {
 private:
    int rows, cols;
    float* data;

 public:
  Matrix(int rows, int cols);
  Matrix();
  Matrix(const Matrix &other);
  ~Matrix();
  int get_rows() const;
  int get_cols() const;
  Matrix& transpose();
  Matrix& vectorize();
  void plain_print() const;
  Matrix dot(const Matrix &other) const;
  float norm() const;
  Matrix rref() const;
  int argmax() const;
  float sum() const;
  Matrix &operator+=(const Matrix &m);
  Matrix operator+(const Matrix &m) const;
  Matrix &operator=(const Matrix &m);
  Matrix operator*(const Matrix &m) const;
  Matrix operator*(float scalar) const;
  float& operator()(int row, int col);
  float operator()(int row, int col) const;
  float& operator[] (int index);
  float operator[] (int index) const;



};
Matrix operator*(float scalar, const Matrix &m);
std::ostream &operator<<(std::ostream &os, const Matrix &m);
std::istream &operator>> (std::istream &input, Matrix &matrix_to_fill);

#endif //MATRIX_H