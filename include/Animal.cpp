#include "Animal.h"

Animal::Animal(Path path, int x, int y, Texture2D texture, int health) : path(path)
{
    this->x = x;
    this->y = y;
    this->texture = texture;
    this->pathsDone = 0;
    this->lengthFromPath = 0;
    this->end = false;
    this->health = health;
}

Animal::~Animal()
{
}

void Animal::update(){
    int direction = -1;
    int length;
    std::map<int, std::tuple<int, int>>::iterator it = path.map.begin();
    int count = 0;
    while (it != path.map.end()){
        if (count == pathsDone){
            direction = std::get<0>(it->second);
            length = std::get<1>(it->second);
        }
        it++;
        count++;
    }
    // TODO: animal killed by turret
    if (direction == -1){
        this->end = true;
    }
    if (direction == 0){
        x++;
    }
    else if (direction == 1){
        y++;
    }
    else if (direction == 2){
        x--;
    }
    else if (direction == 3){
        y--;
    }
    lengthFromPath++;

    if (lengthFromPath >= length){
        pathsDone++;
        lengthFromPath = 0;
    }
}