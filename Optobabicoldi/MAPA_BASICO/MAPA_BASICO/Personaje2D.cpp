#include "Personaje2D.h"
// 123
void Personaje2D::Draw(float x, float y, Color tint, float scale, float rotation)
{
	DrawTextureEx(texture, Vector2{ x = posX, y = posY }, rotation, scale, tint);
}

void Personaje2D::inicializarTexturas(const char* filename)
{
    texture = LoadTexture(filename);
}
float Personaje2D::width() const
{
    return scale * texture.width;
}

float Personaje2D::height() const
{
	return scale * texture.height;
}

void Personaje2D::setXwalk(int s)
{ 
	posX = posX + s * walk; 
}

void Personaje2D::setYwalk(int s)
{
	posY = posY + s * walk; 
}

Rectangle Personaje2D::getRect()
{
	return Rectangle{ posX, posY, width(), height() };
}


Rectangle Personaje2D::getRectAlrededor()
{
    double scale_factor = 1.25;
    double scaled_width = scale_factor * width();
    double scaled_height = scale_factor* height();

    // Calcular la diferencia de escala
    double width_diff = scaled_width - width();
    double height_diff = scaled_height - height();

    // Calcular las nuevas coordenadas de la esquina superior izquierda
    float new_x = posX - width_diff / 2;
    float new_y = posY - height_diff / 2;

    return Rectangle{ new_x, new_y, static_cast<float>(scaled_width), static_cast<float>(scaled_height) };
}

void Personaje2D::movimientoJugador()
{
    if (IsKeyDown(KEY_W))
    {
        setYwalk(-1);
    }
    if (IsKeyDown(KEY_S))
    {
        setYwalk(1);
    }
    if (IsKeyDown(KEY_A))
    {
        setXwalk(-2);
    }
    if (IsKeyDown(KEY_D))
    {
        setXwalk(2);
    }
}

//
//void Personaje2D::colisionObjeto(Map* mp)
//{
//
//    if (CheckCollisionRecs(getRect(), mp->getRectUp())) {
//        if (IsKeyDown(KEY_W))
//        {
//            setYwalk(1);
//        }
//    }
//
//    if (CheckCollisionRecs(getRect(), mp->getRectLeft())) {
//
//        if (IsKeyDown(KEY_A))
//        {
//            setXwalk(2);
//        }
//    }
//
//    if (CheckCollisionRecs(getRect(), mp->getRectRight())) {
//
//        if (IsKeyDown(KEY_D))
//        {
//            setXwalk(-2);
//        }
//    }
//
//    if (CheckCollisionRecs(getRect(), mp->getRectDown())) {
//
//        if (IsKeyDown(KEY_S))
//        {
//            setYwalk(-1);
//        }
//    }
//}

void Personaje2D::colisionObjeto(Personaje2D* npc)
{
    if (CheckCollisionRecs(getRect(), npc->getRect()))
    {
        if (IsKeyDown(KEY_W))
        {
            setYwalk(1);
        }
        if (IsKeyDown(KEY_S))
        {
            setYwalk(-1);
        }
        if (IsKeyDown(KEY_A))
        {
            setXwalk(2);
        }
        if (IsKeyDown(KEY_D))
        {
            setXwalk(-2);
        }
    }
}


void Personaje2D::colisionRec(Rectangle Rec)
{
    if (CheckCollisionRecs(getRect(), Rec))
    {
       /* if (posX + width() > Rec.x)
        {
            posX = Rec.x - width();
        }
        if (posX < Rec.x + Rec.width)
        {
            posX = Rec.x + Rec.width;
        }
        if (posY + height() > Rec.y)
        {
            posY = Rec.y - height();
        }
        if (posY < Rec.y + Rec.height)
        {
            posY = Rec.y + Rec.height;
        }*/

        if (IsKeyDown(KEY_W))
        {
            setYwalk(1);
        }
        if (IsKeyDown(KEY_S))
        {
            setYwalk(-1);
        }
        if (IsKeyDown(KEY_A))
        {
            setXwalk(2);
        }
        if (IsKeyDown(KEY_D))
        {
            setXwalk(-2);
        }
    }
}

void Personaje2D::colisionMapa(Matriz* posiciones, float base, float altura)
{
    int N = posiciones->getFilas();
    int M = posiciones->getColumnas();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (posiciones->getValor(i, j) == 1)
            {
                float x = j * base;
                float y = i * altura;
                Rectangle Zona = { x,y,base,altura };
                colisionRec(Zona);
            }
        }
    }
}