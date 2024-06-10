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
    int maxHealth;
    int fps;
    Path path;
    Texture2D texture;
    bool end;
    bool finish;
    Animal(Path path, int x, int y, Texture2D texture, int health);
    ~Animal();
    void update(int speed);
};
