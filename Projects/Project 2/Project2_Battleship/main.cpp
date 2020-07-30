#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>

#include "battleship.hpp"
#include "history.hpp"
#include "player.hpp"

/**
 * @brief Master GameState Struct
 * 
 */
struct GameState
{
    BSGame::Player* plyers[2];
    int turn = 0;
    
};



int main(){
    std::cout << std::endl;
    std::cout << ">> Battle Ship | CIS-17A Project #2 | Vesion: 0.2 | Version Note: File Loading, Variable Name Cleansing, and Documentation" << std::endl;
    std::cout << std::endl;
    std::cout << ">> Generating Player Objects..." << std::endl;
    GameState* state;
    BSGame::History history("last_game.bin", "all_games.bin");

    state = new GameState();
    state->plyers[0] = new BSGame::Player("Falkin");
    state->plyers[1] = new BSGame::Player("Joshua", true);

    std::cout << ">> Populating ship array..." << std::endl;

    state->plyers[0]->populateShips();
    state->plyers[1]->populateShips();
    state->plyers[0]->printShips();
    
    std::cout << ">> Setting up board" << std::endl;

    state->plyers[0]->genBoard();
    state->plyers[1]->genBoard();
    state->plyers[0]->displayBoard(false);

    bool bothAlive = true;
    while (bothAlive)
    {
        state->plyers[state->turn]->takeTurn(state->plyers[state->turn == 0 ? 1:0]);
        state->turn = state->turn == 0 ? 1:0;
        //takeTurn(state);
        //saveState(state);
        bothAlive = state->plyers[0]->isAlive() && state->plyers[1]->isAlive();
    }
    delete[] state->plyers;
    delete state;
    return 0;
}