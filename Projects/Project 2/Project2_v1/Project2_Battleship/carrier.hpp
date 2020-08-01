#ifndef _BS_CARRIER_H_
#define _BS_CARRIER_H_

#include "ship.hpp"
namespace BSGame
{
    class Carrier : public Ship
    {
    private:
        /* data */
    public:
       Carrier(int id) : Ship( id)
    {
        mId = id;
        mName = "Carrier";
        mSize = 5;
        mIsDead = false;
        mType = Tile::AIRCRAFT_CARRIER;
        mHits = 0;
    }
       // ~Battleship();
    };
    
    
    

    
} // namespace BattleShip


#endif