#pragma once
#include "raylib.h"
#include "Pong.h"
#include "Snake.h"
#include "Asteroid.h"
class Pong;
class Snake;
class Food;
class GameSnake;
class GameRunSnake;

int menu();

class Submenu
{
private:
	bool mostrarSubMenu;
	int opcionSeleccionada;
public:
	Submenu();
	void setSubMenu(bool setSm);
	void setOpcSelec(int setOs);
	bool getSubMenu();
	int getOpcSelec();
	void printMenu(Pong* game, const char* mensaje);
	void printMenu(GameRunSnake* game, const char* mensaje);
	void printOpc();
	void printMenu(AsteroidGame* game, const char* mensaje);

};