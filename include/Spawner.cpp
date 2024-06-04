#include "Spawner.h"
#include "TextureLoader.cpp"
#include <cstdlib>
#include <ctime>

Spawner::Spawner(Path path, int x, int y) : path(path)
{
    this->animalTextures = getTextures();
    this->posX = x;
    this->posY = y;
    this->wave = 1;
    this->waveAmount = 2;
    this->waveScoreMin = 0;
    this->waveScoreMax = 0;
    this->count = 0;
    this->spawnSpeed = 100;
}

Spawner::~Spawner()
{
}

void Spawner::update(){
    if (count == 0){
        if (waveAmount > 0){
            srand((unsigned) time(NULL));
            int rand;
            if (waveScoreMax == 0){
                rand = 0;
            }
            else{
                rand = std::rand() % waveScoreMax;
                rand += waveScoreMin;
                if (rand >= 40){
                    rand = 39;
                }
            }
            Animal animal = Animal(this->path, this->posX, this->posY, this->animalTextures[rand]);
            this->animals.push_back(animal);
            waveAmount--;
        }
    }

    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i].end){
            animals.erase(animals.begin()+i);
        }
        animals[i].update();
    }

    if (waveAmount == 0 && animals.size() == 0){
        wave++;
        waveScoreMax++;
        waveAmount = wave*2;
        spawnSpeed -= 1;
        if (spawnSpeed <= 0){
            spawnSpeed = 1;
        }
        if (wave%5 == 0){
            waveScoreMin++;
        }
    }

    count++;

    if (count >= spawnSpeed){
        count = 0;
    }
}
