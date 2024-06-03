#include "raylib.h"
#include <vector>

std::vector<Texture2D> getTextures(){
    std::vector<Texture2D> list;
    Image image = LoadImage("assets/bee_yellow.png");
    Texture2D texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bee_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bee_bronze.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bee_silver.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bee_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/bird_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bird_blue.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bird_green.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bird_red.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/bird_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/chicken_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/chicken_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/chicken_brown.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/chicken_grey.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/chicken_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/rabbit_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/rabbit_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/rabbit_brown.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/rabbit_beige.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/rabbit_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/cat_orange.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/cat_beige.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/cat_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/cat_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/cat_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/pig_pink.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/pig_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/pig_brown.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/pig_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/pig_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/dog_beige.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/dog_brown.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/dog_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/dog_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/dog_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    
    image = LoadImage("assets/fox_orange.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/fox_brown.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/fox_black.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/fox_white.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);
    image = LoadImage("assets/fox_gold.png");
    texture = LoadTextureFromImage(image);
    list.push_back(texture);

    return list;
}