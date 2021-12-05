#include "game.hpp"

// Funciton used to draw new surface and map for Tetris mania.
void Game::blit()
{
	SDL_Surface *screen = SDL_GetWindowSurface(gWindow);
	SDL_Surface *wallImage = NULL;
	// wallImage = SDL_LoadBMP( "wall.bmp" );
	wallImage = IMG_Load("wall.bmp");
	if (wallImage == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
	}

	SDL_Rect drect = {0, 0, BLOCK_SIZE, BLOCK_SIZE};
	// SDL_Rect drect = wallImage->clip_rect;

	// printing both side walls
	for (int i = 0; i < T_ROWS + 1; i++)
	{
		// left side wall
		drect.y = (BLOCK_SIZE * 2) + i * BLOCK_SIZE;
		drect.x = (BLOCK_SIZE * 4);
		SDL_BlitSurface(wallImage, NULL, screen, &drect);

		// right side wall
		drect.y = (BLOCK_SIZE * 2) + i * BLOCK_SIZE;
		drect.x = BLOCK_SIZE * 5 + T_COLS * BLOCK_SIZE;
		SDL_BlitSurface(wallImage, NULL, screen, &drect);
	}

	// drawing the bottom wall
	for (int i = 0; i < T_COLS; i++)
	{
		// left side wall
		drect.y = BLOCK_SIZE * 2 + T_ROWS * BLOCK_SIZE;
		;
		drect.x = BLOCK_SIZE * 5 + i * BLOCK_SIZE;
		SDL_BlitSurface(wallImage, NULL, screen, &drect);
	}

	blit_called = true;
	gTexture = SDL_CreateTextureFromSurface(gRenderer, screen);
}

bool Game::init()
{
	// Initialization flag
	bool success = true;
	blit_called = false;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Tetris++ Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool Game::loadMedia(bool check)
{
	// Loading success flag
	bool success = true;

	if (check == false)
	{
		cout << "false running original" << endl;
		assets = loadTexture("assets2.png");
		gTexture = loadTexture("background.png");
	}

	if (assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Game::drawMainScreenButtons()
{
	// First drawing Img Tet
	SDL_Rect sRect = {176, 90, 144, 95};
	SDL_Rect mRect = {370, 180, 270, 200};
	// SDL_Rect mRect = {370, 180, 20, 20};

	SDL_RenderCopy(gRenderer, assets, &sRect, &mRect);

	// Second drawing start Game
	sRect = {180, 255, 140, 34};
	mRect = {400, 500, 200, 80};

	SDL_RenderCopy(gRenderer, assets, &sRect, &mRect);

	// Third drawing the Exit button
	sRect = {3, 0, 93, 40};
	mRect = {15, 10, 125, 50};

	SDL_RenderCopy(gRenderer, assets, &sRect, &mRect);
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run()
{
	bool quit = false;
	bool parity;
	SDL_Event e;

	TetrisMania tetrismania(gRenderer, assets, T_ROWS, T_COLS);

	while (!quit)
	{
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);

				if (xMouse > 400 && xMouse < 600 && yMouse > 500 && yMouse < 580)
				{
					cureent_screen = 1;
					blit();
				}
			}

			else if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_UP)
				{
					tetrismania.rotateShape();
				}
				else if (e.key.keysym.sym == SDLK_LEFT)
				{
					tetrismania.moveeShapeLeft();
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					tetrismania.moveShapeRight();
				}
				else if (e.key.keysym.sym == SDLK_DOWN)
				{
					tetrismania.slideShapeDown();
				}
				else if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}
		}

		SDL_RenderClear(gRenderer);						 // removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); // Draws background to renderer
		//***********************draw the objects here********************

		if (cureent_screen == 0)
		{
			tetrismania.drawMainScreenButtons();
		}
		else if (cureent_screen == 1)
		{
			parity = tetrismania.drawObjects();
		}

		SDL_RenderPresent(gRenderer); // displays the updated renderer

		SDL_Delay(200); // causes sdl engine to delay for specified miliseconds
	}
}
