#include "Game.h"
Game::Game()
{

}
Game::~Game()
{

	delete Fondo;
	delete matriz;
	delete piedritas;
	delete Mapa1;
	delete Mapa2;
	delete PJ2D;
	delete NPC;
	delete sub;
	delete pong;
	delete NPC2;
	delete NPC3;
	delete snake;
	delete asteroid;
	UnloadTexture(Fondo->getTexture());
	UnloadTexture(PJ2D->getTexture());
	UnloadTexture(NPC->getTexture());
	UnloadTexture(NPC2->getTexture());
	UnloadTexture(NPC3->getTexture());
	UnloadMusicStream(cancion);
	CloseAudioDevice();
	
}
void Game::Initialise()
{
	InitAudioDevice();
	SetTargetFPS(60);
	InitWindow(800, 600, "Juego - Exploracion");
	SetWindowPosition(( GetMonitorWidth(0) - 800 ) / 2, (GetMonitorHeight(0) - 600) / 2);
	cancion = LoadMusicStream("music/main.mp3");
	PlayMusicStream(cancion);
	matriz->setValor(0, 0, 1);
	matriz->setValor(0, 1, 1);
	matriz->setValor(0, 2, 1);
	matriz->setValor(0, 3, 1);
	//inicializar matriz
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (((i == 0 || i == 29 || j == 0 || j == 39) 
				&& i != 15 && i != 14) 

				|| (j == 12 && (i > 18 || i < 14))
				|| ((i == 19) && (j>40 || j < 8))
				|| (j == 25 && (i > 18 || i < 14))
				|| ((i == 14) && (j > 30))
				|| ((j == 30) && (i > 10 || i < 5))
				|| ((i == 19) && (j > 12))
				|| ((i == 5) && (j > 15))
				
	
				
				)
			{
				piedritas->setValor(i, j, 1);
			}
		}
	}

	Fondo->initialize("texturas/fondo.png", 0, 0, 800, 600);
	Mapa1->initializeMap("texturas/Solid_red.png", 200, 200, matriz);
	Mapa2->initializeMap("texturas/stonewall.png", 20, 20, piedritas);
	PJ2D->inicializarTexturas("texturas/player1.png");
	NPC->inicializarTexturas("texturas/NPC_1.png");
	NPC2->inicializarTexturas("texturas/NPC_2.png");
	NPC3->inicializarTexturas("texturas/NPC_3.png");

	
}
void Game::RunLoop()
{
	
	while (!WindowShouldClose())
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}
void Game::Shutdown()
{
	//UnloadTexture(mapTexture);
	CloseWindow();
}
void Game::GenerateOutput()
{	
	BeginDrawing();
	//limpiar la pantalla
	ClearBackground(RAYWHITE);
	UpdateMusicStream(cancion);
	SetMusicVolume(cancion, 0.4f); // ajustar el volumen de la música
	//dibujar el personaje
	Fondo->Draw();
	Mapa2->Draw();
	NPC->Draw(0, 0, WHITE, 0.5f, 0);
	NPC2->Draw(0, 0, WHITE, 0.5f, 0);
	NPC3->Draw(0, 0, WHITE, 1.2f, 0);
	PJ2D->Draw(0.0, 0.0, WHITE, 0.15f, 0);
	DrawRectangle(540, -5, 240, 40, BLACK);
	DrawText("Esc Para Salir", 550, 0, 30, GREEN);
	// Rectangulos de prueba
	//DrawRectangleRec(NPC3->getRectAlrededor(), RED);

	if (CheckCollisionRecs(PJ2D->getRect(), NPC->getRectAlrededor()))
	{
		if (!IsKeyDown(KEY_F) && !sub->getSubMenu())
		{
			sub->printOpc();
		}
		else 
		{
	
			sub->printMenu(pong, "Ey vos!, Queres jugar al pong?");
		}
		
	}


	if (CheckCollisionRecs(PJ2D->getRect(), NPC2->getRectAlrededor()))
	{
		if (!IsKeyDown(KEY_F) && !sub->getSubMenu())
		{
			sub->printOpc();
		}
		else
		{
			sub->printMenu(snake, "joven le gustaria jugar snake?");
		}
		
	}

	if (CheckCollisionRecs(PJ2D->getRect(), NPC3->getRectAlrededor()))
	{
		if (!IsKeyDown(KEY_F) && !sub->getSubMenu())
		{
			sub->printOpc();
		}
		else
		{
			sub->printMenu(asteroid, "Te gustaria jugar un Asteroid?");
		}

	}


	EndDrawing();

}
void Game::ProcessInput()
{
	//obtiene las imputs del teclado
	PJ2D->movimientoJugador();
}
void Game::UpdateGame()
{

	PJ2D->colisionObjeto(NPC);
	PJ2D->colisionObjeto(NPC2);
	PJ2D->colisionObjeto(NPC3);
	PJ2D->colisionMapa(piedritas, 20, 20);
	
}

