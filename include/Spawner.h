#include <vector>
#include "Animal.cpp"

class Spawner
{
public:
    std::vector<Texture2D> animalTextures;
    std::vector<Animal> animals;
    Path path;
    int posX;
    int posY;
    int wave;
    int waveAmount;
    int waveScoreMin;
    int waveScoreMax;
    int count;
    int spawnSpeed;
    Spawner(Path path, int x, int y);
    ~Spawner();
    void update();
};
