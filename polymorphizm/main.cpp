#include <iostream>

#include "IterableIterator.h"
int main() {
    const std::vector<int> vi {4, 77, -91};
    const std::vector<string> vs {"4", "9991", "adfskld"};
//    ZipperIterator _iterator(vi.begin(),vs.begin(),vi.end(),vs.end());
    for (const auto &p : Zipper(vi, vs)) {
        std::cout << "(" << p.first << ", \"" << p.second << "\") "<< std::endl;
    }
    ZipperIterator _iterator(vi.begin(),vs.begin(),vi.end(),vs.end());
    std::cout << "Hello, World!" << std::endl;
    return 0;
}