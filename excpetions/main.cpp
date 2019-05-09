#include <iostream>
#include <fstream>
#include <regex>
#include <exception>
#include <string>
#include <vector>
#include "MovieDvdSubtitles.h"





int main() {
    std::ifstream subtitles;
    subtitles.open("/home/bohdan/Projects/JIMP2/excpetions/subtitles.txt");

    if(!subtitles.is_open()){
        std::cout<<"closed";
    };
    std::string tmp;
    subtitles>>tmp;
    std::cout<<tmp;
    DvdSubtitles Dvd(subtitles);
    Dvd.ShiftAllFramesByValue(-15);
    Dvd.ShiftChosenFrame(10 , 11 , 5);
    Dvd.ShiftChosenFrame(45 , 11 , 1);
    Dvd.ShiftChosenFrame(10 , 21 , 1);


    //    subtitles.close();



    return 0;
}
