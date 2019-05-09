//
// Created by falcon on 5/9/19.
//

#ifndef EXCPETIONS_MOVIEDVDSUBTITLES_H
#define EXCPETIONS_MOVIEDVDSUBTITLES_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
class Subtitles {

public:
    virtual void MovieDvdSubtitles(std::ifstream& ) = 0;
};
struct NegativeFrameAfterShift:public std::invalid_argument{
    NegativeFrameAfterShift():invalid_argument("Negative frame after shift"){};
};
struct SubtitleEndBeforeStart:public std::invalid_argument{
    SubtitleEndBeforeStart():invalid_argument("Negative frame after shift"){};
};

struct SubtitleOverlap:public std::runtime_error{
    SubtitleOverlap():runtime_error("Overlap"){};
};
class InvalidSubtitleLineFormat:public std::runtime_error{
public:
    InvalidSubtitleLineFormat(std::string sub_line):runtime_error("Invalid subtitle format"){_sub_line = sub_line;};
public:
    std::string _bad_line() const {return _sub_line;}
private:
    std::string _sub_line;
};

struct OutOfOrderFrames:public std::out_of_range{
    OutOfOrderFrames():out_of_range("Element is out of range "){};
};

class DvdSubtitles:public Subtitles{
private:
    std::vector<std::pair<std::pair<int,int>,std::string>> _subtitles;
public:
    DvdSubtitles(std::ifstream& sstream)
    {
        try{
        MovieDvdSubtitles(sstream);
        }catch (InvalidSubtitleLineFormat &e)
        {
            std::cerr<<e.what()<< ": in line ' " << e._bad_line() << "'" << std::endl;
        }
    };
    void MovieDvdSubtitles(std::ifstream& ) override;
    void ShiftAllFramesByValue(int );
    void ShiftChosenFrame(int ,int ,int );

};



#endif //EXCPETIONS_MOVIEDVDSUBTITLES_H
