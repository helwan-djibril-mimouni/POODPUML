#include "Path.h"
#include "raylib.h"

class Animal
{
private:
    int x;
    int y;
    int pathsDone;
    int lengthFromPath;
    Path path;
    Texture2D texture;
public:
    Animal(Path path, int x, int y, Texture2D texture);
    ~Animal();
    void update();
};
