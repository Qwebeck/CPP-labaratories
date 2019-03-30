#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <algorithm>
#include <regex>

using namespace std;


unsigned int ToMinutes(std::string time_HH_MM);
unsigned int MinimalTimeDifference(std::vector<unsigned int>& times);

int main() {
    vector<string> hours = {"12:30","10:55","11:20" , "11:21"};
    vector<unsigned int> minutes;
    for (string& i:hours) {
        minutes.push_back(ToMinutes(i));
    }

    sort(minutes.begin() , minutes.end());
    cout << "Mininal time difference " << MinimalTimeDifference(minutes);
    return 0;
}

unsigned int ToMinutes(string time_HH_MM)
{
    regex time(R"(([0-9][0-9]?):([0-9][0-9]))");
    smatch matches;
    regex_match(time_HH_MM,matches,time);
    string hours = matches[1];
    string minutes = matches[2];

    return static_cast<unsigned int>(stoi(hours) * 60 + stoi(minutes));

}

unsigned int MinimalTimeDifference(std::vector<unsigned int>& times)
{
    unsigned int MinDiff = *max_element(times.begin(),times.end());
    int i = 0;
    while ( i + 1 != times.size())
    {
        if ( times[i + 1] - times[i] < MinDiff)
            MinDiff = times[i + 1 ] - times[i];
        ++i;
    }
    return MinDiff;
};