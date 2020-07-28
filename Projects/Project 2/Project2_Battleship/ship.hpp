#ifndef _BS_SHIP_H_
#define _BS_SHIP_H_

#include <iostream>
#include <string>
#include "board.hpp"
namespace BSGame
{
    class Ship
    {
    protected:
        /* data */
        std::string mName;
        int mId;
        int mSize;
        int mHits;
        Tile mType;
        bool mIsDead;
    public:
        Ship(int id){mId = id;};
        ~Ship(){};
        int getHealth();
        bool getDead();
        void print();
        int getSize();
        int getId();
        int getType();
        std::string getName();
    };
    

} // namespace BattleShip

#endif
