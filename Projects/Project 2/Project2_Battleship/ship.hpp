#ifndef _BS_SHIP_H_
#define _BS_SHIP_H_

#include <iostream>
#include <string>
#include "board.hpp"
namespace BSGame
{
    /**
     * @brief Base ship class that all other ships derive from
     * 
     */
    class Ship
    {
    protected:
        /* data */
        std::string mName;
        int mId;
        int mSize;
        int mHits;
        Tile mType;
        bool mIsDead;
    public:
        Ship(int id){mId = id;};
        ~Ship(){};
        /**
         * @brief Get the Health value (size-hits)
         * 
         * @return int 
         */
        int getHealth();
        /**
         * @brief Get the if the ship is dead (health = 0)
         * 
         * @return true dead
         * @return false  not dead
         */
        bool getDead();
        /**
         * @brief Print the ship stats
         * 
         */
        void print();
        /**
         * @brief Get the Size 
         * 
         * @return int 
         */
        int getSize();
        /**
         * @brief Get the Id
         * 
         * @return int 
         */
        int getId();
        /**
         * @brief Get the Type
         * 
         * @return int 
         */
        int getType();
        /**
         * @brief Process a hit (take away health and check for death)
         * 
         */
        void hit();
        /**
         * @brief Get the Name 
         * 
         * @return std::string 
         */
        std::string getName();
    };
    

} // namespace BattleShip

#endif
