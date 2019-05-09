//
// Created by falcon on 4/8/19.
//
#ifndef IOSTREAM_NAMESPACE

#include <iostream>

#endif

#ifndef CLASSES_AND_OBJECTS_MATRIX_H
#define CLASSES_AND_OBJECTS_MATRIX_H

#include <regex>
#include <complex>

class Matrix {
private:
    int n;
    int m;
    std::complex<double> ** matrix;
    std::pair<int,int> dimension;
public:
    Matrix();
    Matrix(std::pair <int , int>);
    Matrix(const Matrix& );
    ~Matrix(){
        for (int i = 0 ; i < dimension.first ; ++i)delete [] matrix[i];
        std::cout << "Destructor called "<< std::endl;
    }

    explicit Matrix(const std::string& );
    Matrix Add(const Matrix& );
    Matrix toPower(const Matrix&);
    Matrix Multiply(const Matrix&);
    Matrix Divide(const Matrix&);
    void AddColumn(const std::string &);
    void AddRow(const std::string &);

    void ComputeDim(const std::string& );
    void ShowMatrix();
};


#endif //CLASSES_AND_OBJECTS_MATRIX_H
