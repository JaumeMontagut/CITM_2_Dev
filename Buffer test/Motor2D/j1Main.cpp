#include <stdlib.h>

#include "p2Log.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

int main(int argc, char* args[])
{
	SDL_Init();

	SDL_Window window;
	SDL_Renderer renderer;
	SDL_RenderClear();
	SDL_GetRenderDrawColor(255, 0, 0, 0);
	SDL_RenderFillRect();

	return 1;
}