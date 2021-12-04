#include "Exit.hpp"
// pigeon implementation will go here.

void Exit::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    // moverRect.x+=2; // moves the pigeon one pixel towards right, should it be in fly function??
    if (rec_recover)
    {
        moverRect.x = moverRect.x - 5;
        moverRect.y = moverRect.y - 5;
        rec_recover = false;
    }
}
void Exit::animate()
{
    rec_recover = true;
    moverRect.x = moverRect.x + 5;
    moverRect.y = moverRect.y + 5;
}

Exit::Exit()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {3, 0, 93, 40};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {15, 10, 125, 50};
}