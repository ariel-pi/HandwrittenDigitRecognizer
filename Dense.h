// Dense.h
#ifndef DENSE_H
#define DENSE_H

#include "Matrix.h"
#include "Activation.h"


// Insert Dense class here...
class Dense
{
 private:
  Matrix weight_vector;
  Matrix bias_vector;
  activation::activation_function activation_func;

 public :
  Dense(const Matrix& weight, const Matrix& bias,
        activation::activation_function func);
  const Matrix& get_weights() const {return weight_vector;}
  const Matrix& get_bias() const {return bias_vector;}
  activation::activation_function get_activation()
  const {return activation_func;}
  Matrix operator()(const Matrix& vector) const ;

};









#endif //DENSE_H