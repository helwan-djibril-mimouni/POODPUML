#include "player.h"

Player::Player()
{
    this->life = 10;
    this->money = 0;
    this->timer = 0;
}

void Player::update(std::vector<Animal> animals, std::vector<Tower> towers){
    timer++;
    if (timer >= 60){
        timer = 0;
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i].end){
                life -= 1;
                animals.erase(animals.begin() + i);
            }
        }
        for (int i = 0; i < towers.size(); i++)
        {
            if (towers[i].x == 0 && towers[i].y == 0){
                money += 1;
            }
        }
    }
}


Player::~Player()
{
}