#ifndef _BS_BATTLESHIP_H_
#define _BS_BATTLESHIP_H_

#include "ship.hpp"
namespace BSGame
{
    /**
     * @brief Battleship ship class. Values: \n
     * name = Battleship \n
     * size = 4 \n
     * type = Tile::BATTLESHIP \n
     * 
     */
    class Battleship : public Ship
    {
    private:
        /* data */
    public:
        Battleship(int id):Ship(id){};
        void SetInfo()
        {
            mName = "Battleship";
            mSize = 4;
            mIsDead = false;
            mHits = 0;
            mType = Tile::BATTLESHIP;
        }
        // ~Battleship();
    };

} // namespace BSGame

#endif