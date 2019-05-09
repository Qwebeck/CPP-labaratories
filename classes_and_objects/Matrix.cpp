//
// Created by falcon on 4/8/19.
//

#include "Matrix.h"
//Matrix::Matrix() = default;
Matrix::Matrix(std::pair <int , int> dim)
{
    dimension = dim;
    m = dim.first;
    n = dim.second;
    int i = 0;
    matrix = new std::complex<double>* [m] ;

    for( i ; i < m ; ++i)
    {
        *(matrix + i) = new std::complex<double>[n];
    }
}
;
Matrix::Matrix() {
    m = dimension.first;
    n = dimension.second;
    int i = 0;
    matrix = new std::complex<double>* [m] ;
    for( i ; i < m ; ++i)
    {
        *(matrix + i) = new std::complex<double>[n];
    }
}
Matrix Matrix::Add(const Matrix &other) {
    Matrix summed(this -> dimension);
//    summed.ShowMatrix();
    for (int i = 0; i < dimension.first ; ++i)
    {
        for (int j = 0; j < dimension.second ; ++j) {
            *(*(summed.matrix + i) + j) = *(*(this->matrix + i )+ j) + *(*(other.matrix + i )+ j);
        }
    }
    return summed;
}
void Matrix::ShowMatrix() {
    int i = 0;
    int j = 0;
    for ( i;i < m ; ++i)
    {
        for(j = 0 ;j < n ; ++j)std::cout<< *(*(matrix + i) + j) << " " ;
        std::cout << std::endl;
    }
}

void Matrix::ComputeDim(const std::string & str_mtr)
{
    std::string parse = str_mtr;
    std::regex r(R"(;)");
    std::regex num(R"(\d+(i\d+)?)");
    std::smatch mathces;
    int rows = 1; //first is already computed
    while (std::regex_search (parse,mathces,r)) {
        rows += 1;
        parse = mathces.suffix().str();
    }
    parse = str_mtr;
    int cells = 0;
    while (std::regex_search (parse,mathces,num)) {
        cells += 1;
        parse = mathces.suffix().str();
    }
    int col = int(cells / rows);
    dimension = std::make_pair(rows,col);

}

Matrix::Matrix(const std::string & str_mtr) {
    ComputeDim(str_mtr);
    m = dimension.first;
    n = dimension.second;

    int i = 0;
    matrix = new std::complex<double>* [m] ;
    for( i ; i < m ; ++i)
    {
        *(matrix + i) = new std::complex<double>[n];
    }
    std::string parse = str_mtr;
    int j = 0;
    i = 0;
    std::regex el(R"((\d)+i?(\d+)?)");
    std::smatch mathces;
    while (std::regex_search (parse,mathces,el)) {
        if (mathces.length() == 3)
        {
            *(*(matrix + int(i/n)) + i%n) = std::complex<double>(std::stoi(mathces[0]),std::stoi(mathces[2]));
        }
        else *(*(matrix + int(i/n)) + i%n) = std::stoi(mathces[0]);
//        }
        ++i;
        std::cout << std::endl;
        parse = mathces.suffix().str();
    }

}

Matrix::Matrix(const Matrix &old) {
    std::cout << "Copying here" << std::endl;
    m = old.dimension.first;
    n = old.dimension.second;
    int i = 0;
    matrix = new std::complex<double>* [m] ;
    for( i ; i < m ; ++i)
    {
        *(matrix + i) = new std::complex<double>[n];
    }
    int j;
    for(j = 0 ; j < m ; ++j)
    {
        for(i = 0 ; i < n ; ++i)
        {
            *(*(this -> matrix + j) + i) = *(*(old.matrix + j) + i);
        }
    }
    this -> dimension = std::make_pair(m ,n);
}


void Matrix::AddRow(const std::string & newrow)
{
    int i = 0;
    int j = 0;
    std::complex<double> ** tmp = new std::complex<double>* [dimension.first + 1];

    for( i = 0 ; i <= dimension.first ; ++i)
    {
        *(tmp + i) = new std::complex<double>[n];
    }

    for(j = 0 ; j < m ; ++j)
    {
        for(i = 0 ; i < n ; ++i)
        {
            *(*(tmp + j) + i) = *(*(matrix + j) + i);
        }
    }

    i = i * j;
    std::string parse = newrow;
    std::regex el(R"((\d)+i?(\d+)?)");
    std::smatch mathces;
    while (std::regex_search (parse,mathces,el)) {
        if (mathces.length() == 3)
        {
            *(*(tmp + 1 + int(i/(dimension.first))) + i%(dimension.first)) = std::complex<double>(std::stoi(mathces[0]),std::stoi(mathces[2]));
        }
        else *(*(tmp + 1 + int(i/(dimension.first ))) + i%(dimension.first )) = std::stoi(mathces[0]);
//        }
        ++i;
        std::cout << std::endl;
        parse = mathces.suffix().str();
    }

    for (int i = 0 ; i < dimension.first ; ++i)delete [] matrix[i];

    matrix = tmp;
//    std::cout <<"Before tmp" << std::endl;
//    i = 0;
//    j = 0;
//    for ( i;i <= dimension.first   ; ++i)
//    {
//        for(j = 0 ;j < dimension.second ; ++j)std::cout<< *(*(matrix + i) + j) << " " ;
//        std::cout << std::endl;
//    }
    dimension.first += 1;
    std::cout <<"After tmp" << std::endl;
    std::cout << "Calles" << std::endl;


}