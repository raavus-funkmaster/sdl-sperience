#include <stdio.h>
#include <SDL2/SDL.h>

// Window Dimensions
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* argv[]) {

	// Make our window and surface
	SDL_Window* window = NULL;
	SDL_Surface* surf = NULL;

	// Initialize SDL
	if(SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		printf("SDL failed to initialize. Error: %s\n", SDL_GetError());

	else
	{
		// Assign our window 
		window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
			printf("Window creation failed. Error: %s\n", SDL_GetError());

		else
		{
			// begin interacting with window surface
			surf = SDL_GetWindowSurface(window);

			// fills the screen with a green rectangle
			SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, 0x55, 0xFF, 0x99));

			// updates the surface with our newly drawn information
			SDL_UpdateWindowSurface(window);

			// wait 5 seconds
			SDL_Delay(5000);
		}

		// free memory and quit
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	return 0;
}
