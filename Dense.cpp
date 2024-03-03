//
// Created by ariel on 01-Mar-24.
//
#include "Dense.h"
#include "Activation.h"
// documentation in the header file
Dense::Dense(const Matrix& weight, const Matrix& bias,
             activation::activation_function
func){
  weight_vector = weight;
  bias_vector = bias;
  activation_func = func;
}
// documentation in the header file
Matrix Dense::operator()(const Matrix& vector) const {
    return activation_func(weight_vector*vector + bias_vector);
}
