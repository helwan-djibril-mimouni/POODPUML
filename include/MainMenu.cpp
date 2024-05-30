#include "raylib.h"

class MainMenu{
    public:
        void drawMenu(){
            BeginDrawing();
                ClearBackground(BLACK);
                DrawText("Tower Defense",400-MeasureText("Tower Defense",50)/2 ,30, 50, WHITE);

                DrawRectangle(275, 200, 250, 50, GRAY);
                DrawText("Normal Mode", 400-MeasureText("Normal Mode",30)/2, 210, 30, WHITE);

                DrawRectangle(275, 300, 250, 50, GRAY);
                DrawText("Endless Mode", 400-MeasureText("Endless Mode",30)/2, 310, 30, WHITE);

                DrawRectangle(275, 400, 250, 50, GRAY);
                DrawText("Setting", 400-MeasureText("Setting",30)/2, 410, 30, WHITE);

                DrawRectangle(275, 500, 250, 50, GRAY);
                DrawText("Quit", 400-MeasureText("Quit",30)/2, 510, 30, WHITE);
            EndDrawing();
        }

        void eventListener(){
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                Vector2 mousePos = GetMousePosition();
                if (mousePos.x > 275 && mousePos.x < 525){
                    if (mousePos.y > 200 && mousePos.y < 250){
                        // Normal Mode
                    }else if (mousePos.y > 300 && mousePos.y < 350){
                        // Endless Mode
                    }else if (mousePos.y > 400 && mousePos.y < 450){
                        // Setting
                    }else if (mousePos.y > 500 && mousePos.y < 550){
                        CloseWindow();
                    }
                }
            }
        }
};