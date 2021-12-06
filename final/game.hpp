#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

#include "TetrisMania.hpp"

using namespace std;

class Game
{
    // the dimensions of the screen
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 850;

    const int T_ROWS = 30;
    const int T_COLS = 25;

    const int BLOCK_SIZE = 25;

    // main window
    SDL_Window *gWindow = NULL;

    // the main rendrer
    SDL_Renderer *gRenderer = NULL;

    //The music that will be played
    Mix_Music *gMusic = NULL;

    // Current displayed texture
    SDL_Texture *gTexture = NULL;

    // global reference to png image sheets
    SDL_Texture *assets = NULL;

    string cur_string = " ";
    int cureent_screen = 0;

public:
    bool check = false;

    bool blit_called;
    void blit();
    bool init();
    bool loadMedia(bool check);
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
    void page_selection_on_click(int, int);
};