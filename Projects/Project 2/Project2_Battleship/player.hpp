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
    /**
     * @brief Player Class, responsible for more game logic
     * 
     */
    class Player
    {
        
    private:
        std::string mName; 
        bool mIsBot = false;
        Ship* mShips[10];
        Board* mBoard;
        Board* mHitBrd;

  

    public:
        /**
         * @brief Construct a new Player object(Simple Version)
         * 
         * @param name player name
         */
        Player(std::string name);
        /**
         * @brief Construct a new Player object (AI Version)
         * 
         * @param name player name
         * @param isAi  is the play AI controlled
         */
        Player(std::string name, bool isAi);
        /**
         * @brief Generate all required ship objects
         * 
         */
        void populateShips();
        
        void print();
        /**
         * @brief Get a coordinate selection from the use
         * 
         * @param result refrence to the output result
         */
        void getChoice(BSVector2& result);
        /**
         * @brief Take a turn in the game
         * 
         * @param othPlyr other components, used to check for hits/misses
         */
        void takeTurn(Player* othPlyr);
        /**
         * @brief Print the current ships statistics
         * 
         */
        void printShips();
        /**
         * @brief Check if a range of vectors (start -> end) is clear to place a ship
         * 
         * @param start start position to check
         * @param end end position to check
         * @return true is a valid placement
         * @return false is an invalid placement
         */
        bool checkPlace(BSVector2 start, BSVector2 end);
        /**
         * @brief Places a ship in randomly selected spot
         * 
         * @param ship ship refrence to place
         * @return int 1 = successfully placed, 0 = unsuccessful placement
         */
        int placeShip(Ship* ship);
        
        /**
         * @brief prints a board, either the ship board (private board) or the hit board
         * 
         * @param hitBoard display the hitboard
         */
        void displayBoard(bool hitBoard);

        /**
         * @brief Generate a initial board with random ship placement
         * 
         */
        void genBoard();

        /**
         * @brief Returns if the player has any ships left
         * 
         * @return true ships are still alive
         * @return false all ships are dead
         */
        bool isAlive();
        /**
         * @brief Get the Private Board object
         * 
         * @return Board* 
         */
        Board* getPrivateBoard();
        /**
         * @brief Get the Hit Board object
         * 
         * @return Board* 
         */
        Board* getHitBoard();
        std::string getName();
        /**
         * @brief Get the Ship object
         * 
         * @param id the id of the ship
         * @return Ship* 
         */
        Ship* getShip(int id);
    };
}; // namespace BSGame

#endif