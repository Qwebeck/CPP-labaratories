#include <iostream>
#include <regex>
#include <string>
#include "StudyYear.h"
#include "StudentRepository.h"
#include "Student.h"
using ::std::string;
using ::std::regex;
using ::std::smatch;
class complex{
private:
    double img;
    double real;
public:
    complex();
    complex(double , double );

    std::istream&operator>>(std::istream & input)
    {
        input.ignore();
        input >> this -> real;
        input.ignore();
        input >> this -> img;
        input.ignore();
        return input;
    }




    void print() { std::cout << real << " + i" << img << std::endl; }

    const complex operator+(const complex& other)
    {
        complex res;
        res.img = img + other.img;
        res.real = real + other.real;
        return res;
    };
    const complex operator-(const complex& other)
    {
        complex res;
        res.img = img - other.img;
        res.real = real - other.real;
        return res;
    };
    std::ostream& operator<<(std::ostream & output)
    {
        output << this -> real << " + ";
        output << this -> img <<"i";
        output << std::endl;
        return output;
    }
    const complex operator*(const complex&other)
    {
        complex res;
        res.real = this -> real * other.real + this -> img * other.img * (-1);
        res.img = this -> real * other.img + other.real * other.img;
        return res;
    }
    const complex operator/(const complex&other)
    {
        complex res;

        double d = other.real * other.real + other.img * other.img * (-1);

        res.real = (this -> real * other.real + this -> img * other.img * (-1)) / d;
        res.img = (this -> real * other.img + other.real * other.img)/d;
        return res;
    }

};
/*std::istream&operator>>(std::istream & input , complex & obj)
{
    input.ignore();
    input >> obj.real;
    input.ignore();
    input >> obj.img;
    input.ignore();
    return input;
}*/

complex::complex()
{
    img = 0;
    real = 0;
}
complex::complex(double real_p, double img_p) {
    img = img_p;
    real = real_p;
}



int main() {
   /* complex z1(4,5);
    complex z2(5,7);
    complex z3 = z1 + z2;
    complex z4 = z1 * z2;

    z3<<std::cout;
    z3 >> std::cin;
    z3<<std::cout;
    z4<<std::cout;
    z4 = z1 / z4;
    z4<<std::cout;
    complex z8(1,0);
    complex z9(2 ,0);
    z4 = z8 * z9;
    z4 << std::cout;
    std::cout << "Hello, World!" << std::endl;*/
    /*Student Arkadiusz;
    Arkadiusz >> std::cin;
    Arkadiusz.about();*/
    StudentRepository cs;
    cs >> std::cin;
    if (cs["2030001236"] != nullptr)cs["2030001236"] -> about();
    StudentRepository sr;
    sr >> std::cin;
    bool a = sr==cs;
    std::cout << a << std::endl;
    return 0;
}