#include "Asteroid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
//métodos útiles
float norma(Vector2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

Vector2 normalizar(Vector2 vec)
{
	return { vec.x / norma(vec),vec.y / norma(vec) };
}
Vector2 sumar(Vector2 v1, Vector2 v2)
{
	return { v1.x + v2.x,v1.y + v2.y };
}
Vector2 restar(Vector2 v1, Vector2 v2)
{
	return { v1.x - v2.x,v1.y - v2.y };
}
Vector2 rotarVector(Vector2 v, float angulo)
{
	double rad = (double)angulo * PI / 180.0;
	double x = cos(rad) * v.x - sin(rad) * v.y;
	double y = cos(rad) * v.y + sin(rad) * v.x;
	return { (float)x,(float)y };
}
Nave::Nave()
{
	int ancho = 800;
	int largo = 600;
	center = { ancho / 2.0f,largo / 2.0f };
	v1 = { center.x, center.y - (50 / 3) };
	v2 = { center.x - 10, center.y + (50 / 3) };
	v3 = { center.x + 10, center.y + (50 / 3) };
	direction = restar(v1, center);
	direction = normalizar(direction);
}
Nave::Nave(int ancho, int largo)
{
	center = { ancho / 2.0f,largo / 2.0f };
	v1 = { center.x, center.y - (50 / 3) };
	v2 = { center.x - 10, center.y + (50 / 3) };
	v3 = { center.x + 10, center.y + (50 / 3) };
	direction = restar(v1, center);
	direction = normalizar(direction);
}
Nave::~Nave()
{

}
void Nave::move()
{
	if (IsKeyDown(KEY_UP))
	{
		speed = 3.0f;
	}
	//Rotación

	if (IsKeyDown(KEY_LEFT))
	{
		angle = -10.0f;
		rotar(angle);
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		angle = +10.0f;
		rotar(angle);
	}

}
void Nave::Draw()
{
	DrawTriangleLines(v1, v2, v3, WHITE);
}
void Nave::colisionPantalla(Rectangle pantalla)
{
	if (center.x - radio > pantalla.width)
	{
		v1.x = v1.x - pantalla.width;
		v2.x = v2.x - pantalla.width;
		v3.x = v3.x - pantalla.width;
	}
	if (center.x + radio < 0)
	{
		v1.x = v1.x + pantalla.width;
		v2.x = v2.x + pantalla.width;
		v3.x = v3.x + pantalla.width;
	}
	if (center.y - radio < 0)
	{
		v1.y = v1.y + pantalla.height;
		v2.y = v2.y + pantalla.height;
		v3.y = v3.y + pantalla.height;
	}
	if (center.y + radio > pantalla.height)
	{
		v1.y = v1.y - pantalla.height;
		v2.y = v2.y - pantalla.height;
		v3.y = v3.y - pantalla.height;
	}
}
bool Nave::disparar()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		return true;
	}
	return false;
}
//Setters
void Nave::SetPositionInicial()
{
	int ancho = 800;
	int largo = 600;
	center = { ancho / 2.0f,largo / 2.0f };
	v1 = { center.x, center.y - (50 / 3) };
	v2 = { center.x - 10, center.y + (50 / 3) };
	v3 = { center.x + 10, center.y + (50 / 3) };
	direction = restar(v1, center);
	direction = normalizar(direction);
	speed = 0.0f;
}
void Nave::actualizarCentro()
{
	center = { (v1.x + v2.x + v3.x) / 3.0f,(v1.y + v2.y + v3.y) / 3.0f };
}
void Nave::actualizardireccion()
{
	direction = restar(v1, center);
	direction = normalizar(direction);
}
void Nave::rotar(float angle)
{
	v1 = restar(v1, center);
	v1 = rotarVector(v1, angle);
	v1 = sumar(v1, center);
	v2 = restar(v2, center);
	v2 = rotarVector(v2, angle);
	v2 = sumar(v2, center);
	v3 = restar(v3, center);
	v3 = rotarVector(v3, angle);
	v3 = sumar(v3, center);
}
void Nave::actualizar()
{
	if (speed > 3)
	{
		speed = 3.0f;
	}
	direction.x *= speed;
	direction.y *= speed;

	speed *= 0.9f;
	center = sumar(center, direction);
	v1 = sumar(v1, direction);
	v2 = sumar(v2, direction);
	v3 = sumar(v3, direction);
}
Vector2 Nave::getDireccion()
{
	return direction;
}
Vector2 Nave::getCentro()
{
	return center;
}
Asteroide::Asteroide()
{
	randomDir();
	randomPos();
}
Asteroide::~Asteroide()
{

}
void Asteroide::Draw()
{
	DrawPolyLines(center, 12, Radio, 0.0, WHITE);
}
void Asteroide::mover()
{
	center.x += direccion.x;
	center.y += direccion.y;
}
void Asteroide::setDir(Vector2 dir)
{
	direccion = dir;
}
void Asteroide::randomDir()
{
	float x = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
	float y = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
	this->direccion.x = 2 * x;
	this->direccion.y = 2 * y;
}
void Asteroide::colisionPantalla(Rectangle pantalla)
{
	if (center.x - Radio > pantalla.width)
	{
		center.x = center.x - pantalla.width;
	}
	if (center.x + Radio < 0)
	{
		center.x = center.x + pantalla.width;
	}
	if (center.y - Radio < 0)
	{
		center.y = center.y + pantalla.height;
	}
	if (center.y + Radio > pantalla.height)
	{
		center.y = center.y - pantalla.height;
	}
}
void Asteroide::randomPos()
{
	float x = 0; float y = 0;
	do
	{
		x = ((float)rand() / RAND_MAX) * 800;
		y = ((float)rand() / RAND_MAX) * 600;
	} while (CheckCollisionPointCircle({ x,y }, { 400,300 }, 60));
	center = { x,y };
}
Vector2 Asteroide::getCenter()
{
	return center;
}
float Asteroide::getRadio()
{
	return Radio;
}
void Asteroide::destroid()
{
	vida = false;
}
Proyectil::Proyectil(Vector2 pos, Vector2 dir)
{
	position = pos;
	direction = dir;
}
Proyectil::~Proyectil()
{

}
void Proyectil::update(Vector2 pos, Vector2 dir)
{
	position = pos;
	direction = dir;
}
void Proyectil::mover()
{
	position.x += direction.x * 10.0f;
	position.y += direction.y * 10.0f;
}
void Proyectil::Draw()
{
	::DrawCircle((int)position.x, (int)position.y, 3, WHITE);
}
Vector2 Proyectil::getPosition()
{
	return position;
}
void Proyectil::colision(Asteroide* A)
{
	if (CheckCollisionPointCircle(position, A->getCenter(), A->getRadio()))
	{
		A->destroid();
	}
}

