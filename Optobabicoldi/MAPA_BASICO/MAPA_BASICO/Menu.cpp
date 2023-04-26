#include "Menu.h"

int menu() {
	int option;
	bool confirmacion = true;
	int largoTexto = MeasureText("Menu Juegos", 60);
	int largoJugar1 = MeasureText("Opcion 1", 40);
	int largoJugar2 = MeasureText("Opcion 2", 40);
	float puntero_x = (float)GetScreenWidth() / 2 - largoJugar1;
	float puntero_y = (float)GetScreenHeight() / 2 - 20;
	while (confirmacion && !WindowShouldClose()) {
		if (IsKeyDown(KEY_W))
		{
			puntero_x = (float)GetScreenWidth() / 2 - largoJugar1;
			puntero_y = (float)GetScreenHeight() / 2 - 20;
		}
		if (IsKeyDown(KEY_S))
		{
			puntero_x = (float)GetScreenWidth() / 2 - largoJugar1;
			puntero_y = (float)GetScreenHeight() / 2 + 40;
		}
		if (IsKeyPressed(KEY_SPACE)) {
			if (puntero_y == (float)GetScreenHeight() / 2 - 20) {
				confirmacion = false;
				return 1;
			}
			if (puntero_y == (float)GetScreenHeight() / 2 + 40) {
				confirmacion = false;
				return 2;
			}
		}
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Juegardos", GetScreenWidth() / 2 - largoTexto / 2, 20, 60, WHITE);
		DrawText("opcion 1 - Tipito", GetScreenWidth() / 2 - largoJugar1 / 2, GetScreenHeight() / 2 - 40, 40, WHITE);
		DrawText("opcion 2 - Pong", GetScreenWidth() / 2 - largoJugar1 / 2, GetScreenHeight() / 2 + 20, 40, WHITE);
		DrawPoly(Vector2{ puntero_x,puntero_y }, 3, 20, 90.0, WHITE);
		EndDrawing();
	}
}


Submenu::Submenu()
{
	mostrarSubMenu = false;
	opcionSeleccionada = -1;
}

bool Submenu::getSubMenu()
{
	return mostrarSubMenu;
}
void Submenu::setSubMenu(bool setSm)
{
	mostrarSubMenu = setSm;
}
int Submenu::getOpcSelec()
{
	return opcionSeleccionada;
}

void Submenu::setOpcSelec(int setOs)
{
	opcionSeleccionada = setOs;
}
void Submenu::printOpc()
{
    if (!getSubMenu())
    {
    // Dibuja un rectángulo negro
    DrawRectangle(250, 600 - 80, 460, 50, BLACK);

    // Establece el color del texto como blanco

    // Dibuja el texto sobre el rectángulo negro
    DrawText("Presiona F para interactuar", 250, 600 - 75, 30,WHITE);
    }
}
void Submenu::printMenu(Pong* game,const char* mensaje)
{
    if (IsKeyPressed(KEY_F))
    {
        setSubMenu(true);
    }

    if (getSubMenu())
    {
        // Dibujar el menú
        const int menuPosX = 20;
        const int menuPosY = 600 - 100;
        const int menuWidth = 160;
        const int menuHeight = 60;
        const int opcionHeight = 30;
        DrawRectangle(menuPosX, menuPosY - opcionHeight - 5, 30*17, 50, BLACK);
        DrawText(mensaje, menuPosX + 10, menuPosY - opcionHeight - 5, 30, WHITE);
        DrawRectangle(menuPosX, menuPosY, menuWidth, menuHeight, LIGHTGRAY);

        DrawText("Si (Up)", menuPosX + 10, menuPosY + 5, 30, opcionSeleccionada == 0 ? MAROON : BLACK);
        DrawText("No (Down)", menuPosX + 10, menuPosY + opcionHeight + 5, 30, opcionSeleccionada == 1 ? MAROON : BLACK);

        // Detectar si el usuario ha cambiado de opción con las teclas W y S
        if (IsKeyPressed(KEY_UP))
        {
            opcionSeleccionada--;
            if (opcionSeleccionada < 0)
            {
                opcionSeleccionada = 1;
            }
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            opcionSeleccionada++;
            if (opcionSeleccionada > 1)
            {
                opcionSeleccionada = 0;
            }
        }

        // Realizar la acción correspondiente a la opción seleccionada
        if (IsKeyPressed(KEY_ENTER))
        {

            setSubMenu(false);
            if (opcionSeleccionada == 0)
            {
                game->game();
            }
            else if (opcionSeleccionada == 1)
            {
                // Salir
            }
        }
    }
}



