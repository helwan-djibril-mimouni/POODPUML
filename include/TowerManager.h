#include "Tower.cpp"


class TowerManager
{

public:
    TowerManager();
    std::vector<Tower> towers;
    std::vector<Rectangle> tower_rectangles;
    void addTower(int x, int y);
    void update(std::vector<Animal> animals);  
    ~TowerManager();

};