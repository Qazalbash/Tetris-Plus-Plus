#include<SDL.h>


class ImgTet{
SDL_Rect srcRect, moverRect;

public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    ImgTet(); // may add other overloaded constructors here... 
};
