//
// Created by ariel on 01-Mar-24.
//
#include <cmath>
#include "Activation.h"
// documentation in the header file
Matrix activation::relu(const Matrix& m){
    Matrix res_matrix = Matrix(m.get_rows (), m.get_cols ());
    for(int i = 0; i < m.get_rows () * m.get_cols (); ++i)
    {
        if (m[i] >= 0)
        {
            res_matrix[i] = m[i];
        }
        else
        {
            res_matrix[i] = 0;
        }
    }
    return res_matrix;
}
// documentation in the header file
Matrix activation::softmax(const Matrix& m){
    Matrix res_matrix = Matrix(m.get_rows (), m.get_cols ());
    for (int i = 0; i < m.get_rows () * m.get_cols (); i++)
    {
      res_matrix[i] = std::exp(m[i]);
    }
    return res_matrix * (1/res_matrix.sum());
}
