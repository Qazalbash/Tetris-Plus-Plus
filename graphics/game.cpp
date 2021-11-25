#include "game.hpp"
#include "TetrisMania.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <SDL_mixer.h>



using namespace std;

// Funciton used to draw new surface and map for Tetris mania. 
void Game::blit(){
	SDL_Surface *screen = SDL_GetWindowSurface(gWindow);
		SDL_Surface* wallImage = NULL;
	    SDL_Surface* foodImage = NULL;
		SDL_Surface* pacmanImage = NULL;
		// wallImage = SDL_LoadBMP( "wall.bmp" );
		wallImage = IMG_Load( "wall.bmp" );
			if(wallImage==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
    }
		
        // foodImage = SDL_LoadBMP( "point.bmp" );
		pacmanImage =  IMG_Load("homepage.png");
	
		if(pacmanImage==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
    }
        ifstream fin("mapa.txt", std::ios::in);
		std::fstream file;
		string path = "mapa.txt";
		// Open the file and check if successful
		file.open(path.c_str(), std::ios::in);

		string line;

		SDL_Rect srect= {0,0,25,25};
		SDL_Rect drect = wallImage->clip_rect;
		// SDL_Rect drectb = pacmanImage->clip_rect;
		// SDL_Rect srectb= {0,0,1000,640};
		// SDL_BlitSurface(pacmanImage, NULL, screen, &srectb );
		int x = 0;
		while (getline(file, line)) {
			vector<char> chars(line.begin(), line.end());
			for (unsigned int y = 0; y < chars.size(); y++){
				cout<<drect.x<<" "<<drect.y<<endl;
				switch (chars[y])
					{
						case 'x':
							SDL_BlitSurface(wallImage, NULL, screen, &drect );
							break;			
					}
				drect.x+=25;
			}
			drect.x=0;
			drect.y+=25;
			}
			blit_called = true;
			gTexture = SDL_CreateTextureFromSurface( gRenderer, screen);
}


bool Game::init()
{
	//Initialization flag
	bool success = true;
	blit_called=false;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Tetris++ Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia(bool check)
{
	//Loading success flag
	bool success = true;

	if (check==false){
		cout<<"false running original"<<endl;
		assets = loadTexture("assets.png");
    	gTexture = loadTexture("background.png");
	}
	
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit=false;
	SDL_Event e;

	TetrisMania tetrismania(gRenderer, assets);

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			//Calling functions that are to be run on the click of the mouse button
			else if(e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				tetrismania.createObject(xMouse, yMouse);
				if (xMouse>400 && xMouse<600 && yMouse>500 && yMouse<580) {
					// gTexture = loadTexture("homepage.png");
					blit();
					tetrismania.screen_Setter(1);
					
				}
			}

			//Calling functions that are to be run depending on input from the keyboard. 
			else if (e.type = SDL_KEYDOWN){
				if (e.key.keysym.sym== SDLK_SPACE){
					tetrismania.rotateObject();
				}
				else if (e.key.keysym.sym== SDLK_RIGHT){
					tetrismania.slideObject(1);
				}
				else if (e.key.keysym.sym== SDLK_LEFT){
					tetrismania.slideObject(-1);
				}
				else if (e.key.keysym.sym== SDLK_DOWN){
					tetrismania.slideObject(0);
				}
				
			}
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		
		tetrismania.drawObjects();
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}
