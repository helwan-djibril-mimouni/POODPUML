#include "Path.cpp"
#include "raylib.h"

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Image bee = LoadImage("assets/bee_yellow.png");
    Texture2D bee_texture = LoadTextureFromImage(bee);

    Path path = Path(0, 300);
    path.add(1, 200);
    path.add(2, 200);
    path.add(3, 200);
    path.add(0, 500);
    path.add(1, 500);
    path.add(2, 200);
    path.add(3, 200);
    path.add(0, 400);

    int posX = 0;
    int posY = 0;
    int pathsDone = 0;
    int lengthFromPath = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(bee_texture, posX, posY, WHITE);

        int direction = -1;
        int length;
        std::map<int, std::tuple<int, int>>::iterator it = path.map.begin();
        int count = 0;
        std::cout << path.map.size() << std::endl;
        while (it != path.map.end()){
            if (count == pathsDone){
                direction = std::get<0>(it->second);
                std::cout << it->first << " : " << std::get<0>(it->second) << "," << std::get<1>(it->second) << std::endl;
                length = std::get<1>(it->second);
                std::cout << direction << ", " << length << std::endl;
            }
            it++;
            count++;
        }
        std::cout << "end while" << std::endl;
        if (direction == -1){
            CloseWindow();
        }
        if (direction == 0){
            posX++;
        }
        else if (direction == 1){
            posY++;
        }
        else if (direction == 2){
            posX--;
        }
        else if (direction == 3){
            posY--;
        }
        lengthFromPath++;

        if (lengthFromPath >= length){
            pathsDone++;
            lengthFromPath = 0;
        }

        EndDrawing();
    }
}
// need class for path, class for animal following path