#include <stdio.h>
#include <SDL2/SDL.h>

// Window Dimensions
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// initialize window and surfaces
SDL_Window* window = NULL;
SDL_Surface* screen_surface = NULL;
SDL_Surface* media_surface = NULL;

// start up sdl, make a window
/*bool init();

// load media
bool load_media();

// free media memory and close sdl
void close();*/

bool init()
{
	bool success = false;

	// initialize sdl
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
			screen_surface = SDL_GetWindowSurface(window);
			success = true;
		}
	}
	return success;
}

void close()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[]) {

	bool quit = false;
	SDL_Event e;

	// initializes SDL and assigns the window. if this fails, it'll error message and exit
	if (init())
	{
		// our main loop which updates the screen every 5 seconds. we aren't drawing anything new,
		// so nothing changes
		while (!quit) 
		{
			 // does the user want to quit?
			 while(SDL_PollEvent(&e) != 0)  
			 	if(e.type == SDL_QUIT)  
			 		quit = true;

			// fills the screen with a green rectangle
			SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0x55, 0xFF, 0x99));

			// updates the surface with our newly drawn information
			SDL_UpdateWindowSurface(window);

			// wait 5 milliseconds
			SDL_Delay(5);
		}

		// free memory and quit
		close();	
	}

	return 0;
}
