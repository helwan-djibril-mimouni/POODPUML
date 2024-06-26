#include "raylib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct ScoreEntry {
    std::string pseudo;
    int score;
    int vague;
};

class scoreMenu {
public:
    bool menulaunch = true;
    scoreMenu(const std::string& filename) {
        loadScores(filename);
    }

    void loadScores(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            ScoreEntry entry;
            iss >> entry.pseudo >> entry.score >> entry.vague;
            if (!iss.fail()) {
                scores.push_back(entry);
            }
        }
    }

    void draw() {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(275, 500, 250, 50, GRAY);
        DrawText("Return", 400 - MeasureText("Return", 30) / 2, 510, 30, WHITE);

        DrawText("Hall of Fame", 400 - MeasureText("Hall of Fame", 50) / 2, 30, 50, RED);
        int y = 100;

        const int pseudoColumnWidth = 150;
        const int scoreColumnWidth = 150;
        const int vagueColumnWidth = 100;

        const int pseudoColumnX = 100;
        const int scoreColumnX = pseudoColumnX + pseudoColumnWidth;
        const int vagueColumnX = scoreColumnX + scoreColumnWidth;

        DrawText("Pseudo", pseudoColumnX, y, 20, BLUE);
        DrawText("Score", scoreColumnX, y, 20, BLUE);
        DrawText("Vague", vagueColumnX, y, 20, BLUE);
        y += 30; 

        for (const auto& entry : scores) {
            DrawText(entry.pseudo.c_str(), pseudoColumnX, y, 20, WHITE); 
            DrawText(TextFormat("%d", entry.score), scoreColumnX, y, 20, WHITE); 
            DrawText(TextFormat("%d", entry.vague), vagueColumnX, y, 20, WHITE); 
            y += 30; 
        }
        EndDrawing();
    }

    void eventListener(){
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (mousePos.x > 275 && mousePos.x < 525 && mousePos.y > 500 && mousePos.y < 550) {
                menulaunch = false;
            }
        }
    
    }

private:
    std::vector<ScoreEntry> scores;
};
