#include "raylib.h"
#include <vector>

static std::vector<Texture2D> getTowerTextures(){ // design pattern : singleton and object pool
    std::vector<Texture2D> list;
    Image image = LoadImage("assets/towerA1.png");
    Texture2D texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerA2.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerA3.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerA4.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerA5.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerA6.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);

    
    image = LoadImage("assets/towerB1.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerB2.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerB3.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerB4.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerB5.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerB6.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/towerC1.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerC2.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerC3.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerC4.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerC5.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerC6.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/towerD1.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerD2.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerD3.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerD4.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerD5.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerD6.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/towerE1.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerE2.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerE3.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerE4.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerE5.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/towerE6.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);

    return list;
}
