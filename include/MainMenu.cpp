#include "raylib.h"

class MainMenu {
    private:
        float volume = 0.5f; // Volume level from 0.0 to 1.0
        Music music; // Music stream

    public:
        bool scoreMenu = false;
        MainMenu() {
            // Initialize the music stream
            InitAudioDevice();
            music = LoadMusicStream("1.03 Title Screen.mp3"); // Replace with your music file path
            PlayMusicStream(music);
            SetMusicVolume(music, volume);
        }

        ~MainMenu() {
            // Unload the music stream and close the audio device
            UnloadMusicStream(music);
            CloseAudioDevice();
        }

        void drawMenu() {
            BeginDrawing();
                ClearBackground(BLACK);
                DrawText("Tower Defense", 400 - MeasureText("Tower Defense", 50) / 2, 30, 50, WHITE);

                DrawRectangle(275, 200, 250, 50, GRAY);
                DrawText("Normal Mode", 400 - MeasureText("Normal Mode", 30) / 2, 210, 30, WHITE);

                DrawRectangle(275, 300, 250, 50, GRAY);
                DrawText("Score", 400 - MeasureText("Score", 30) / 2, 310, 30, WHITE);

                DrawText("Volume", 400 - MeasureText("Volume", 30) / 2, 400, 30, WHITE);
                DrawRectangle(275, 440, 250, 20, GRAY);
                DrawRectangle(275 + (int)(volume * 250), 435, 10, 30, WHITE); // Volume slider

                DrawRectangle(275, 500, 250, 50, GRAY);
                DrawText("Quit", 400 - MeasureText("Quit", 30) / 2, 510, 30, WHITE);

                DrawText("Made by: Albin Fabijan, Guillaume Bomben, Helwan-Djibril Mimouni", 10, 580, 20, WHITE);
            EndDrawing();
        }

        void eventListener() {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (mousePos.x > 275 && mousePos.x < 525) {
                    if (mousePos.y > 200 && mousePos.y < 250) {
                        // Normal Mode
                    } else if (mousePos.y > 300 && mousePos.y < 350) {
                        scoreMenu = true;
                    } else if (mousePos.y > 500 && mousePos.y < 550) {
                        CloseWindow();
                    }
                }
            }
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (mousePos.x > 275 && mousePos.x < 525 && mousePos.y > 435 && mousePos.y < 465) {
                    volume = (mousePos.x - 275) / 250.0f;
                    if (volume < 0.0f) volume = 0.0f;
                    if (volume > 1.0f) volume = 1.0f;
                    SetMusicVolume(music, volume);
                }
            }

            UpdateMusicStream(music); // Update the music stream
        }
};
