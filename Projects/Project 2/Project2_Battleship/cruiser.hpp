#ifndef _BS_CRUISER_H_
#define _BS_CRUISER_H_

#include "ship.hpp"
namespace BSGame
{
    /**
     * @brief Cruiser ship class. Values: \n
     * name = Cruiser \n
     * size = 2 \n
     * type = Tile::CRUISER \n
     * 
     */
    class Cruiser : public Ship
    {
    private:
        /* data */
    public:
       Cruiser(int id) : Ship( id)
    {
        mId = id;
        mName = "Cruiser";
        mSize = 2;
        mIsDead = false;
        mType = CRUISER;
        mHits = 0;
    }
       // ~Battleship();
    };
    
    
    

    
} // namespace BattleShip


#endif