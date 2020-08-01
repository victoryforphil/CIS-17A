#ifndef _BS_CARRIER_H_
#define _BS_CARRIER_H_

#include "ship.hpp"
namespace BSGame
{   
    /**
     * @brief Carrier ship class. Values: \n
     * name = Carrier \n
     * size = 5 \n
     * type = Tile::AIRCRAFT_CARRIER \n
     * 
     */
    class Carrier : public Ship
    {
    private:
        /* data */
    public:
        Carrier(int id) : Ship(id){};
    void SetInfo()
    {
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