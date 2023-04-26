#pragma once
#include "raylib.h"
#include "Matriz.h"

class Matriz;

class Personaje2D {
private:
    Texture2D texture;
    float posX;
    float posY;
    float walk;
    float scale;

public:
    Personaje2D(float x, float y, float sca) :
         posX(x), posY(y), scale(sca) {
        walk = 4;
    }

    void Draw(float x, float y, Color tint, float scale, float rotation);

    float width() const;
    float height() const;
    void setXwalk(int s);
    void setYwalk(int s);
    Texture2D getTexture() { return texture; };
    Rectangle getRect();
    Rectangle getRectAlrededor();
    void movimientoJugador();
    //void colisionObjeto(Map* mp);
    void colisionObjeto(Personaje2D* npc);
    void inicializarTexturas(const char* filename);
    void colisionRec(Rectangle Rec);
    void colisionMapa(Matriz* posiciones, float base, float altura);
};
