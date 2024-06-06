#include "Spawner.cpp"
#include "TowerManager.cpp"
#include "raylib.h"
#include "player.h"

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    Path path = Path(0, 300);
    path.add(1, 500);
    path.add(2, 200);
    path.add(3, 200);
    path.add(0, 600);
    path.add(1, 200);
    path.add(2, 200);
    path.add(3, 500);
    path.add(0, 300);

    Spawner spawner = Spawner(path, 0, 50);
    TowerManager towerManager = TowerManager();
    Image image = LoadImage("assets/background.png");
    Texture2D background = LoadTextureFromImage(image);
    int time = 0;
    int count = 0;

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(background, 0, 0, WHITE);

        int money = spawner.update();
        towerManager.gainMoney(money);

        std::vector<std::tuple<int, int>> positions;
        for (Animal a : spawner.animals){
            std::tuple<int, int> data = std::tuple(a.x, a.y);
            positions.push_back(data);
        }

        std::vector<std::vector<int>> listDamages = towerManager.update(positions);

        for (std::vector<int> damages : listDamages){
            for (int i = 0; i < damages.size(); i++){
                spawner.animals[i].health -= damages[i];
            }
        }
        
        //player.update(spawner.animals, towerManager.towers);



        for (int i = 0; i < spawner.animals.size(); i++)
        {
            DrawTexture(spawner.animals[i].texture, spawner.animals[i].x, spawner.animals[i].y, WHITE);
        }
        for (int i = 0; i < towerManager.towers.size(); i++)
        {
            DrawTexture(towerManager.towers[i].texture, towerManager.towers[i].x, towerManager.towers[i].y, WHITE);
        }

        DrawText(("Vague: " + std::to_string(spawner.wave)).c_str(), 10, 10, 20, WHITE);

        DrawText(("Argent: " + std::to_string(towerManager.money)).c_str(), 250, 10, 20, WHITE);

        DrawText(("Vie: " + std::to_string(spawner.playerHP)).c_str(), 450, 10, 20, WHITE);

        DrawText(("timer: " + std::to_string(time)).c_str(), 650, 10, 20, WHITE);

        if (count >= 60){
            count = 0;
            time++;
        }

        count++;

        EndDrawing();
    }

    return 0;
}