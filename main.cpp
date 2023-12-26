#include <sdl.h>
#include <iostream>
#include <string>
#include <SDL_image.h>

using namespace std;

const int screen_w = 1000;
const int screen_h = 800;

enum keypresssurfaces
{
	key_press_surface_default,
	key_press_surface_up,
	key_press_surface_down,
	key_press_surface_left,
	key_press_surface_right,
	key_press_surface_total
};

bool init();
bool loadmedia();
void close();

SDL_Window* window = NULL; //окно
SDL_Surface* scr = NULL;  //основная поверхность окна
SDL_Surface* loadsurface(string path); //загруженные изображения
SDL_Surface* keypresssurfaces[key_press_surface_total]; //картинки по нажатию клавиши
SDL_Surface* cur = NULL; //текущая картинка

int main(int argc, char* args[])
{	
		if (!init())
		{
			cout << "failed to initialize!\n";
		}
		else
		{
			if (!loadmedia())
			{
				cout << "failed to load media!\n";
			}
			else
			{
				bool quit = false;
				SDL_Event e;
				cur = keypresssurfaces[key_press_surface_default];
				while (!quit)
				{
					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
						}
						else if (e.type == SDL_KEYDOWN)
						{
							switch (e.key.keysym.sym)
							{
							case SDLK_UP:
								cur = keypresssurfaces[key_press_surface_up];
								break;

							case SDLK_DOWN:
								cur = keypresssurfaces[key_press_surface_down];
								break;

							case SDLK_LEFT:
								cur = keypresssurfaces[key_press_surface_left];
								break;

							case SDLK_RIGHT:
								cur = keypresssurfaces[key_press_surface_right];
								break;

							default:
								cur = keypresssurfaces[key_press_surface_default];
								break;
							}
						}
					}

					SDL_Rect rect;
					rect.x = -300;
					rect.y = -300;
					rect.w = screen_w*2;
					rect.h = screen_h*2;

					if (cur == keypresssurfaces[key_press_surface_default] || cur == keypresssurfaces[key_press_surface_down])
					{
						SDL_BlitSurface(cur, NULL, scr, NULL);
					}
					else
					{
						SDL_BlitSurface(loadsurface("image/FON1.bmp"), NULL, scr, NULL);
						SDL_BlitScaled(cur, &rect, scr, NULL);
					}
					SDL_UpdateWindowSurface(window);

				}
			}
		}
	close();
	return 0;
}
bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				scr = SDL_GetWindowSurface(window);
			}
		}
	}

	return success;
}

bool loadmedia()
{
	bool success = true;

	keypresssurfaces[key_press_surface_default] = loadsurface("image/FON.bmp");
	if (keypresssurfaces[key_press_surface_default] == NULL)
	{
		cout << "failed to load default image!\n";
		success = false;
	}

	keypresssurfaces[key_press_surface_up] = loadsurface("image/TIG1.bmp");
	if (keypresssurfaces[key_press_surface_up] == NULL)
	{
		cout << "failed to load default image!\n";
		success = false;
	}

	keypresssurfaces[key_press_surface_down] = loadsurface("image/ZOO.bmp");
	if (keypresssurfaces[key_press_surface_down] == NULL)
	{
		cout << "failed to load default image!\n";
		success = false;
	}

	keypresssurfaces[key_press_surface_left] = loadsurface("image/CAT1.bmp");
	if (keypresssurfaces[key_press_surface_left] == NULL)
	{
		cout << "failed to load default image!\n";
		success = false;
	}

	keypresssurfaces[key_press_surface_right] = loadsurface("image/POP1.bmp");
	if (keypresssurfaces[key_press_surface_right] == NULL)
	{
		cout << "failed to load default image!\n";
		success = false;
	}

	return success;
}

void close()
{
	for (int i = 0; i < key_press_surface_total; ++i)
	{
		SDL_FreeSurface(keypresssurfaces[i]);
		keypresssurfaces[i] = NULL;
	}
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

SDL_Surface* loadsurface(string path)
{
	SDL_Surface* optimizedsurface = NULL;
	SDL_Surface* loadedsurface = SDL_LoadBMP(path.c_str());
	if (loadedsurface == NULL)
	{
		cout << "unable to load image %s! sdl error: %s\n", path.c_str(), SDL_GetError();
	}
	else
	{
		//convert surface to screen format
		optimizedsurface = SDL_ConvertSurface(loadedsurface, scr->format, 0);
		if (optimizedsurface == NULL)
		{
			printf("unable to optimize image %s! sdl error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedsurface);
	}

	return optimizedsurface;
}
