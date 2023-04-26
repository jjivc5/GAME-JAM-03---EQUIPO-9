#pragma once
#include "Funciones.h"

class PantallaInicial
{
private:
	//Intro
	int screenWidth = 800;
	int screenHeight = 600;
	int logoPositionX = screenWidth / 2 - 128;
	int logoPositionY = screenHeight / 2 - 128;

	int framesCounter = 0;
	int lettersCount = 0;

	int topSideRecWidth = 16;
	int leftSideRecHeight = 16;

	int bottomSideRecWidth = 16;
	int rightSideRecHeight = 16;

	int state = 0;                  // Tracking animation states (State Machine)
	float alpha = 1.0f;             // Useful for fading
public:
	void LogicCounter();

};