//
// Created by ariel on 01-Mar-24.
//
#include <cmath>
#include "Activation.h"
Matrix activation::relu( const Matrix& m){
    Matrix res_matrix = Matrix(m.getRows(),m.getCols());
    for(int i = 0; i < m.getRows() * m.getCols(); ++i)
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
Matrix activation::softmax(const Matrix& m){
    Matrix res_matrix = Matrix(m.getRows(),m.getCols());
    for (int i = 0; i < m.getRows() * m.getCols(); i++)
    {
      res_matrix[i] = std::exp(m[i]);
    }
    return res_matrix * (1/res_matrix.sum());
}