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
    this->fire_rate = 2;
    this->texture = LoadTexture("assets/tower.png");
}



void Tower::update(std::vector<Animal> animals){
    count++;
    if (count >= fire_rate){
        count = 0;
        for (int i = 0; i < animals.size(); i++)
        {
            if (abs(animals[i].x - x) <= range + 41 && abs(animals[i].y - y) <= range + 41){
                animals[i].end = true;
                std::cout << "hit" << std::endl;
                //animation ?
            }
        }
    } 
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
