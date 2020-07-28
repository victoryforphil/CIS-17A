#include "ship.hpp"
#include <iomanip>
using namespace BattleShip;

int Ship::getHealth(){
    return getSize() - mHits;
}

int Ship::getSize(){
    return mSize;
}

bool Ship::getDead(){   
    return mDead();
}

std::string Ship::getName(){
    return mName;
}
int Ship::getId(){
    return mId;
}
void Ship::print(){
    std::cout << std::left << std::setw(5) << std::setfill(' ') << getId() << std::setw(32) << getName() << std::setw(1) << getHealth() << "/" << getSize() << std::endl;
    //std::cout << "SHIP!" << std::endl;
}