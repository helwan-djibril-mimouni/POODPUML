#include "Tower.h"
#include "TowerTextureLoader.cpp"
#include <iostream>

Tower::Tower( int x , int y, Texture2D texture)
{
    this->x = x;
    this->y = y;
    this->range = 50;
    this->level = 1;
    this->cost_next_upgrade = 200;
    this->damage = 1;
    this->count = 0;
    this->fire_rate = 500;
    this->texture = texture;
}

Tower::Tower()
{
    this->x = -100;
    this->y = -100;
    this->range = 1;
    this->level = 1;
    this->cost_next_upgrade = 200;
    this->damage = 1;
    this->count = 0;
    this->fire_rate = 500;
    this->texture = LoadTexture(NULL);
    this->hit = false;
}

std::vector<int> Tower::update(std::vector<std::tuple<int, int>> animalsPos){
    count++;
    if (hitCount > 0){
        hitCount--;
    }
    else{
        hit = false;
    }
    std::vector<int> damages;
    if (count >= fire_rate){
        count = 0;
        for (int i = 0; i < animalsPos.size(); i++)
        {
            int animalX = std::get<0>(animalsPos[i]);
            int animalY = std::get<1>(animalsPos[i]);
            if (abs(animalX - x) <= range + 41 && abs(animalY - y) <= range + 41){
                damages.push_back(damage);
                hit = true;
                hitCount = 10;
                //animation ?
                break;
            }
            else{
                damages.push_back(0);
            }
        }
    }
    return damages;
}


void Tower::upgrade(Texture2D texture){
    level++;
    cost_next_upgrade *= 2;
    damage += 1;
    if (fire_rate > 5){
        fire_rate -= 5;
    }
    this->texture = texture;
}

Tower::~Tower()
{
}
