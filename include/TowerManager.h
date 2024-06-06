#include "Tower.cpp"

class TowerManager
{

public:
    TowerManager();
    std::vector<Tower> towers;
    std::vector<Rectangle> tower_rectangles;
    void addTower(int x, int y);
    std::vector<std::vector<int>> update(std::vector<std::tuple<int, int>> animalsPos);  
    ~TowerManager();
    void gainMoney(int money);
    int money;
};