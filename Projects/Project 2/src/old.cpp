#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#include <board.hpp>
#include <math.hpp>
#include <player.hpp>

#include <ship.hpp>


struct GameState
{
    BattleShip::Player plyStates[2];
    int turn = 0;
};

bool checkPlace(PlayerState &state, int sX, int sY, int endX, int endY);
int placeShip(Ship &ship, PlayerState &state);
void populateShips(PlayerState &state);
void genBoard(GameState *state);

void printBoard(PlayerState &state, bool hitboard);

void getChoice(int &xChoice, int &yChoice);
void takeTurn(GameState *state);
bool checkWin(PlayerState &state);



int main()
{
    std::cout << "Greetings Doctor Falkin \n. Shall we play a game? " << std::endl;
    GameState* state;
    std::cout << ">> Generating Player Objects..." << std::endl;
    PlayerState player;
    PlayerState aiPlayer;

    player.name = "Falkin";
    player.isAi = false;

    aiPlayer.name = "Joshua (COM)";
    aiPlayer.isAi = true;
    state = new GameState();
    state->plyStates[0] = player;
    state->plyStates[1] = aiPlayer;

    std::cout << ">> Populating ship array..." << std::endl;
    populateShips(state->plyStates[0]);
    populateShips(state->plyStates[1]);

    std::cout << ">> Setting up board" << std::endl;

    genBoard(state);

    printBoard(state->plyStates[0], false);

    bool hasWon = false;
    while (hasWon == false)
    {
        takeTurn(state);
        //hasWon = checkWin(state.plyStates[0]) && checkWin(state.plyStates[1]);
    }

    return 0;
}

void populateShips(PlayerState &state)
{
    int id = 0;
    Ship cv1;
    cv1.name = "Aircraft Carrier";
    cv1.size = 4;
    cv1.type = Tile::AIRCRAFT_CARRIER;
    cv1.hits = 0;
    cv1.id = id;
    cv1.isDead = false;

    state.ships[0] = cv1;
    id++;

    ///
    Ship bb1;
    bb1.name = "Battleship";
    bb1.size = 3;
    bb1.type = Tile::BATTLESHIP;
    bb1.hits = 0;
    bb1.id = id;
    bb1.isDead = false;

    state.ships[1] = bb1;
    id++;

    Ship bb2;
    bb2.name = "Big Boi (Battleship)";
    bb2.size = 3;
    bb2.type = Tile::BATTLESHIP;
    bb2.hits = 0;
    bb2.id = id;
    bb2.isDead = false;

    state.ships[2] = bb2;
    id++;
    ///

    for (int i = 0; i < 3; i++)
    {
        Ship dd;
        dd.name = "Destroyer";
        dd.size = 2;
        dd.type = Tile::DESTROYER;
        dd.hits = 0;
        dd.isDead = false;
        dd.id = id;
        state.ships[3 + i] = dd;
        id++;
    }

    for (int i = 0; i < 4; i++)
    {
        Ship cr;
        cr.name = "Small Boi (Cruisers)";
        cr.size = 1;
        cr.type = Tile::CRUISER;
        cr.hits = 0;
        cr.isDead = false;
        cr.id = id;
        state.ships[6 + i] = cr;
        id++;
    }
}

