#pragma once
#include "raylib.h"
#include <string>

class Ball
{
public:
	float x;
	float y;
	float speedX, speedY;
	float radius;
	void Draw() {
		DrawCircle((int)x, (int)y, radius, WHITE);
	}
};

class Paddle
{
public:
	float x, y;
	float speed;
	float width, height;

	Rectangle GetRect() {
		return Rectangle{ x - width / 2, y - height / 2, 10, 100 };
	}

	void Draw() {
		DrawRectangleRec(GetRect(), WHITE);
	}
};

class Pong
{
public:
	void game();
};

