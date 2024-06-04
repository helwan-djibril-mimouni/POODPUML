#include "Path.cpp"
#include "raylib.h"

class Animal
{
public:
    int x;
    int y;
    int pathsDone;
    int lengthFromPath;
    int health;
    Path path;
    Texture2D texture;
    bool end;
    Animal(Path path, int x, int y, Texture2D texture, int health);
    ~Animal();
    void update();
};
