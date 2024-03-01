//
// Created by ariel on 01-Mar-24.
//
#include "Dense.h"
Dense::Dense(const Matrix& weight,const Matrix& bias,activation_func func){
  weight_vector = weight;
  bias_vector = bias;
  activation_function = func;
}
Matrix Dense::operator()(const Matrix& vector) const {
    return activation_function(weight_vector.dot(vector) + bias_vector);
}
