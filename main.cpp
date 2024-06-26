#include "Spawner.cpp"
#include "TowerManager.cpp"
#include "raylib.h"
#include "player.h"
#include "MainMenu.cpp"
#include "scoreMenu.cpp"

void saveScore(int score, int wave) {
    std::ofstream outFile("scores.txt", std::ios_base::app);
    if (outFile.is_open()) {
        outFile << "player " << score << " " << wave << "\n";
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing\n";
    }
}

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(300);

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
    int seconds = 0;
    int minutes = 0;
    int count = 0;
    int score = 0;
    bool running = true;

    MainMenu mainMenu;
    scoreMenu ScoreMenu("scores.txt");
    
    Music music = LoadMusicStream("music/MainGame.mp3");
    bool musicPlay = false;
    
    // Main game loop
    while (!WindowShouldClose() /* && running */){
        if (!mainMenu.scoreMenu && !mainMenu.game) {
            mainMenu.drawMenu();
            mainMenu.eventListener();
        }
        else if (mainMenu.game && running){
            BeginDrawing();
            ClearBackground(BLACK);

            if (!musicPlay){
                CloseAudioDevice();
                InitAudioDevice();
                PlayMusicStream(music);
                SetMusicVolume(music, 0.5f);
                musicPlay = true;
            }
            
            UpdateMusicStream(music);

            DrawTexture(background, 0, 0, WHITE);

            int num = spawner.update();
            towerManager.gainMoney(num);
            score += num;

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
            for (int i = 0; i < 24; i++)
            {
                if (towerManager.towers[i].x > 0){
                    if (towerManager.towers[i].hit){
                        DrawTexture(towerManager.towers[i].texture, towerManager.towers[i].x, towerManager.towers[i].y, GRAY);
                    }
                    else{
                        DrawTexture(towerManager.towers[i].texture, towerManager.towers[i].x, towerManager.towers[i].y, WHITE);
                    }                
                }
            }

            DrawText(("Vague: " + std::to_string(spawner.wave)).c_str(), 10, 10, 20, WHITE);

            DrawText(("Argent: " + std::to_string(towerManager.money)).c_str(), 250, 10, 20, WHITE);

            DrawText(("Vie: " + std::to_string(spawner.playerHP)).c_str(), 450, 10, 20, WHITE);

            if (minutes <= 0){
                DrawText(("Time: " + std::to_string(seconds)).c_str(), 650, 10, 20, WHITE);
            }
            else{
                if (seconds < 10){
                    DrawText(("Time: " + std::to_string(minutes) + ":0" + std::to_string(seconds)).c_str(), 650, 10, 20, WHITE);
                }
                else{
                    DrawText(("Time: " + std::to_string(minutes) + ":" + std::to_string(seconds)).c_str(), 650, 10, 20, WHITE);
                }
            }

            if (count >= 300){
                count = 0;
                seconds++;
            }
            if (seconds == 60){
                seconds = 0;
                minutes++;
            }

            count++;

            EndDrawing();

            if (spawner.playerHP <= 0){
                saveScore(score, spawner.wave);
                running = false;
            }
        }
        else if (!running){
            BeginDrawing();
            ClearBackground(BLACK);

            DrawText(("Score: " + std::to_string(score)).c_str(), 10, 10, 20, WHITE);
            if (minutes <= 0){
                DrawText(("Time: " + std::to_string(seconds)).c_str(), 10, 60, 20, WHITE);
            }
            else{
                if (seconds < 10){
                    DrawText(("Time: " + std::to_string(minutes) + ":0" + std::to_string(seconds)).c_str(), 10, 60, 20, WHITE);
                }
                else{
                    DrawText(("Time: " + std::to_string(minutes) + ":" + std::to_string(seconds)).c_str(), 10, 60, 20, WHITE);
                }
            }
            DrawText(("Wave: " + std::to_string(spawner.wave)).c_str(), 10, 110, 20, WHITE);

            DrawText("Press Enter to return to the main menu", 10, 250, 20, RED);
            
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)){
                running = true;
                mainMenu.game = false;
                spawner = Spawner(path, 0, 50);
                towerManager = TowerManager();
                score = 0;
                seconds = 0;
                minutes = 0;
                count = 0;

            }
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
    
    
    return 0;
}