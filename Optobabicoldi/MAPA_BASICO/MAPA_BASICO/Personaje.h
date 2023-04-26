#pragma once
#include "raylib.h"
#include "Funciones.h"
// 1
class Personaje
{
private:
	float Radio;
	Vector2 posicion;
	//Se puede agregar el sprite de la textura
public:
	Personaje(Vector2 pos, float Rad);
	~Personaje();
	void mover();
	void setPosition(Vector2 posActualizada);
	Vector2 getPosition();
	float getRadio();
	void Draw();
};

