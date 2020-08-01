#ifndef _BS_BOARD_H_
#define _BS_BOARD_H_
#include "math.hpp"
namespace BattleShip
{
    enum Tile
    {
        EMPTY = 0,
        AIRCRAFT_CARRIER = 1,
        BATTLESHIP = 2,
        DESTROYER = 3,
        CRUISER = 4,
        HIT = 5,
        MISS = 6
    };

    class Board
    {
    private:
        int mBoard[10][10]; //Y X order

    public:
        Board();
        int getTile(BSVector2 vector);
        int getBoard();
        void resetBoard(int defaultVal);
        void setTile(BSVector2 vector, int value);
        
        ~Board();
    };
} // namespace BattleShip

#endif