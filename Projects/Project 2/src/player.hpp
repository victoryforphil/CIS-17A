#ifndef _BS_PLAYER_H_
#define _BS_PLAYER_H_
#include <string>
#include <algorithm>
#include <iostream>
#include <board.hpp>
#include <ship.hpp>

namespace BattleShip{
    class Player{
        
        private:
            std::string mName;
            bool mIsBot = false;
            BattleShip::Ship mShips[];
        public:
        Player(std::string name);
        Player(std::string name, bool isAi);
        void populateShips();
        void print();
        void takeTurn();
        void populateShips();

    }
};

#endif