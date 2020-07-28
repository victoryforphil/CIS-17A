#ifndef _BS_PLAYER_H_
#define _BS_PLAYER_H_
#include <string>
#include <algorithm>
#include <iostream>
#include "player.hpp"
#include "board.hpp"

#include "battleship.hpp"
namespace BSGame
{
    class Player
    {

    private:
        std::string mName;
        bool mIsBot = false;
        Ship* mShips[10];

    public:
        Player(std::string name);
        Player(std::string name, bool isAi);
        void populateShips();
        void print();
        void takeTurn();
        void printShips();
    };
}; // namespace BSGame

#endif