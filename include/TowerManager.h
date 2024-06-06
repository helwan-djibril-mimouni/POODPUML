#include "Tower.cpp"

class TowerManager
{

public:
    TowerManager();
    Tower towers[24];
    std::vector<Rectangle> tower_rectangles;
    std::vector<Texture2D> towerTextures;
    void addTower(int x, int y, int index);
    std::vector<std::vector<int>> update(std::vector<std::tuple<int, int>> animalsPos);  
    ~TowerManager();
    void gainMoney(int money);
    int money;
};