#include "Game.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int main() 
{
	Game* game = new Game();

	game->Initialise();
	game->RunLoop();
	game->Shutdown();

	delete game;

	return 0;
}