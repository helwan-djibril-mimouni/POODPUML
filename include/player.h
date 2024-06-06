
#include <vector>

class Player {
public:
    int life;
    int money;
    int timer;

    Player() {
        life = 100;
        money = 0;
        timer = 0;
    }
    void update(std::vector<Animal> animals, std::vector<Tower> towers);
};