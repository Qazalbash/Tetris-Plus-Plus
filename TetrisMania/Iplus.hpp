#include<SDL.h>
#include "Tetris_block.hpp"


/*
This class represents the L-SHAPED block
*/

class Iplus:public Tetris_Block{

public:
    /*
    The draw function draws the L-ShAPED Block on the screen.
    */
    void draw(SDL_Renderer*, SDL_Texture* );
    /*
    Defines functionality of the L-SHAPED block to make it fall.
    */
    void drop();
    /*
    Switches between different images of L-SHAPED block to show rotation
    */
    void rotation();
    /*
    Provides functionality to block to move left, right and down with the help of arrow keys.
    */
    void slide(int);
    /*
    Checks whether block has reached the ground. returns a boolean value.
    */
    // bool isReached(bool);
    /*
    Constructor extracts initial image from assets.png and defines coordinates
    of the location and dimensions where it is to be placed on the screen. 
    */
    Iplus(); 
    static const int rightwall=547;
    static const int leftwall=80;

    


  
};
