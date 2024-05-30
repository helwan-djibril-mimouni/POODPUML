#include "Path.h"

Path::Path(int direction, int length)
{
    std::map<int, std::tuple<int, int>> temp;
    std::tuple<int, int> data = std::tuple(direction, length);
    temp[1] = data;
    this->map = temp;
}

Path::~Path()
{
}

void Path::add(int direction, int length){
    std::map<int, std::tuple<int, int>>::iterator it = this->map.begin();
    std::tuple<int, int> data = std::tuple(direction, length);
    int count = 1;
    while (it != this->map.end()){
        it++;
        count++;
    }
    std::cout << count << std::endl;
    this->map.insert(std::make_pair(count, data));
}