void Submenu::printMenu(GameRunSnake* game, const char* mensaje)
{
    if (IsKeyPressed(KEY_F))
    {
        setSubMenu(true);
    }

    if (getSubMenu())
    {
        // Dibujar el menú
        const int menuPosX = 20;
        const int menuPosY = 600 - 100;
        const int menuWidth = 160;
        const int menuHeight = 60;
        const int opcionHeight = 30;
        DrawRectangle(menuPosX, menuPosY - opcionHeight - 5, 30 * 17, 50, BLACK);
        DrawText(mensaje, menuPosX + 10, menuPosY - opcionHeight - 5, 30, WHITE);
        DrawRectangle(menuPosX, menuPosY, menuWidth, menuHeight, LIGHTGRAY);

        DrawText("Si (Up)", menuPosX + 10, menuPosY + 5, 30, opcionSeleccionada == 0 ? MAROON : BLACK);
        DrawText("No (Down)", menuPosX + 10, menuPosY + opcionHeight + 5, 30, opcionSeleccionada == 1 ? MAROON : BLACK);

        // Detectar si el usuario ha cambiado de opción con las teclas W y S
        if (IsKeyPressed(KEY_UP))
        {
            opcionSeleccionada--;
            if (opcionSeleccionada < 0)
            {
                opcionSeleccionada = 1;
            }
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            opcionSeleccionada++;
            if (opcionSeleccionada > 1)
            {
                opcionSeleccionada = 0;
            }
        }

        // Realizar la acción correspondiente a la opción seleccionada
        if (IsKeyPressed(KEY_ENTER))
        {

            setSubMenu(false);
            if (opcionSeleccionada == 0)
            {
                game->game();
            }
            else if (opcionSeleccionada == 1)
            {
                // Salir
            }
        }
    }
}


void Submenu::printMenu(AsteroidGame* game, const char* mensaje)
{
    if (IsKeyPressed(KEY_F))
    {
        setSubMenu(true);
    }

    if (getSubMenu())
    {
        // Dibujar el menú
        const int menuPosX = 20;
        const int menuPosY = 600 - 100;
        const int menuWidth = 160;
        const int menuHeight = 60;
        const int opcionHeight = 30;
        DrawRectangle(menuPosX, menuPosY - opcionHeight - 5, 30 * 17, 50, BLACK);
        DrawText(mensaje, menuPosX + 10, menuPosY - opcionHeight - 5, 30, WHITE);
        DrawRectangle(menuPosX, menuPosY, menuWidth, menuHeight, LIGHTGRAY);

        DrawText("Si (Up)", menuPosX + 10, menuPosY + 5, 30, opcionSeleccionada == 0 ? MAROON : BLACK);
        DrawText("No (Down)", menuPosX + 10, menuPosY + opcionHeight + 5, 30, opcionSeleccionada == 1 ? MAROON : BLACK);

        // Detectar si el usuario ha cambiado de opción con las teclas W y S
        if (IsKeyPressed(KEY_UP))
        {
            opcionSeleccionada--;
            if (opcionSeleccionada < 0)
            {
                opcionSeleccionada = 1;
            }
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            opcionSeleccionada++;
            if (opcionSeleccionada > 1)
            {
                opcionSeleccionada = 0;
            }
        }

        // Realizar la acción correspondiente a la opción seleccionada
        if (IsKeyPressed(KEY_ENTER))
        {

            setSubMenu(false);
            if (opcionSeleccionada == 0)
            {
                game->game();
            }
            else if (opcionSeleccionada == 1)
            {
                // Salir
            }
        }
    }
}