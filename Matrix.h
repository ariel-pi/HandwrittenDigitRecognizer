// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


// You don't have to use the struct. Can help you with MlpNetwork.h
struct matrix_dims {
    int rows, cols;
};


// Insert Matrix class here...
struct Matrix {
 private:
    int rows, cols;
    float* data;

 public:
  Matrix(int rows, int cols);
  Matrix();
  Matrix(const Matrix &other);
  ~Matrix();
  int getRows() const;
  int getCols() const;
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

  /**
    Matrix(int rows, int cols);
    Matrix(const Matrix &m);
    ~Matrix();
    Matrix &operator=(const Matrix &m);
    Matrix operator*(const Matrix &m) const;
    Matrix operator+(const Matrix &m) const;
    Matrix operator-(const Matrix &m) const;
    Matrix operator-() const;
    Matrix &operator+=(const Matrix &m);
    Matrix &operator-=(const Matrix &m);
    Matrix &operator*=(const Matrix &m);
    Matrix operator*(float scalar) const;
    Matrix &operator*=(float scalar);
    Matrix operator/(float scalar) const;
    Matrix &operator/=(float scalar);
    float *operator[](int i);
    const float *operator[](int i) const;
    Matrix transpose() const;
    Matrix hadamard(const Matrix &m) const;
    Matrix apply(float (*func)(float)) const;
    Matrix apply(float (*func)(float, float), float scalar) const;
    Matrix apply(float (*func)(float, float), const Matrix &m) const;
    Matrix vectorize() const;
    Matrix reshape(int rows, int cols) const;
    Matrix dot(const Matrix &m) const;
    Matrix sum(int axis) const;
    Matrix mean(int axis) const;
    Matrix std(int axis) const;
    Matrix var(int axis) const;
    Matrix softmax() const;
    Matrix relu() const;
    Matrix sigmoid() const;
    Matrix tanh() const;
    Matrix exp() const;
    Matrix log() const;
    Matrix pow(float scalar) const;
    Matrix pow(const Matrix &m) const;
    Matrix sqrt() const;
    Matrix abs() const;
    Matrix sum() const;
    Matrix mean() const;
    Matrix std() const;
    Matrix var() const;
    Matrix operator==(const Matrix &m) const;
    Matrix operator!=(const Matrix &m) const;
    Matrix operator>(const Matrix &m) const;
    Matrix operator>=(const Matrix &m) const;
    Matrix operator<(const Matrix &m) const;
    Matrix operator<=(const Matrix &m) const;
    Matrix operator&&(const Matrix &m) const;
    Matrix operator||(const Matrix &m) const;
    Matrix operator!() const;
    Matrix &operator++();
    Matrix operator++(int);
    Matrix &operator--();
    Matrix operator
    */

};
Matrix operator*(float scalar, const Matrix &m);
std::ostream &operator<<(std::ostream &os, const Matrix &m);
std::istream &operator>> (std::istream &input, Matrix &matrix_to_fill);

#endif //MATRIX_H