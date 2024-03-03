// MlpNetwork.h
#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4

/**
 * @struct digit
 * @brief Identified (by Mlp network) digit with
 *        the associated probability.
 * @var value - Identified digit value
 * @var probability - identification probability
 */
typedef struct digit {
	unsigned int value;
	float probability;
} digit;

const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
									{64,  128},
									{20,  64},
									{10,  20}};
const matrix_dims bias_dims[] = {{128, 1},
								 {64,  1},
								 {20,  1},
								 {10,  1}};

// Insert MlpNetwork class here...
class MlpNetwork
{
 private:
  Dense r_1;
  Dense r_2;
  Dense r_3;
  Dense r_4;
 public:
  /**
   * Constructs a new MlpNetwork with the given weights and biases.
   *
   * @param weights Weights of the network.
   * @param biases Biases of the network.
   */
  MlpNetwork(const Matrix weights[MLP_SIZE], const Matrix
  biases[MLP_SIZE]);
  /**
      * Classifies a given input matrix into a digit using the MLP network.
      *
      * This function feeds the input matrix through each layer of the MLP network
      * and returns the digit with the highest probability.
      *
      * @param m Input matrix to be classified.
      * @return A digit structure containing the classified digit value and its probability.
      */
  digit operator()(const Matrix& m ) const;

};

#endif // MLPNETWORK_H