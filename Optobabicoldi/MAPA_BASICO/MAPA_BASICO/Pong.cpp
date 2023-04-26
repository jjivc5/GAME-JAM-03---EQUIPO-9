#include "Pong.h"
#include <iostream>

const char* winnerText = nullptr;
void Pong::game()
{
	Ball ball;
	ball.x = GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 5;
	ball.speedX = 300;
	ball.speedY = 300;

	Paddle leftPaddle;
	leftPaddle.x = 50;
	leftPaddle.y = GetRenderHeight() / 2;
	leftPaddle.height = 100;
	leftPaddle.width = 10;
	leftPaddle.speed = 500;

	Paddle rightPaddle;
	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetRenderHeight() / 2;
	rightPaddle.height = 100;
	rightPaddle.width = 10;
	rightPaddle.speed = 500;

	int ScoreIZQ = 0;
	int ScoreDER = 0;
	/*
	BeginDrawing();
	ClearBackground(BLACK);
	EndDrawing();
	*/
	while (!WindowShouldClose())
	{

	ball.x += ball.speedX * GetFrameTime();
	ball.y += ball.speedY * GetFrameTime();
	//Movimiento de la pelotita
	if (ball.y < 0) {
		ball.y = 0;
		ball.speedY *= -1;
	}
	if (ball.y > GetScreenHeight()) {
		ball.y = GetScreenHeight();
		ball.speedY *= -1;
	}
	//Mover la primera paleta
	if (IsKeyDown(KEY_W))
	{
		leftPaddle.y -= leftPaddle.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		leftPaddle.y += leftPaddle.speed * GetFrameTime();
	}
	//Mover la otra pelota
	if (IsKeyDown(KEY_UP))
	{
		rightPaddle.y -= rightPaddle.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_DOWN))
	{
		rightPaddle.y += rightPaddle.speed * GetFrameTime();
	}

	if (IsKeyDown(KEY_ESCAPE))
	{
		exit(0);
	}
	//Crear colisión
	if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, rightPaddle.GetRect())) {
		if (ball.speedX > 0) {
			ball.speedX *= -1.1f;
			ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * ball.speedX;
		}
	}
	if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, leftPaddle.GetRect())) {
		if (ball.speedX < 0) {
			ball.speedX *= -1.1f;
			ball.speedY = -1 * (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
		}
	}
	//Texto de Victoria
	if (ball.x < 0) {
		winnerText = "Has Perdido";
	}
	if (ball.x > GetScreenWidth()) {
		winnerText = "Has Ganado";
	}
	//Resetear el juego si se gana
	if (winnerText && (IsKeyPressed(KEY_SPACE)))
	{
		if (ball.x < 0) {
			ScoreDER++;
		}
		if (ball.x > GetScreenWidth()) {
			ScoreIZQ++;
		}
		ball.x = GetScreenWidth() / 2.0f;
		ball.y = GetScreenHeight() / 2.0f;
		ball.speedX = 300;
		ball.speedY = 300;
		winnerText = nullptr;
	}
	std::string textoIZQ = std::to_string(ScoreIZQ);
	std::string textoDER = std::to_string(ScoreDER);
	BeginDrawing();
	SetWindowTitle("Pong");
	ClearBackground(BLACK);
	//Dibujar Fondo y puntuación
	DrawText(textoIZQ.c_str(), 200, 20, 40, YELLOW);
	DrawText(textoDER.c_str(), 600, 20, 40, YELLOW);
	Vector2 inicio = { GetScreenWidth() / 2, 0 };
	Vector2 fin = { GetScreenWidth() / 2, GetScreenHeight() };
	DrawLineEx(inicio, fin, 2, WHITE);
	//DrawCircle((int) ball.x, (int) ball.y, ball.radius , WHITE);
	ball.Draw();
	leftPaddle.Draw();
	rightPaddle.Draw();
	//DrawRectangle(50, GetScreenHeight() / 2-50,10,100,WHITE);
	//DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
	if (winnerText) {
		int widthtext = MeasureText(winnerText, 60);
		DrawText(winnerText, GetScreenWidth() / 2 - widthtext / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
	}
	//DrawFPS(0, 0);
	EndDrawing();

	}

	
	winnerText = nullptr;
	SetWindowTitle("Juego - Exploracion");
}