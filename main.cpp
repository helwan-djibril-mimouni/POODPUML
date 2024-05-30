#include "raylib.h"
#include "MainMenu.cpp"

int main(){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    // Main game loop
    MainMenu mainMenu;
    while (!WindowShouldClose()){
        mainMenu.drawMenu();
        mainMenu.eventListener();
    }
}