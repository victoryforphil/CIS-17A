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