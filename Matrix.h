// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


// You don't have to use the struct. Can help you with MlpNetwork.h
/**
 * Defines the dimensions of a matrix.
 */
struct matrix_dims {
    int rows, cols;
};


// Insert Matrix class here...
/**
 * Represents a matrix and provides various operations on matrices.
 */
class Matrix {
 private:
  int rows, cols;
  float *data;

 public:
  /**
   * Constructs a matrix with specified dimensions and initializes elements to 0.
   *
   * @param rows Number of rows in the matrix.
   * @param cols Number of columns in the matrix.
   */
  Matrix (int rows, int cols);
  /**
   * Constructs a 1x1 matrix and initializes its element to 0.
   */
  Matrix ();
  /**
   * Copy constructor.
   *
   * @param other Another matrix to copy from.
   */
  Matrix (const Matrix &other);
  /**
   * Destructor.
   */
  ~Matrix ();
  /**
     * Returns the number of rows in the matrix.
     *
     * @return Number of rows.
     */
  int get_rows () const;
  /**
 * Returns the number of columns in the matrix.
 *
 * @return Number of columns.
 */
  int get_cols () const;
  /**
   * Transposes the matrix.
   *
   * @return Reference to the transposed matrix.
   */
  Matrix &transpose ();
  /**
       * Converts the matrix to a vector (i.e., a single column).
       *
       * @return Reference to the vectorized matrix.
       */
  Matrix &vectorize ();
    /**
     * Prints the matrix to the standard output.
     */
  void plain_print () const;
    /**
     * Computes the dot product of this matrix with another matrix
     * element-wise.
     *
     * @param other Another matrix.
     * @return The dot product of the two matrices.
     */
  Matrix dot (const Matrix &other) const;
  /**
   * Computes the Euclidean norm of the matrix.
   *
   * @return Euclidean norm of the matrix.
   */
  float norm () const;
/**
   * Computes the reduced row echelon form of the matrix.
   *
   * @return Reduced row echelon form of the matrix.
   */
  Matrix rref () const;
    /**
     * Returns the index of the maximum element in the matrix.
     *
     * @return Index of the maximum element.
     */
  int argmax () const;
    /**
     * Returns the sum of all elements in the matrix.
     *
     * @return Sum of all elements.
     */
  float sum () const;
  /**
     * Adds another matrix to the current matrix element-wise.
     *
     * @param m Matrix to be added.
     * @return Reference to the current matrix after addition.
     */
  Matrix &operator+= (const Matrix &m);
  /**
   * Adds two matrices and returns the result.
   *
   * @param m Another matrix to be added.
   * @return Resulting matrix after addition.
   */
  Matrix operator+ (const Matrix &m) const;
  /**
   * Assigns the content of another matrix to the current matrix.
   *
   * @param m Another matrix to be assigned.
   * @return Reference to the current matrix after assignment.
   */
  Matrix &operator= (const Matrix &m);
  /**
 * Multiplies the matrix with another matrix.
 *
 * @param m Another matrix to be multiplied with.
 * @return Resulting matrix after multiplication.
 */
  Matrix operator* (const Matrix &m) const;
  /**
 * Multiplies the matrix with a scalar value.
 *
 * @param scalar Scalar value to be multiplied with.
 * @return Resulting matrix after multiplication with scalar.
 */
  Matrix operator* (float scalar) const;
  /**
 * Provides access to the matrix elements for modification.
 *
 * @param row Row index of the element.
 * @param col Column index of the element.
 * @return Reference to the matrix element.
 */
  float &operator() (int row, int col);
  /**
     * Provides read-only access to the matrix elements.
     *
     * @param row Row index of the element.
     * @param col Column index of the element.
     * @return Value of the matrix element.
     */
  float operator() (int row, int col) const;
  /**
 * Provides access to the matrix elements using 1D indexing for modification.
 *
 * @param index Index of the element.
 * @return Reference to the matrix element.
 */
  float &operator[] (int index);
  /**
 * Provides read-only access to the matrix elements using 1D indexing.
 *
 * @param index Index of the element.
 * @return Value of the matrix element.
 */
  float operator[] (int index) const;

};
/**
 * Multiplies a scalar value with a matrix.
 *
 * @param scalar Scalar value to be multiplied with.
 * @param m Matrix to be multiplied.
 * @return Resulting matrix after multiplication.
 */
Matrix operator* (float scalar, const Matrix &m);
/**
 * Outputs the matrix to the given output stream.
 *
 * @param os Output stream to write to.
 * @param m Matrix to be written.
 * @return Reference to the output stream.
 */
std::ostream &operator<< (std::ostream &os, const Matrix &m);
/**
 * Inputs data into the matrix from the given input stream.
 *
 * @param input Input stream to read from.
 * @param matrix_to_fill Matrix to be filled with data.
 * @return Reference to the input stream.
 */
std::istream &operator>> (std::istream &input, Matrix &matrix_to_fill);

#endif //MATRIX_H