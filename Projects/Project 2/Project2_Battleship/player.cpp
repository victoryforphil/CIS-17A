#include "player.hpp"
#include <iostream>
#include <iomanip>
using namespace BSGame;

Player::Player(std::string name){
    mName = name;
    mIsBot = false;
}
Player::Player(std::string name, bool isAi){
    mName = name;
    mIsBot = isAi;
}
void Player::populateShips(){
    int id=0;
    for(int i=0;i<10;i++){
        mShips[id] = new BSGame::Battleship(id);
        id++;
    }
}

void Player::print(){
    std::cout << "print()" << std::endl;
}

void Player::printShips(){
    std::cout << " --- Ships --- " << std::endl;
    std::cout << std::left << std::setw(5) << std::setfill(' ') << "ID" << std::setw(32) << "Name" << std::setw(5) << "Health" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::left << std::setw(5) << std::setfill(' ') << mShips[i]->getId()
        << std::setw(32) << mShips[i]->getName() << std::setw(1) 
        << mShips[i]->getHealth() << "/" << mShips[i]->getSize() << std::endl;
    }
}

void Player::takeTurn(){
    
}

bool Player::checkPlace(BSVector2 start, BSVector2 end){
    start.clampMin(0);

    for(int y=0;y< ((end.y() - start.y()) + 1); y++){
        for(int x=0;x<((end.x()-start.x()) + 1); x++){
            BSVector2 trueVec(start.x() + x, start.y() + y);
            trueVec.clampMax(9);


            BSVector2 testVec = trueVec;
                
            // Loop through top left, middle and bottom right coorindates for tiles to ceheck
            for(int i=0;i<3;i++){
                testVec.setX(testVec.x() + (-1 + i)));
                testVec.setY(testVec.y() + (-1 + i)));
                testVec.clampMin(0);
                if(getPrivateBoard()->getTile() != Tile::EMPTY){
                    return false;
                }
            }
        }
    }
    return true;
}

Board* Player::getPrivateBoard(){
    return mBoard;
}
Board* Player::getHitBoard(){
    return mHitBrd;
}