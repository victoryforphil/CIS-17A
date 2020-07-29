#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>

#include "battleship.hpp"

#include "player.hpp"

/**
 * @brief Master GameState Struct
 * 
 */
struct GameState
{
    BSGame::Player* plyStates[2];
    int turn = 0;
};


int main(){
    std::cout << std::endl;
    std::cout << ">> Battle Ship | CIS-17A Project #2 | Vesion: 0.2 | Version Note: Better Displaying" << std::endl;
    std::cout << std::endl;
    std::cout << ">> Generating Player Objects..." << std::endl;
    GameState* state;


    state = new GameState();
    state->plyStates[0] = new BSGame::Player("Falkin");
    state->plyStates[1] = new BSGame::Player("Joshua", true);

    std::cout << ">> Populating ship array..." << std::endl;

    state->plyStates[0]->populateShips();
    state->plyStates[1]->populateShips();
    state->plyStates[0]->printShips();
    
    std::cout << ">> Setting up board" << std::endl;

    state->plyStates[0]->genBoard();
    state->plyStates[1]->genBoard();
    state->plyStates[0]->displayBoard(false);

    bool bothAlive = true;
    while (bothAlive)
    {
        state->plyStates[state->turn]->takeTurn(state->plyStates[state->turn == 0 ? 1:0]);
        state->turn = state->turn == 0 ? 1:0;
        //takeTurn(state);
        //saveState(state);
        bothAlive = state->plyStates[0]->isAlive() && state->plyStates[1]->isAlive();
    }

    return 0;
}