#ifndef _BS_BATTLESHIP_H_
#define _BS_BATTLESHIP_H_

#include <ship.hpp>
namespace BattleShip
{
    class Battleship : Ship
    {
    private:
        /* data */
    public:
        Battleship : Ship(/int id);
        ~Battleship : Ship();
    };
    
    Battleship : Ship::Battleship : Ship(int id)
    {
        mId = id;
        mName = "Battleship";
        mSize = 4;
        mDead = false;
        mHits = 0;
    }
    
    Battleship : Ship::~Battleship : Ship()
    {
    }
    
} // namespace BattleShip


#endif