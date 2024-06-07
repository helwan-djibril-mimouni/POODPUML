#include "raylib.h"
#include <vector>
#include <iostream>

class Tower
{
public:
    Tower( int x , int y);
    Tower();
    int x;
    int y;
    int range;
    std::vector<int> update(std::vector<std::tuple<int, int>> animals);
    void upgrade();
    int level;
    int cost_next_upgrade;
    int damage;
    int count;
    int fire_rate;
    bool hit;
    int hitCount;
    Texture2D texture;
    ~Tower();
};