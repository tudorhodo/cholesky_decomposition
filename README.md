# Cholesky Decomposition



## Descrierea Algoritmului
In linear algebra, a matrix decomposition or matrix factorization is a factorization of a matrix into a product of matrices. There are many different matrix decompositions. One of them is Cholesky Decomposition.

The Cholesky decomposition or Cholesky factorization is a decomposition of a Hermitian, positive-definite matrix into the product of a lower triangular matrix and its conjugate transpose. The Cholesky decomposition is roughly twice as efficient as the LU decomposition for solving systems of linear equations.

The Cholesky decomposition of a Hermitian positive-definite matrix A is a decomposition of the form A = [L][L]^T, where L is a lower triangular matrix with real and positive diagonal entries, and L^T denotes the conjugate transpose of L. Every Hermitian positive-definite matrix (and thus also every real-valued symmetric positive-definite matrix) has a unique Cholesky decomposition.
![This is an image](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-2c9c5ec3c07feb9806c5c71186ca7007_l3.svg)

Every symmetric, positive definite matrix A can be decomposed into a product of a unique lower triangular matrix L and its transpose: A = L L^T 

The following formulas are obtained by solving above lower triangular matrix and its transpose. These are the basis of Cholesky Decomposition Algorithm : 

![This is an image](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-f485728e0eb6ecec335903f70bd3dc5c_l3.svg)
