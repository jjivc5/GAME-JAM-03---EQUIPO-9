#include "Snake.h"

void GameRunSnake::game()
{
    int w = 2 * offset + cellSize * cellCount;
    int h = 2 * offset + cellSize * cellCount;

    int monitorWidth = GetMonitorWidth(0);
    int monitorHeight = GetMonitorHeight(0);

  

    // Calcular la posición para centrar la ventana
    int windowPosX = (monitorWidth - w) / 2;
    int windowPosY = (monitorHeight - h) / 2;

    SetWindowSize(w, h);
    SetWindowPosition(windowPosX, windowPosY);
 
    SetWindowTitle("Snake");


    GameSnake game = GameSnake();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        if (eventTriggered(0.2))
        {
            game.Update();
        }
        //movimiento por teclas  
        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
        {
            //0=x -1=y por lo que al su 1 va para abajo -1 para arriba
            game.snake.direction = { 0,-1 };
            game.running = true;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
        {
            game.snake.direction = { 0,1 };
            game.running = true;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
        {
            game.snake.direction = { -1,0 };
            game.running = true;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
        {
            game.snake.direction = { 1,0 };
            game.running = true;
        }

        //Drawing
        ClearBackground(beige);
        DrawRectangleLinesEx(Rectangle{ (float)offset - 5,(float)offset - 5,(float)cellSize * cellCount + 10,(float)cellSize * cellCount + 10 }, 5, orange);
        DrawText("Snake", offset - 5, 20, 30, orange);
        DrawText(TextFormat("%i", game.score), offset + 480, 20, 30, orange);
        game.Draw();

        EndDrawing();
    }


    SetWindowSize(800, 600);
    SetWindowPosition((monitorWidth - 800)/2, (monitorHeight - 600) / 2);
    SetWindowTitle("Juego - Exploracion");
}