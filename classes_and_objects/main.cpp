#include <iostream>
#include "Marsjanin.h"
#include "Matrix.h"
#include <list>

int Marsjanin::number = 0;

int main() {
   /* std::list <Marsjanin> Marsians;
    bool running = true;
    int a = 0;
    while (a < 6){
        Marsians.emplace_back();
        for (Marsjanin &i:Marsians) {
            i.Action();
        }
    a++;
    }
    std::cout << "Loop ended" << std::endl;*/
    Matrix M1("[ 1i3 2  ;3  4;4 5]");
    M1.ShowMatrix();
    Matrix M2("[ 1 2;3 4;4 5]");
    M2.AddRow("[10 11]");
    M2.ShowMatrix();
    Matrix M3 = M2;
    M3.ShowMatrix();
//    M3 = M1.Add(M2);
//    M3.ShowMatrix();
    return 0;
}