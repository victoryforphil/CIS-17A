#ifndef _BS_PLAYER_H_
#define _BS_PLAYER_H_
#include <string>
#include <algorithm>
#include <iostream>
#include "player.hpp"
#include "board.hpp"

#include "carrier.hpp"
#include "cruiser.hpp"
#include "destroyer.hpp"
#include "battleship.hpp"
namespace BSGame
{
    class Player
    {

    private:
        std::string mName;
        bool mIsBot = false;
        Ship* mShips[10];
        Board* mBoard;
        Board* mHitBrd;

  

    public:
        Player(std::string name);
        Player(std::string name, bool isAi);
        void populateShips();
        void print();
        void getChoice(BSVector2& result);
        void takeTurn();
        void printShips();
        bool checkPlace(BSVector2 start, BSVector2 end);
        int placeShip(Ship* ship);

        void displayBoard(bool hitBoard);

        void genBoard();

        Board* getPrivateBoard();
        Board* getHitBoard();
    };
}; // namespace BSGame

#endif