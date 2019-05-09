//
// Created by falcon on 5/9/19.
//

#include "MovieDvdSubtitles.h"

void DvdSubtitles::MovieDvdSubtitles(std::ifstream& sub_stream )
{
    if(!sub_stream.is_open()){
        sub_stream.open("subtitles.txt");
    };
    std::string tmp;
    std::string current;
    while (getline(sub_stream,tmp)) {
        current = tmp;
        std::pair<int, int> frames = std::make_pair(0, 0);
        std::regex time{R"(\{ *(\d+) *\})"};
        std::smatch matches;
        int i = 0;
        while (std::regex_search(tmp, matches, time) and i < 2) { ;
            if (!i)frames.first = stoi(matches[1].str());
            else frames.second = stoi(matches[1].str());
            tmp = matches.suffix();
            ++i;
        }
        if (i!=2)throw InvalidSubtitleLineFormat(current);

        this -> _subtitles.emplace_back(frames,tmp);
        tmp = "";
    }
    sub_stream.close();
}
void DvdSubtitles::ShiftAllFramesByValue(int  shift)
{
    try {
    for(auto& subtitle:_subtitles)
    {
        subtitle.first.first += shift;
        subtitle.first.second+=shift;
        if(subtitle.first.first < 0 or subtitle.first.second < 0)
        {
            throw NegativeFrameAfterShift();
        }
    }
    }catch (NegativeFrameAfterShift &e){std::cerr<<e.what()<<std::endl;}

}
void DvdSubtitles::ShiftChosenFrame(int begin , int end , int frame) {
    try{
        if (frame >=_subtitles.size()) throw OutOfOrderFrames();
        _subtitles.at(frame);
        if (begin < 0 or end < 0) throw NegativeFrameAfterShift();
        if (begin>end) throw SubtitleEndBeforeStart();
        if (_subtitles[frame+1].first.first < end)throw SubtitleOverlap();
        _subtitles[frame].first.first = begin;
        _subtitles[frame].first.second = end;
        for (std::vector<std::pair<std::pair<int,int>,std::string>>::const_iterator it = _subtitles.begin();it!=it + frame;++it)
        {
            if(it -> first.first > _subtitles[frame].first.first)throw SubtitleOverlap();
        }
    }
    catch(std::out_of_range &e){std::cerr << e.what()<<std::endl;}
    catch (NegativeFrameAfterShift &e){std::cerr<<e.what()<<std::endl;}
    catch (SubtitleEndBeforeStart &e){std::cerr <<e.what()<<std::endl;}
    catch (SubtitleOverlap &e){std::cerr <<e.what()<<std::endl;}

}
