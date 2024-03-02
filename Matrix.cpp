//
// Created by ariel on 29-Feb-24.
//
#include <iostream>
#include "Matrix.h"
#include <cmath>
Matrix::Matrix(int rows, int cols): rows(rows), cols(cols) {
  if (rows <= 0 || cols <= 0) {
    // todo: check if need to throw exception or return null
  }
  data = new float[rows * cols];
  for (int i = 0; i < rows * cols; i++) {
    data[i] = 0;
  }
}
Matrix::Matrix() : rows(1), cols(1), data(new float[1])
{}
Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(new
float[other.rows * other.cols]) {
  for (int i = 0; i < rows * cols; ++i) {
    data[i] = other.data[i];
  }
}
Matrix::~Matrix() {
  delete[] data;
}
int Matrix:: get_rows() const {
  return rows;
}
int Matrix:: get_cols() const {
  return cols;
}

Matrix &Matrix::transpose() {
  float *new_data = new float[rows * cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      new_data[j * rows + i] = (*this)(i,j);
    }
  }

  Matrix transposed = Matrix(cols, rows);
  //todo: maybe need to delete data before?
  transposed.data = new_data;
  *this = transposed;
  return *this;
}

Matrix& Matrix::vectorize ()
{
    rows = rows * cols;
    cols = 1;
    return *this;
}
void Matrix::plain_print() const {
    std::cout<<this;
}
Matrix Matrix::dot(const Matrix &other) const
{
  if (cols != other.cols || rows != other.rows)
  {
  throw std::exception();
  }
  Matrix result = Matrix (rows, other.cols);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < other.cols; j++)
    {
      result(i, j) = (*this)(i, j) * other(i, j);
    }
  }
    return result;
}
float Matrix::norm() const
{
  float sum = 0;
  for (int i = 0; i < rows * cols; i++)
  {
    sum += data[i] * data[i];
  }
  return (float)sqrt((double)sum);
}

Matrix Matrix::rref() const
{
  Matrix result = *this;
  int lead = 0;
  for (int r = 0; r < rows; r++)
  {
    if (cols <= lead)
    {
      break;
    }
    int i = r;
    while (result.data[i * rows + lead] == 0)
    {
      i++;
      if (rows == i)
      {
        i = r;
        lead++;
        if (cols == lead)
        {
          break;
        }
      }
    }
    for (int j = 0; j < cols; j++)
    {
      std::swap(result.data[i * rows + j], result.data[r * rows + j]);
    }
    float div = result.data[r * rows + lead];
    for (int j = 0; j < cols; j++)
    {
      result.data[r * rows + j] /= div;
    }
    for (int i = 0; i < rows; i++)
    {
      if (i != r)
      {
        float sub = result.data[i * rows + lead];
        for (int j = 0; j < cols; j++)
        {
          result.data[i * rows + j] -= sub * result.data[r * rows + j];
        }
      }
    }
    lead++;
  }
  return result;
}

int Matrix::argmax() const
{
  int max_idx = 0;
  for (int i = 1; i < rows * cols; i++)
  {
    if (data[i] > data[max_idx])
    {
      max_idx = i;
    }
  }
  return max_idx;
}

float Matrix::sum() const
{
  float sum_val = 0;
  for (int i = 0; i < rows * cols; i++)
  {
    sum_val += data[i];
  }
  return sum_val;
}


Matrix& Matrix::operator+=(const Matrix &other)
{
  if (rows != other.rows || cols != other.cols)
  {
    throw std::exception();
  }
  for (int i = 0; i < rows * cols; i++)
  {
    data[i] += other.data[i];
  }
    return *this;

}
Matrix Matrix::operator+(const Matrix &other) const
{
  if (rows != other.rows || cols != other.cols)
  {
    throw std::exception();
  }
  Matrix result = Matrix(rows, cols);
  result+= *this;
  result+= other;
  return result;

}

Matrix& Matrix::operator=(const Matrix &other)
{
  if (this == &other)
  {
    return *this;
  }
  delete[] data;
  rows = other.rows;
  cols = other.cols;
  data = new float[rows * cols];
  for (int i = 0; i < rows * cols; i++)
  {
    data[i] = other.data[i];
  }
  return *this;
}



Matrix Matrix::operator*(const Matrix &other) const
{
  if(cols != other.rows)
  {
    throw std::exception();
  }

    Matrix result= Matrix (rows, other.cols);
    for (int i = 0; i <rows; i++)
    {
      for (int j = 0; j < other.cols; j++)
      {
        float sum = 0;
        for (int k = 0; k < cols; k++)
        {
          sum += (*this)(i, k) *
                 other(k, j);
        }
        result(i, j) = sum;
      }
    }
    return result;

}

Matrix Matrix::operator*(float scalar) const
{
  Matrix result = *this;
  for (int i = 0; i < rows * cols; i++)
  {
    result.data[i] *= scalar;
  }
  return result;
}

Matrix operator*(float scalar, const Matrix &m)
{
  return m * scalar;
}
float& Matrix::operator() (int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
      throw std::exception();
    }
  return this->data[row * cols + col];
}
float Matrix::operator() (int row, int col) const
{
  if (row < 0 || row >= rows || col < 0 || col >= cols)
  {
    throw std::exception();
  }
  return this->data[row * cols + col];
}

float& Matrix::operator[] (int index)
{
    if (index < 0 || index >= rows * cols)
    {
      throw std::exception();
    }
  return this->data[index];
}
float Matrix::operator[] (int index) const
{
  if (index < 0 || index >= rows * cols)
  {
    throw std::exception();
  }
  return this->data[index];
}

std::ostream &operator<<(std::ostream &os, const Matrix &m){
  for (int i = 0; i < m.get_rows (); i++) {
    for (int j = 0; j < m.get_cols (); j++) {
      if (m[i * m.get_rows () + j] > 0.1){
        os << "**";
      }
      else{
        os << "  ";
      }

    }
    os << std::endl;
  }
  return os;
}
std::istream &operator>> (std::istream &input, Matrix &matrix_to_fill)
{
  size_t matrix_num_of_bytes = matrix_to_fill.get_rows () * matrix_to_fill
      .get_cols () * (size_t)sizeof (float);
  char *data = new char[matrix_num_of_bytes];
  //todo: can i use char*?
  input.read (data, matrix_num_of_bytes);
  if (input.fail () || input.gcount () < matrix_num_of_bytes)
  {
    delete[] data;
    throw std::exception ();
  }

  float* float_data= new float[matrix_to_fill.get_rows () * matrix_to_fill
      .get_cols ()];;
  memcpy(float_data, data, matrix_num_of_bytes);

  for (int i = 0; i < matrix_to_fill.get_rows () * matrix_to_fill.get_cols (); i++)
  {
    matrix_to_fill[i] = float_data[i];
  }

  delete[] data;
  return input;
}





