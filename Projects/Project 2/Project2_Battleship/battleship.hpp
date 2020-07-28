#ifndef _BS_BATTLESHIP_H_
#define _BS_BATTLESHIP_H_

#include "ship.hpp"
namespace BSGame
{
    class Battleship : public Ship
    {
    private:
        /* data */
    public:
       Battleship(int id) : Ship( id)
    {
        mId = id;
        mName = "Battleship";
        mSize = 4;
        mIsDead = false;
        mHits = 0;
    }
       // ~Battleship();
    };
    
    
    

    
} // namespace BattleShip


#endif