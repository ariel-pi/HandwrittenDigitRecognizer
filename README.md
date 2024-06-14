# Image Digit Recognition Project

This C++ project aims to analyze images of a manuscript stored in a binary file and identify the digits that were written. It provides functionalities for image processing, matrix operations, and implementing a multi-layer perceptron (MLP) network for digit recognition.

## Project Structure

### Matrix
Defines a class `Matrix` for matrix operations, which serves as the backbone for various mathematical operations involved in image processing and neural network computations.

### Activation
Contains activation functions such as Rectified Linear Unit (ReLU) and softmax, which are essential components of neural networks for introducing non-linearity.

### Dense
Defines a class `Dense` representing dense neural network layers. It encapsulates the weights, biases, and activation functions necessary for implementing fully connected layers.

### MlpNetwork
Implements a class `MlpNetwork` representing a multi-layer perceptron (MLP) network. This class orchestrates the process of feeding input images through the network layers and classifying them into digits.

### main.cpp
Contains the main function to demonstrate the usage of the project components. It includes loading manuscript images, initializing the MLP network, and classifying the digits present in the images.


## Usage

1. **Data Preprocessing**: Prepare the manuscript images and convert them into a suitable format for input to the MLP network.

2. **Initialization**: Instantiate the necessary matrices, including weights and biases for each layer of the MLP network.

3. **Training (Optional)**: If required, train the MLP network using a suitable training dataset to optimize the network parameters.

4. **Recognition**: Pass the preprocessed manuscript images through the trained MLP network using the `MlpNetwork` class to classify the digits present in the images.

## Example

```cpp
#include "Matrix.h"
#include "Activation.h"
#include "Dense.h"
#include "MlpNetwork.h"

int main() {
    // Load manuscript images from binary file
    // Preprocess images if necessary

    // Initialize MLP network
    Matrix weights[MLP_SIZE]; // Initialize weights for each layer
    Matrix biases[MLP_SIZE]; // Initialize biases for each layer
    MlpNetwork network(weights, biases);

    // Classify manuscript images
    // Pass images through the network and obtain digit predictions

    return 0;
}
