#ifndef _BS_BOARD_H_
#define _BS_BOARD_H_
#include "math.hpp"

namespace BSGame
{
    /**
     * @brief Tile enum to easily define tile types
     * 
     */
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

    /**
     * @brief Game board representation (2d array, 15x15, ints)
     * 
     */
    class Board
    {
    private:
        int mBoard[15][15]; //Y X order

    public:
        Board();
        /**
         * @brief Get the tile value at a given location
         * 
         * @param vector the location to look up
         * @return int tile value
         */
        int getTile(BSVector2<int> vector);
        /**
         * @brief Get the Board object
         * 
         * @return int 
         */
        int getBoard();
        /**
         * @brief Set all values of the board to one value
         * 
         * @param defaultVal value to set the board too
         */
        void resetBoard(int val);
        /**
         * @brief Set the Tile value at a given location
         * 
         * @param vector location to set
         * @param value tile value to set
         */
        void setTile(BSVector2<int> vector, int value);
        
        ~Board();
    };
} // namespace BattleShip

#endif