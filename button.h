#include <SDL.h>


class Button{
    private:
    SDL_Rect src_idle, mover_idle;
    SDL_Rect src_hover, mover_hover;
    SDL_Rect src_pressed, mover_pressed;

    public:
    Button(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void animate(int mouse_x, int mouse_y, bool clk);



}; 