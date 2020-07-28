#ifndef _BS_DESTORYER_H_
#define _BS_DESTORYER_H_

#include "ship.hpp"
namespace BSGame
{
    class Destroyer : public Ship
    {
    private:
        /* data */
    public:
       Destroyer(int id) : Ship( id)
    {
        mId = id;
        mName = "Destroyer";
        mSize = 3;
        mIsDead = false;
        mType = Tile::DESTROYER;
        mHits = 0;
    }
       // ~Battleship();
    };
    
    
    

    
} // namespace BattleShip


#endif