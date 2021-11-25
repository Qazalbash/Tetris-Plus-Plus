#include<iostream>
#include "TetrisMania.hpp"

void TetrisMania::drawObjects(){
    //Drawing all objects here. 
    if (screen_number==1){
        for (auto b: Blocks){
            b->draw(gRenderer, assets);
        }//random block is generated and dropped after first block reaches the ground. 
        if (currentblock->isReached()){
            currentblock=randomBlock();
            Blocks.push_back(currentblock);
        }
    }
    //t1-image of tetrs, sg-image of start game, ex--image of exit
    //all printed on the first home screen. 
    else{
        t1.draw(gRenderer, assets);
        sg.draw(gRenderer, assets);
        ex.draw(gRenderer, assets);
    }
}

//swithcing from one screen to another. 
void TetrisMania::screen_Setter(int x){
    screen_number=x;
}

//generates random blocks. 
Tetris_Block* TetrisMania::randomBlock(){
    int r;
    r= (rand() % 30) + 1;
    if (r>1 && r<10){
        return new Lplus;
    }
    else if (r>10 && r<20){
        return new Tplus;
    }
    else if (r>20 && r<30){
        return new Oplus;
    }
}
//Function closes window when exit button is pressed. 
void TetrisMania::createObject(int x, int y){
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
   
    if (x>15 && x<150 && y>10 && y<60){
        ex.animate();
        gm.close();
    }
}

//Function used to rotate individual blocks. 
void TetrisMania::rotateObject(){
    currentblock->rotation();
}

//Function used tomove block to the left and right. 
void TetrisMania::slideObject(int direct){
    currentblock->slide(direct);
}

//Constructor initially making one block fall. 
TetrisMania::TetrisMania(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    currentblock=randomBlock();
    Blocks.push_back(currentblock);
}
