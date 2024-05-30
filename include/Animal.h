#include "Path.cpp"
#include "raylib.h"

class Animal
{
public:
    int x;
    int y;
    int pathsDone;
    int lengthFromPath;
    Path path;
    Texture2D texture;
    Animal(Path path, int x, int y, Texture2D texture);
    ~Animal();
    void update();
};
