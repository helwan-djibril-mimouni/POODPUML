#include <map>
#include <iostream>

class Path
{
public:
    std::map<int, std::tuple<int, int>> map;        // direction, length
    Path(std::map<int, std::tuple<int, int>> map);         
    Path(int direction, int length);                // direction : 0=E, 1=S, 2=W, 3=N
    void add(int direction, int length);            // length in pixels
    ~Path();
};