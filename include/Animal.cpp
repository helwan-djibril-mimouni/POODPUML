#include "Animal.h"

Animal::Animal(Path path, int x, int y, Texture2D texture) : path(path)
{
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
    int direction = -1;
    int length;
    std::map<int, std::tuple<int, int>>::iterator it = path.map.begin();
    int count = 0;
    std::cout << path.map.size() << std::endl;
    while (it != path.map.end()){
        if (count == pathsDone){
            direction = std::get<0>(it->second);
            std::cout << it->first << " : " << std::get<0>(it->second) << "," << std::get<1>(it->second) << std::endl;
            length = std::get<1>(it->second);
            std::cout << direction << ", " << length << std::endl;
        }
        it++;
        count++;
    }
    std::cout << "end while" << std::endl;
    if (direction == -1){
        CloseWindow();
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