AsteroidGame::AsteroidGame()
{

}
AsteroidGame::~AsteroidGame()
{
	Disparos.clear();
	Asteroides.clear();
	delete jugador;
}
void AsteroidGame::condicionesIniciales()
{
	cont_Asteroides = 0;
	Puntuacion = 0;
	vidaJugador = 3;
	jugador->SetPositionInicial();
	NuevosAsteroides();
}
//Métodos más importantes
void AsteroidGame::Initialize()
{
	condicionesIniciales();

}
void AsteroidGame::Runloop()
{
	while (!WindowShouldClose())
	{
		SetWindowTitle("Asteroid");
		if (vidaJugador > 0)
		{
			ProcessInput();
			UpdateGame();
			GenerateOutput();
		}
		else
		{
			condicionesIniciales();
		}
	}
	SetWindowTitle("Juego - Exploracion");
}
//Métodos del loop de juego
void AsteroidGame::ProcessInput()
{
	jugador->move();
	disparo = jugador->disparar();
	if (disparo)
	{
		Proyectil* PUM = new Proyectil(jugador->getCentro(), jugador->getDireccion());
		Disparos.push_back(PUM);
	}
	if (cont_Asteroides == 0)
	{
		NuevosAsteroides();
		jugador->SetPositionInicial();
		vidaJugador++;
	}
}
void AsteroidGame::UpdateGame()
{
	for (auto A : Asteroides)
	{
		A->mover();
		A->colisionPantalla(Pantalla);
	}
	for (auto P : Disparos)
	{
		P->mover();
	}
	ColisionDispAsteroide();
	Disparos.erase(std::remove_if(Disparos.begin(), Disparos.end(), [](Proyectil* d) {
		return !d->vive() || d->getPosition().x < 0 || d->getPosition().x > 800 || d->getPosition().y < 0 || d->getPosition().y > 600;
		}), Disparos.end());
	for (auto it = Asteroides.begin(); it != Asteroides.end();) {
		if (!(*it)->vive()) {
			delete (*it);
			it = Asteroides.erase(it);
		}
		else {
			++it;
		}
	}
	jugador->colisionPantalla(Pantalla);
	colisionNave();
	jugador->actualizar();
	jugador->actualizarCentro();
	jugador->actualizardireccion();
}
void AsteroidGame::GenerateOutput()
{
	BeginDrawing();
	ClearBackground(BLACK);
	jugador->Draw();
	for (auto P : Disparos)
	{
		P->Draw();
	}
	for (auto A : Asteroides)
	{
		A->Draw();
	}
	std::string texto = "Puntos: " + std::to_string(Puntuacion);
	DrawText(texto.c_str(), 10, 10, 20, WHITE);
	std::string vidas = "Vidas: " + std::to_string(vidaJugador);
	DrawText(vidas.c_str(), 700, 10, 20, WHITE);
	EndDrawing();
}
void AsteroidGame::ColisionDispAsteroide()
{
	for (auto P : Disparos)
	{
		for (auto A : Asteroides)
		{
			if (CheckCollisionPointCircle(P->getPosition(), A->getCenter(), A->getRadio()))
			{
				P->destroid();
				A->destroid();
				Puntuacion += 10;
				cont_Asteroides--;
			}
		}
	}
}
void AsteroidGame::colisionNave()
{
	for (auto A : Asteroides)
	{
		if (CheckCollisionCircles(A->getCenter(), A->getRadio(), jugador->getCentro(), 50 / 3))
		{
			vidaJugador--;
			jugador->SetPositionInicial();
		}
	}
}
void AsteroidGame::NuevosAsteroides()
{
	Asteroides.clear();
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Asteroide* Ast = new Asteroide();
		Asteroides.push_back(Ast);
		cont_Asteroides++;
	}
}
void AsteroidGame::game()
{
	Initialize();
	Runloop();
}