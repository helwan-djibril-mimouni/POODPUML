
#include "raylib.h"
#include <vector>

class Tower
{
public:
    Tower( int x , int y);
    int x;
    int y;
    int range;
    void update(std::vector<Animal> animals);
    void upgrade();
    int level;
    int cost_next_upgrade;
    int damage;
    int count;
    int fire_rate;
    Texture2D texture;
    ~Tower();
};