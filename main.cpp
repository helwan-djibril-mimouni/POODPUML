#include "Spawner.cpp"
#include "TowerManager.cpp"
#include "raylib.h"

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

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(background, 0, 0, WHITE);

        spawner.update();
        towerManager.update(spawner.animals);


        for (int i = 0; i < spawner.animals.size(); i++)
        {
            DrawTexture(spawner.animals[i].texture, spawner.animals[i].x, spawner.animals[i].y, WHITE);
        }
        for (int i = 0; i < towerManager.towers.size(); i++)
        {
            DrawTexture(towerManager.towers[i].texture, towerManager.towers[i].x, towerManager.towers[i].y, WHITE);
        }

        // TODO: add turret system (don't forget to make it infinitely upgradable, or at least a lot)
        // help : can simply check for animal in radius r
        // example : if (turret.x - animal.x <= abs(r)) { animal.end = true; } + animation ?

        EndDrawing();
    }

    return 0;
}