#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    // Write your code here
  Complex ** A = new Complex *[m];
  for(unsigned int i = 0; i<m; i++){
    A[i] = new Complex[n];
  }

  for(unsigned int r_ = 0; r_<m; r_++){
    for(unsigned int c_ = 0; c_<n; c_++){
      A[r_][c_].im = c.im;
      A[r_][c_].re = c.re;
        }
    } 
  return A;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    // Write your code here
    for(unsigned int r_ = 0; r_<m; r_++){
        for(unsigned int c_ = 0; c_<n; c_++){
            if(A[r_][c_].im>=0){
            cout << A[r_][c_].re << "+" <<A[r_][c_].im << "i ";
            }else{
            cout << A[r_][c_].re << A[r_][c_].im << "i ";
            }
        }
        cout << "\n";
    } 
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Write your code here
    Complex c = {0, 0};
    Complex **A = createMatrix(n, n, c);
    for(unsigned int r_ = 0; r_<n; r_++){
        for(unsigned int c_ = 0; c_<n; c_++){
            if(r_ == c_){
            A[r_][c_].re = 1;
            A[r_][c_].im = 0;
            }else{
            A[r_][c_].re = 0;
            A[r_][c_].im = 0;
            }
        }
    } 
    return A;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    // Write your code here
    Complex sum_ = {0, 0};
    for(unsigned int i = 0; i < m; ++i){
        for(unsigned int j = 0; j < p; ++j){
            C[i][j].im = 0;
            C[i][j].re = 0;
            for(unsigned int k = 0; k < n; ++k){
                C[i][j].im = add(C[i][j], mult(A[i][k], B[k][j])).im;
                C[i][j].re = add(C[i][j], mult(A[i][k], B[k][j])).re;
            }
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
