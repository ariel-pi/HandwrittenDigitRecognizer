// Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

typedef Matrix (*activation_function) (const Matrix&);

// Insert Activation namespace here...
namespace activation
{
  Matrix relu( const Matrix& m);
  Matrix softmax(const Matrix& m);
}











#endif //ACTIVATION_H