bool checkPlace(PlayerState &state, int sX, int sY, int endX, int endY)
{

    sX = std::max(0, sX);
    sY = std::max(0, sY);

    for (int y = 0; y < ((endY - sY) + 1); y++)
    {
        for (int x = 0; x < ((endX - sX) + 1); x++)
        {
            int true_x = sX + x;
            int true_y = sY + y;

            true_x = std::min(9, true_x);
            true_y = std::min(9, true_y);

            if (state.board[std::max(0, true_y - 1)][std::max(0, true_x - 1)] != 0)
            {
                return false;
            }
            if (state.board[std::max(0, true_y)][std::max(0, true_x)] != 0)
            {
                return false;
            }
            if (state.board[std::max(0, true_y + 1)][std::max(0, true_x + 1)] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int placeShip(Ship &ship, PlayerState &state)
{

    int startX = std::rand() % 10;
    int startY = std::rand() % 10;
    int orient = std::rand() % 11;

    int endX = startX + ship.size;
    int endY = startY;

    if (orient < 6)
    {
        endY = startY + ship.size;
        endX = startX;
    }

    bool valid = checkPlace(state, startX, startY, endX, endY);

    if (valid)
    {
        for (int y = 0; y < (endY - startY) + 1; y++)
        {
            for (int x = 0; x < (endX - startX) + 1; x++)
            {
                int trueX = startX + x;
                int trueY = startY + y;
                if (trueX >= 0 && trueY >= 0)
                {
                    state.board[trueY][trueX] = ship.id;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void genBoard(GameState *state)
{
    //Fill board and hit array with 0's

    state->plyStates[0].playBoard->resetBoard(BattleShip::Tile::EMPTY);
    state->plyStates[0].hitBrd->resetBoard(BattleShip::Tile::EMPTY);

    state->plyStates[1].board>resetBoard(BattleShip::Tile::EMPTY);
    state->plyStates[1].hitBrd->resetBoard(BattleShip::Tile::EMPTY);

    std::cout << "\t - Placing ships..." << std::endl;
    
    int cvCount = 0;
    while (cvCount < 1)
    {
        std::cout << "\t - ... Attempting cv placement for player" << std::endl;
        cvCount += placeShip(state->plyStates[0].ships[cvCount], state->plyStates[0]);
    }
    cvCount = 0;
    while (cvCount < 1)
    {
        std::cout << "\t - ... Attempting cv placement for ai" << std::endl;
        cvCount += placeShip(state->plyStates[1].ships[cvCount], state->plyStates[1]);
    }

    std::cout << "\t - Added Aircraft Carriers to board." << std::endl;

    int bbCount = 0;
    while (bbCount < 2)
    {
        std::cout << "\t - ... Attempting Battleships placement for player" << std::endl;
        bbCount += placeShip(state->plyStates[0].ships[bbCount + 1], state->plyStates[0]);
    }
    bbCount = 0;
    while (bbCount < 2)
    {
        std::cout << "\t - ... Attempting Battleships placement for ai" << std::endl;
        bbCount += placeShip(state->plyStates[1].ships[bbCount + 1], state->plyStates[1]);
    }

    std::cout << "\t - Added Battleships to board." << std::endl;
    int ddCount = 0;
    while (ddCount < 3)
    {
        std::cout << "\t - ... Attempting Destroyer placement for player" << std::endl;
        ddCount += placeShip(state->plyStates[0].ships[ddCount + 3], state->plyStates[0]);
    }
    ddCount = 0;
    while (ddCount < 3)
    {
        std::cout << "\t - ... Attempting Destroyer placement for ai" << std::endl;
        ddCount += placeShip(state->plyStates[1].ships[ddCount + 3], state->plyStates[1]);
    }
    std::cout << "\t - Added Destroyers to board." << std::endl;
    int crCount = 0;
    while (crCount < 4)
    {
        std::cout << "\t - ... Attempting Cruiser placement for player" << std::endl;
        crCount += placeShip(state->plyStates[0].ships[crCount + 6], state->plyStates[0]);
    }
    crCount = 0;
    while (crCount < 4)
    {
        std::cout << "\t - ... Attempting Cruiser placement for ai" << std::endl;
        crCount += placeShip(state->plyStates[1].ships[crCount + 6], state->plyStates[1]);
    }
    std::cout << "\t - Added Cruisers to board." << std::endl;
}

void printBoard(PlayerState &state, bool hitBoard)
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {

            int tile = state.board[y][x];
            if (hitBoard)
            {
                tile = state.hitBrd[y][x];
            }
            if (tile != 0 && tile != 5 && !hitBoard)
            {
                tile = state.ships[tile].type; // Get Ship off ID (same as array index)
            }

            switch (tile)
            {
            case Tile::EMPTY:
                std::cout << "`"<< " ";
                break;
            case Tile::AIRCRAFT_CARRIER:
                std::cout << "A" << " ";
                break;
            case Tile::BATTLESHIP:
                std::cout << "B"<< " ";
                break;
            case Tile::DESTROYER:
                std::cout << "D"<< " ";
                break;
            case Tile::CRUISER:
                std::cout << "C" << " ";
                break;
            case Tile::HIT:
                std::cout << "*" << " ";
                break;
            case Tile::MISS:
                std::cout << "o" << std::endl;
            }

            //std::cout << tile << " ";
        }
        std::cout << std::endl;
    }
    if (hitBoard)
    {
        return;
    }
    std::cout << " --- Ships --- " << std::endl;
    std::cout << std::left << std::setw(5) << std::setfill(' ') << "ID" << std::setw(32) << "Name" << std::setw(5) << "Health" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::left << std::setw(5) << std::setfill(' ') << state.ships[i].id << std::setw(32) << state.ships[i].name << std::setw(1) << (state.ships[i].size - state.ships[i].hits) << "/" << state.ships[i].size << std::endl;
    }
}

void getChoice(int &xChoice, int &yChoice)
{
    std::cout << "Please select X/Y Coordinates to strike: " << std::endl;
    do
    {
        std::cout << "X (1-10):";
        std::cin >> xChoice;
    } while (xChoice < 1 || xChoice > 10);
    do
    {

        std::cout << "Y (1-10):";
        std::cin >> yChoice;
    } while (yChoice < 1 || yChoice > 10);
}
void takeTurn(GameState *state)
{
    // Display Hit Board
    // Ask for input
    // Do a check to see if its a hit
    // If its a hit: Mark as hit on the hitboard
    /*
        - Get Ship that was hit
        - Update Ship with --health
        - Check if the ship is dead
        - Check win state, let player continue
    */
    // Else
    if (state->turn == 0)
    { // Human turn
        bool turnOvr = false;
        while (!turnOvr)
        {
            std::cout << "Your turn!" << std::endl;

            std::cout << "Your Hit Board: " << std::endl;
            printBoard(state->plyStates[0], true);

            int choiceX, choiceY;
            getChoice(choiceX, choiceY);

            int tile = state->plyStates[1].board[choiceY - 1][choiceX - 1];

            if (tile == 0)
            {
                std::cout << "MISS!" << std::endl;
                state->plyStates[0].hitBrd[choiceY - 1][choiceX - 1] = Tile::MISS;
                turnOvr = true;
            }
            else
            {
                std::cout << "HIT!" << std::endl;
                state->plyStates[0].hitBrd[choiceY - 1][choiceX - 1] = Tile::HIT;

                state->plyStates[1].ships[tile].hits++;
                if (state->plyStates[1].ships[tile].hits > state->plyStates[1].ships[tile].size)
                {
                    state->plyStates[1].ships[tile].isDead = true;
                    std::cout << "You sunk: " << state->plyStates[1].ships[tile].name;
                }
            }
        }
        state->turn = 1;
    }
    else
    {
         bool turnOvr = false;
        std::cout << "AI is taking turn..." << std::endl;
        while (!turnOvr)
        {
            std::cout << "Your turn!" << std::endl;

         


            int choiceX = 0;
            int choiceY = 0;

            

            int tile = -1;

            do{
                choiceX = std::rand() % 10;;
                choiceY = std::rand() % 10;
                tile = state->plyStates[0].board[choiceY - 1][choiceX - 1];

            }while(tile == Tile::MISS || tile == Tile::HIT);

            if (tile == 0)
            {
                std::cout << "MISS!" << std::endl;
                state->plyStates[1].hitBrd[choiceY - 1][choiceX - 1] = Tile::MISS;
                turnOvr = true;
            }
            else
            {
                std::cout << "HIT!" << std::endl;
                state->plyStates[1].hitBrd[choiceY - 1][choiceX - 1] = Tile::HIT;

                state->plyStates[0].ships[tile].hits++;
                if (state->plyStates[0].ships[tile].hits > state->plyStates[0].ships[tile].size)
                {
                    state->plyStates[0].ships[tile].isDead = true;
                    std::cout << "AI sunk: " << state->plyStates[0].ships[tile].name;
                }
            }
        }
        state->turn = 0;
    }
}

bool checkWin(PlayerState &state)
{
    bool bShipAlive = false;

    for (int i = 0; i < 10; i++)
    {
        Ship _ship = state.ships[i];
        if (_ship.isDead == false)
        {
            bShipAlive = true;
            return bShipAlive;
        }
    }

    return bShipAlive;
}