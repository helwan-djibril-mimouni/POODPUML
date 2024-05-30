#include "Animal.h"

Animal::Animal(Path path, int x, int y, Texture2D texture)
{
    this->path = path;
    this->x = x;
    this->y = y;
    this->texture = texture;
    this->pathsDone = 0;
    this->lengthFromPath = 0;
}

Animal::~Animal()
{
}

void Animal::update(){
    
}