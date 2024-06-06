#include "TowerManager.h"
#include <vector>

TowerManager::TowerManager()
{
    Rectangle rectangle = {100, 96, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {244, 96, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {343, 96, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {445, 96, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {546, 96, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {686, 96, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {100, 299, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {244, 299, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {343, 299, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {445, 299, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {546, 299, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {686, 299, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {142, 396, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {244, 396, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {343, 396, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {445, 396, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {546, 396, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {647, 396, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {142, 499, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {244, 499, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {343, 499, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {445, 499, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {546, 499, 41, 41};
    tower_rectangles.push_back(rectangle);
    rectangle = {647, 499, 41, 41};
    tower_rectangles.push_back(rectangle);     

    this->money = 200;
    this->towerTextures = getTowerTextures();
}


void TowerManager::addTower(int x, int y, int index){
    if (towers[index].x < 0){
        if (money >= 100){
            money -= 100;
            Tower tower(x, y);
            towers[index] = tower;
        }
    }
}

void TowerManager::gainMoney(int money){
    this->money += money;
}

std::vector<std::vector<int>> TowerManager::update(std::vector<std::tuple<int, int>> animalsPos){

    for (int i = 0; i < tower_rectangles.size(); i++)
    {
        if (CheckCollisionPointRec(GetMousePosition(), tower_rectangles[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            if (towers[i].x < 0){
                addTower(tower_rectangles[i].x, tower_rectangles[i].y, i);
            }
            else{
                if (money >= towers[i].cost_next_upgrade){
                    money -= towers[i].cost_next_upgrade;
                    towers[i].upgrade();
                }
            }
        }
    }
    std::vector<std::vector<int>> listDamages;
    for (int i = 0; i < 24; i++)
    {
        std::vector<int> damages = towers[i].update(animalsPos);
        listDamages.push_back(damages);
    }
    return listDamages;
}



TowerManager::~TowerManager()
{
}