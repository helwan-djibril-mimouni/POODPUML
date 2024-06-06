#include "Tower.h"
#include <iostream>

Tower::Tower( int x , int y)
{
    this->x = x;
    this->y = y;
    this->range = 50;
    this->level = 1;
    this->cost_next_upgrade = 10;
    this->damage = 1;
    this->count = 0;
    this->fire_rate = 100;
    this->texture = LoadTexture("assets/tower.png");
}

std::vector<int> Tower::update(std::vector<std::tuple<int, int>> animalsPos){
    count++;
    std::vector<int> damages;
    if (count >= fire_rate){
        count = 0;
        for (int i = 0; i < animalsPos.size(); i++)
        {
            int animalX = std::get<0>(animalsPos[i]);
            int animalY = std::get<1>(animalsPos[i]);
            if (abs(animalX - x) <= range + 41 && abs(animalY - y) <= range + 41){
                damages.push_back(damage);
                std::cout << "hit" << std::endl;
                //animation ?
                break;
            }
        }
    }
    return damages;
}


void Tower::upgrade(){
    level++;
    cost_next_upgrade += 10;
    damage += 1;
    fire_rate -= 1;
}

Tower::~Tower()
{
}
