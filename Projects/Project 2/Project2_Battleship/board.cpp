#include "board.hpp"

using namespace BSGame;


Board::Board(){

}

int Board::getTile(BSVector2 vector){
    return mBoard[vector.y()][vector.x()];
}

void Board::resetBoard(int defaultVal){
    for(int y=0;y<10;y++){
        for(int x=0;x<10;x++){
            setTile(BSVector2(x,y),defaultVal);
        }
    }
}

void Board::setTile(BSVector2 vector, int value){
    mBoard[vector.y()][vector.x()] = value;
}


Board::~Board(){

}