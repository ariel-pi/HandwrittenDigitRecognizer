//
// Created by ariel on 01-Mar-24.
//
#include "MlpNetwork.h"


MlpNetwork::MlpNetwork(const Matrix weights[MLP_SIZE],
                       const Matrix biases[MLP_SIZE])
    : r_1(weights[0], biases[0], activation::relu),
      r_2(weights[1], biases[1], activation::relu),
      r_3(weights[2], biases[2], activation::relu),
      r_4(weights[3], biases[3], activation::softmax) {
}
digit MlpNetwork:: operator()(const Matrix& m ) const {


    Matrix result = r_1(m);
    result = r_2(result);
    result = r_3(result);
    result = r_4(result);
    digit d;
    d.value = result.argmax();
    d.probability = result[(int)d.value];
    return d;

}