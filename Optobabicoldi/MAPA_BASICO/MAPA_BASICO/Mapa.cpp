#include "Mapa.h"
Mapa::Mapa()
{
}
Mapa::Mapa(const char* filename, int w, int h)
{
    //para crear un fondo
    width = w; height = h;
    textura->initialize(filename,0,0,width,height);
}
Mapa::Mapa(const char* filename, int w, int h, Matriz* matriz)
{
    //para crear un fondo
    width = w; height = h;
    textura->initialize(filename, 0, 0, width, height);
    tablero = matriz;
}
Mapa::~Mapa() 
{
    UnloadTexture(textura->getTexture());
    delete textura;
    //delete tablero;
}
void Mapa::DrawFondo()
{
    textura->Draw();
}
void Mapa::Draw()
{
  /* for (int i = 0; i < tablero.size(); i++) {
        for (int j = 0; j < tablero[i].size(); j++) {
            if (tablero[i][j] == 1)
            {
                float x = i*width;
                float y = j*height;
                textura->setPosition(x,y);
                textura->Draw();
            }   
        }
    }
 */ 
    /*int i = 0; int j = 0;
    for (auto fila : tablero) {
        for (auto valor : fila) {
            // cambiar la posición de inicio
            if (valor == 1) {
                float x = i * width;
                float y = j * height;
                textura->setPosition(x, y);
                textura->Draw();
            }
            j++;
        }
        i++;
    }*/
    for (int i = 0; i < tablero->getFilas();i++) {
        for (int j=0;j< tablero->getColumnas();j++) {
            // cambiar la posición de inicio
            if (tablero->getValor(i,j)==1) {
                float x = j * width;
                float y = i * height;
                textura->setPosition(x, y);
                textura->DrawRec();
            }
        }

    }
}
void Mapa::initializeMap(const char* filename, int w, int h, Matriz* matriz)
{
    width = w; height = h;
    textura->initialize(filename, 0, 0, width, height);
    tablero = matriz;
}
Loseta::Loseta() 
{
}
Loseta::~Loseta() {}
Loseta::Loseta(const char* filename, int x, int y, int w, int h)
{
    texture = LoadTexture(filename);
    posX = (float)x;
    posY = (float)y;
    width = (float)w;
    height = (float)h;
}
Loseta::Loseta(float x, float y, int w, int h)
{
    posX = (float)x;
    posY = (float)y;
    width = (float)w;
    height = (float)h;
}
void Loseta::Draw() 
{
    ::DrawTexture(texture, posX, posY, WHITE);
}
void Loseta::DrawRec()
{
    ::DrawTextureRec(texture, {0,0,(float)width,(float)height}, { posX, posY }, WHITE);
}
void Loseta::UpdatePosition(float x, float y)
{
    posX = x;
    posY = y;
}
Rectangle Loseta::getRectangle()
{
    Rectangle Rect = { (float)posX,(float)posY,(float)width, (float)height };
    return Rect;
}
void Loseta::setPosition(float x, float y)
{
    posX = x; posY = y;
}
void Loseta::initialize(const char* filename, int x, int y, int w, int h)
{
    texture = LoadTexture(filename);
    posX = (float)x;
    posY = (float)y;
    width = (float)w;
    height = (float)h;
}