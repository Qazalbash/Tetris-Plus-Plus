#include<SDL.h>

class Lplus{
SDL_Rect srcRect, moverRect;
int n=0;
public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void rotation();
    Lplus(); // may add other overloaded constructors here... 
};
