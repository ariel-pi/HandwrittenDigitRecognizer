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
  /**
     * Constructor for Dense layer.
     * @param weight Weight matrix.
     * @param bias Bias matrix.
     * @param func Activation function.
     */
  Dense(const Matrix& weight, const Matrix& bias,
        activation::activation_function func);
  /**
   * Getter for weights matrix.
   * @return Const reference to the weights matrix.
   */
  const Matrix& get_weights() const {return weight_vector;}
  /**
   * Getter for bias matrix.
   * @return Const reference to the bias matrix.
   */
  const Matrix& get_bias() const {return bias_vector;}
  /**
   * Getter for activation function.
   * @return Activation function.
   */
  activation::activation_function get_activation()
  const {return activation_func;}
  /**
   * Operator overload for applying Dense layer to input vector.
   * @param vector Input vector.
   * @return Output matrix after applying Dense layer.
   */

  Matrix operator()(const Matrix& vector) const ;

};









#endif //DENSE_H