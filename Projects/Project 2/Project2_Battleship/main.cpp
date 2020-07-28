#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>

#include "battleship.hpp"

#include "player.hpp"


struct GameState
{
    BSGame::Player* plyStates[2];
    int turn = 0;
};
int main(){

    std::cout << ">> Generating Player Objects..." << std::endl;
    GameState* state;


    state = new GameState();
    state->plyStates[0] = new BSGame::Player("Falkin");
    state->plyStates[1] = new BSGame::Player("Joshua", true);

    std::cout << ">> Populating ship array..." << std::endl;

    state->plyStates[0]->populateShips();
    
    state->plyStates[0]->printShips();
    

    return 0;
}