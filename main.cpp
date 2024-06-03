#include "Spawner.cpp"
#include "raylib.h"

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

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

    Image image = LoadImage("assets/background.png");
    Texture2D texture = LoadTextureFromImage(image);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(texture, 0, 0, WHITE);

        spawner.update();

        for (int i = 0; i < spawner.animals.size(); i++)
        {
            DrawTexture(spawner.animals[i].texture, spawner.animals[i].x, spawner.animals[i].y, WHITE);
        }

        EndDrawing();
    }

    return 0;
}
// need class for path, class for animal following path