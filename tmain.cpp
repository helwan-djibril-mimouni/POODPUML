#include "raylib.h"
#include "MainMenu.cpp"
#include "scoreMenu.cpp"

int main(){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    // Main game loop
    MainMenu mainMenu;
    scoreMenu ScoreMenu("scores.txt");
    while (!WindowShouldClose()){
        if (!mainMenu.scoreMenu) {
            mainMenu.drawMenu();
            mainMenu.eventListener();
        }
        else{
            ScoreMenu.draw();
            ScoreMenu.eventListener();
            if (!ScoreMenu.menulaunch){
                ScoreMenu.menulaunch = true;
                mainMenu.scoreMenu = false;
            }
        }
    }
}