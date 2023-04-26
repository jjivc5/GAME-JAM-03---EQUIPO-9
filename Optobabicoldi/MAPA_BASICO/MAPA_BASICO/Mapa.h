#pragma once
#include "Personaje.h"
#include "Matriz.h"
#include <iostream>
class Loseta
{
private:
	Texture2D texture;
	float posX;
	float posY;
	int width;
	int height;
public:
	Loseta();
	~Loseta();
    Loseta(const char* filename, int x, int y, int w, int h);
	Loseta(float x, float y, int w, int h);
	void initialize(const char* filename, int x, int y, int w, int h);
	void setPosition(float x, float y);
    void Draw(); 
	void DrawRec();
	Texture2D getTexture() { return texture; };
	void UpdatePosition(float x, float y);

	Rectangle getRectangle();
};
class Mapa
{
	Loseta* textura = new Loseta;
	Matriz* tablero = new Matriz();
	int width;
	int height;
public:
	Mapa();
	Mapa(const char* filename, int w,int h, Matriz* matriz);
	Mapa(const char* filename, int w, int h);
	~Mapa();
	void initializeMap(const char* filename, int w, int h, Matriz* matriz);
	void DrawFondo();
	void Draw();

};
