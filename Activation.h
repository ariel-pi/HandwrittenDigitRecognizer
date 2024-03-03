// Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"
namespace activation{
typedef Matrix (*activation_function) (const Matrix&);

  /**
     * Rectified Linear Unit (ReLU) activation function.
     * ReLU sets all negative values to zero and leaves positive values unchanged.
     * @param m Input matrix.
     * @return Matrix with ReLU activation applied.
     */
    Matrix relu(const Matrix& m);
    /**
     * Softmax activation function.
     * Softmax computes the probability distribution over the classes for each input sample.
     * @param m Input matrix.
     * @return Matrix with Softmax activation applied.
     */
    Matrix softmax(const Matrix& m);
}











#endif //ACTIVATION_H