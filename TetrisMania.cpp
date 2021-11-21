#include<iostream>
#include "TetrisMania.hpp"

void TetrisMania::drawObjects(){
    // call draw functions of all the objects here
    t1.draw(gRenderer, assets);
    sg.draw(gRenderer, assets);
    ex.draw(gRenderer, assets);
    L.draw(gRenderer, assets);
}

void TetrisMania::createObject(int x, int y){
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    if (x>400 && x<600 && y>500 &&y<580){
        sg.animate();
    }
    else if (x>15 && x<150 && y>10 && y<60){
        ex.animate();
        gm.close();
    }
}

void TetrisMania::rotateObject(){
    L.rotation();
}

TetrisMania::TetrisMania(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}
