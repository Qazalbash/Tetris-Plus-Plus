#include <SDL.h>
// #include "Unit.hpp"
#include <string>

class sdl_grid
{
public:
    // Unit* data;
    SDL_Rect x;
    // char name;
    bool occupied;
    sdl_grid(SDL_Rect y = {0, 0, 0, 0}, bool o = false)
    {
        x = y;
        occupied = o;
    }
    void change_state()
    {
        occupied = !occupied;
    }
};