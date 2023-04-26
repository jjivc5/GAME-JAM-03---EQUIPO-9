#include "Personaje.h"
#include "Mapa.h"
#include "Matriz.h"
#include "Personaje2D.h"
#include "Menu.h"
#include "Pong.h"
#include "PantallaInicial.h"
#include "Snake.h"
#include "Asteroid.h"


class Game
{
private:
	
	//Atributos de la pantalla
	int screenWidth = 800;
	int screenHeight = 600;
	Rectangle Pantalla = { 0.0f,0.0f,(float) screenWidth, (float) screenHeight };
	//Personaje
	float radio = 20.0f;
	
	//Mapa
	Loseta* Fondo = new Loseta();
	Matriz* matriz = new Matriz(3,4,0);
	Matriz* piedritas = new Matriz(30,40,0);
	Mapa* Mapa1 = new Mapa();
	Mapa* Mapa2 = new Mapa();
	Personaje2D* PJ2D = new Personaje2D(30.0, 30.0, 0.15);
	Personaje2D* NPC = new Personaje2D(180, screenHeight-110, 0.5);
	Personaje2D* NPC2 = new Personaje2D(screenWidth-80, 200, 0.5);
	Personaje2D* NPC3 = new Personaje2D(screenWidth/2+35, 150, 1.2);
	Submenu* sub = new Submenu();
	Pong* pong = new Pong();
	GameRunSnake* snake = new GameRunSnake();
	AsteroidGame* asteroid = new AsteroidGame();
	Music cancion;
	//funciones para ayudar el loop del juego
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	//Función extra para evitar la colisión con el borde
	//void limiteMapa(/*Personaje P1*/);
public:
	Game();
	~Game();
	//Inicializar el juego
	void Initialise();
	//Correr el loop del juego
	void RunLoop();
	//Cerrar
	void Shutdown();

	//Idea falopa mía
	void main();
};

