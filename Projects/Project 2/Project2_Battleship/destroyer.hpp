#ifndef _BS_DESTORYER_H_
#define _BS_DESTORYER_H_

#include "ship.hpp"
namespace BSGame
{
     /**
     * @brief Destroyer ship class. Values: \n
     * name = Destroyer \n
     * size = 3 \n
     * type = Tile::DESTROYER \n
     * 
     */
    class Destroyer : public Ship
    {
    private:
        /* data */
    public:
    Destroyer(int id) : Ship(id){};
     void SetInfo()
    {

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