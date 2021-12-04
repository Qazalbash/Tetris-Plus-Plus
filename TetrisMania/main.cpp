#include "game.hpp"
#include <SDL_ttf.h>
#include <SDL.h>

int main(int argc, char *argv[]){
    Game game;
    bool check=false;
    
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !game.loadMedia(check) ){
        printf( "Failed to load media!\n" );
        return 0;
    }

    game.run();
    game.close();

    return 0;
}