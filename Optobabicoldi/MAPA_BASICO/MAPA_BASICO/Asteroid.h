#pragma once
#include <vector>
#include "raylib.h"
class Nave
{
private:
	//Texture2D texture;
	//Rectangle Rec;
	//Vertices
public:
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;
	Vector2 center;
	Vector2 direction;
	float radio = 50 / 3;
	float speed = 0.0f;
	//Ángulo de rotación
	float angle = 0.0f;
	int life = 3;
	Nave();
	//Nave(float posX, float posY);
	Nave(int ancho, int largo);
	~Nave();
	void actualizar();
	void actualizardireccion();
	void actualizarCentro();
	void move();
	void Draw();
	void rotar(float angle);
	void colisionPantalla(Rectangle pantalla);
	bool disparar();
	//Setters
	void SetPositionInicial();
	//void SetRotation();
	//void SetSpeed();
	//Getters
	Vector2 getDireccion();
	Vector2 getCentro();
};
class Asteroide
{
	Vector2 direccion = { 1.0f,1.0f };
	float Radio = 40.0f;
	Vector2 center = { 800 / 2, 600 / 2 };
	int size = 12;
	bool vida = true;
public:
	Asteroide();
	~Asteroide();
	void Draw();
	void randomDir();
	void mover();
	void setDir(Vector2 dir);
	void colisionPantalla(Rectangle pantalla);
	void randomPos();
	Vector2 getCenter();
	float getRadio();
	void destroid();
	bool vive() { return vida; };
	// inicializar();
};
class Proyectil
{
public:
	Proyectil(Vector2 pos, Vector2 dir);
	~Proyectil();
	void update(Vector2 pos, Vector2 dir);
	void mover();
	void Draw();
	//bool colision();
	void colision(Asteroide* A);
	Vector2 getPosition();
	void destroid() { vida = false; };
	bool vive() { return vida; };
private:
	Vector2 position;
	Vector2 direction;
	float speed = 10.0f;
	bool vida = true;
};
class AsteroidGame
{
public:
	AsteroidGame();
	~AsteroidGame();
	void Initialize();
	void Runloop();
	void game();
private:
	//Atributos
	//float radio = 50 / 3;
	Rectangle Pantalla = { 0,0,800,600 };
	Nave* jugador = new Nave(800, 600);
	std::vector<Proyectil*> Disparos;
	std::vector<Asteroide*> Asteroides;
	//Asteroide* A = new Asteroide();
	int cont_Asteroides = 0;
	int Puntuacion = 0;
	int vidaJugador = 3;
	bool disparo;
	bool dibujar = true;
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void ColisionDispAsteroide();
	void colisionNave();
	void condicionesIniciales();
	void NuevosAsteroides();
};


