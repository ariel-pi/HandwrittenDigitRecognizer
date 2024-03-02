//
// Created by ariel on 01-Mar-24.
//
#include "Dense.h"
#include "Activation.h"
Dense::Dense(const Matrix& weight, const Matrix& bias,
             activation::activation_function
func){
  weight_vector = weight;
  bias_vector = bias;
  activation_func = func;
}
Matrix Dense::operator()(const Matrix& vector) const {
    return activation_func(weight_vector*vector + bias_vector);
}
