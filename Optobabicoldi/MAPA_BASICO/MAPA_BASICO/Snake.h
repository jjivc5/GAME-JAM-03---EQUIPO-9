#pragma once
#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>



class Snake
{
public:
    Color orange = { 255,255,255,255 };
    Color beige = { 0,0,0,255 };

    int cellSize = 25;
   // int cellSize = 30;
    int offset = 70;

    double lastUpdateTime = 0;

    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
    {
        for (unsigned int i = 0; i < deque.size(); i++)
        {
            if (Vector2Equals(deque[i], element))
            {
                return true;
            }
        }

        return false;
    };

    //verifica cada cuanto se actualiza la serpiente
    bool eventTriggered(double inteval)
    {
        double currentTime = GetTime();
        if (currentTime - lastUpdateTime >= inteval)
        {
            lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }
    std::deque<Vector2> body = { Vector2{6,9},Vector2{5,9},Vector2{4,9} };
    Vector2 direction = { 1,0 };

    bool addSegment = false;


    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++) {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{ offset + x * cellSize , offset + y * cellSize, (float)cellSize - 1,(float)cellSize - 1 };
            DrawRectangleRounded(segment, 0.8, 6, orange);
        }
    }
    //mover el cuerpo
    void Update()
    {
        //agrega un segmento al frente
        body.push_front(Vector2Add(body[0], direction));

        if (addSegment == true)
        {
            //retorna a false para que se siga moviendo
            addSegment = false;
        }
        else
        {
            //elimina el ultimo elemento del deque
            body.pop_back();

        }
    }
    void Reset()
    {
        //resetea la snake y espera que aprieta una tecla para reiniciar
        body = { Vector2{6,9}, Vector2{5,9},Vector2{4,9} };
        direction = { 1,0 };

    }
};

class Food
{
public:
    Color orange = { 255,255,255,255 };
    Color beige = { 0,0,0,255 };

    int cellSize = 25;
    // int cellSize = 30;
    int cellCount = 20;
    int offset = 70;

    double lastUpdateTime = 0;

    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
    {
        for (unsigned int i = 0; i < deque.size(); i++)
        {
            if (Vector2Equals(deque[i], element))
            {
                return true;
            }
        }

        return false;
    };

    //verifica cada cuanto se actualiza la serpiente
    bool eventTriggered(double inteval)
    {
        double currentTime = GetTime();
        if (currentTime - lastUpdateTime >= inteval)
        {
            lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }
    Vector2 position;
    //se necesita para cargar la imagen
    Texture2D texture;
    //constructor
    Food(std::deque<Vector2>snakeBody) {
        Image imagen = LoadImage("texturas/snakecoin.png");
        texture = LoadTextureFromImage(imagen);
        UnloadImage(imagen);
        position = GenerateRandomPos(snakeBody);
    }
    //destructor
    ~Food() {
        UnloadTexture(texture);
    }
    //dibuja la comida (rata)
    void Draw() {
        // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize,cellSize, orange);
        DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
    }

    //Genera la celda para la food
    Vector2 GenereteRandomCell()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{ x,y };
    }
    //posiciona la comida en el eje x, y o en este caso celdas/ comprueba que no se aparezca encima de la snake
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody) {

        Vector2 position = GenereteRandomCell();
        while (ElementInDeque(position, snakeBody))
        {
            position = GenereteRandomCell();
        }
        return position;
    }

};

class GameSnake
{
public:
    Color orange = { 255,255,255,255 };
    Color beige = { 0,0,0,255 };

   
    int cellCount = 20;
    double lastUpdateTime = 0;

    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
    {
        for (unsigned int i = 0; i < deque.size(); i++)
        {
            if (Vector2Equals(deque[i], element))
            {
                return true;
            }
        }

        return false;
    };

    //verifica cada cuanto se actualiza la serpiente
    bool eventTriggered(double inteval)
    {
        double currentTime = GetTime();
        if (currentTime - lastUpdateTime >= inteval)
        {
            lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;


    void Draw()
    {
        snake.Draw();
        food.Draw();
    }
    void Update()
    {
        if (running)
        {
            snake.Update();
            CheckCollisionWhithFood();
            ChecCollisionWithEdges();
            ChecCollisionWithTail();
        }
    }

    void CheckCollisionWhithFood()
    {
        //si la snake choca con el food agrega otro food y hace verdadero el addSegment para que crezca la snake
        if (Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake.body);
            snake.addSegment = true;
            score++;

        }
    }

    void ChecCollisionWithEdges()
    {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1)
        {
            GameOver();
        }
    }
    void GameOver()
    {
        //crea un metodo en la clase snake para que se reinicie
        snake.Reset();
        //crea la comida de nuevo
        food.position = food.GenerateRandomPos(snake.body);
        running = false;
        score = 0;

    }
    //si la cabeza choca con el cuerpo
    void ChecCollisionWithTail()
    {
        std::deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (ElementInDeque(snake.body[0], headlessBody))
        {
            GameOver();
        }
    }
};
class GameRunSnake
{
public:
    Color orange = { 255,255,255,255 };
    Color beige = { 0,0,0,255 };

    int cellSize = 25;
    // int cellSize = 30;
    int cellCount = 20;
    int offset = 70;

    double lastUpdateTime = 0;

    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
    {
        for (unsigned int i = 0; i < deque.size(); i++)
        {
            if (Vector2Equals(deque[i], element))
            {
                return true;
            }
        }

        return false;
    };

    //verifica cada cuanto se actualiza la serpiente
    bool eventTriggered(double inteval)
    {
        double currentTime = GetTime();
        if (currentTime - lastUpdateTime >= inteval)
        {
            lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }
    void game();
};




