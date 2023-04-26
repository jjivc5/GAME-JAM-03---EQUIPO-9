#include "Personaje.h"
Personaje::Personaje(Vector2 pos, float Rad)
{
	posicion = pos; Radio = (float) Rad;
}
Personaje::~Personaje()
{

}
void Personaje::mover()
{
	if (IsKeyDown(KEY_W)) {
		posicion.y -= 2.0f;
	}
	if (IsKeyDown(KEY_S)) {
		posicion.y += 2.0f;
	}
	if (IsKeyDown(KEY_A)) {
		posicion.x -= 2.0f;
	}
	if (IsKeyDown(KEY_D)) {
		posicion.x += 2.0f;
	}
}
void Personaje::setPosition(Vector2 posActualizada)
{
	posicion = posActualizada;
}
Vector2 Personaje::getPosition()
{
	return posicion;
}
float Personaje::getRadio()
{
	return Radio;
}
void Personaje::Draw()
{
	//Se puede cambiar el color
	DrawCircleV(posicion, Radio, BLUE);
}