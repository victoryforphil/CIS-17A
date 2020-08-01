#include "board.hpp"

using namespace BSGame;
#include <iostream>

Board::Board(){
    resetBoard(EMPTY);
}

int Board::getTile(BSVector2<int> vector){
    return mBoard[vector.y()][vector.x()];
}

void Board::resetBoard(int val){
    for(int y=0;y<10;y++){
        for(int x=0;x<10;x++){
           
            BSVector2<int> vec(x,y);
         
            setTile(vec, val);
        }
    }
}

void Board::setTile(BSVector2<int> vector, int value){
    mBoard[vector.y()][vector.x()] = value;

}

Board::~Board(){

}