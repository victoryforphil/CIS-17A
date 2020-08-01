#include "player.hpp"
#include <iostream>
#include <iomanip>
#include <random>
using namespace BSGame;

Player::Player(std::string name)
{

    mName = name;
    mIsBot = false;
}
Player::Player(std::string name, bool isAi)
{
    mName = name;
    mIsBot = isAi;
}
void Player::populateShips()
{
    int id = 10;
    for (int i = 0; i < 1; i++)
    {
        mShips[id - 10] = new BSGame::Carrier(id);
        id++;
    }
    for (int i = 0; i < 2; i++)
    {
        mShips[id - 10] = new BSGame::Battleship(id);
        id++;
    }
    for (int i = 0; i < 3; i++)
    {
        mShips[id - 10] = new BSGame::Destroyer(id);
        id++;
    }
    for (int i = 0; i < 4; i++)
    {
        mShips[id - 10] = new BSGame::Cruiser(id);
        id++;
    }
}

void Player::print()
{
    std::cout << "print()" << std::endl;
}

void Player::printShips()
{
    std::cout << " --- Ships --- " << std::endl;
    std::cout << std::left << std::setw(5) << std::setfill(' ') << "ID" << std::setw(32) << "Name" << std::setw(5) << "Health" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::left << std::setw(5) << std::setfill(' ') << mShips[i]->getId()
                  << std::setw(32) << mShips[i]->getName() << std::setw(1)
                  << mShips[i]->getHealth() << "/" << mShips[i]->getSize() << std::endl;
    }
}

void Player::takeTurn(Player* othPlyr)
{
    bool turnOvr = false;
  
    while (!turnOvr)
    {
        std::cout << std::endl;
        std::cout << std::endl;
        if(!mIsBot){
             std::cout << "Your turn!" << std::endl;

            std::cout << "Your Hit Board: " << std::endl;
            displayBoard(true);
            printShips();
        }else{
            std::cout << "Computer's Turn" << std::endl;
        }

        BSVector2 choice(0,0);
        if(!mIsBot){
            getChoice(choice);
        }else{
           
            choice.setX(std::rand() % 15);
            choice.setY(std::rand() % 15);
        }


        int tile = othPlyr->getPrivateBoard()->getTile(choice);
       
        if (tile == Tile::EMPTY)
        {
            std::cout << "MISS!" << std::endl;
            getHitBoard()->setTile(choice, MISS);
            turnOvr = true;
        }
        else
        {
            std::cout << "HIT!" << std::endl;
            getHitBoard()->setTile(choice, HIT);
            std::cout << tile << std::endl;


            othPlyr->getShip(tile - 10)->hit();
            std::cout << "You Hit: " << othPlyr->getShip(tile - 10)->getName();
            
            if ( othPlyr->getShip(tile - 10)->getDead())
            {
                std::cout << "You sunk: " << othPlyr->getShip(tile - 10)->getName();
            }
            
        }
    }
}
bool Player::isAlive(){
    bool bShipAlive = false;

    for (int i = 0; i < 10; i++)
    {
        Ship* _ship = mShips[i];
        if (_ship->getDead() == false)
        {
            bShipAlive = true;
            return bShipAlive;
        }
    }

    return bShipAlive;
}
void Player::getChoice(BSVector2 &choice)
{
    std::cout << "Please select X/Y Coordinates to strike: " << std::endl;
    int val;
    do
    {
     
        std::cout << "X (1-15):";
        std::cin >> val;
        choice.setX(val - 1);
    } while (val < 1 || val > 15);
    val = 0;
    do
    {
        
        std::cout << "Y (1-15):";
        std::cin >> val;
        choice.setY(val - 1);
    } while (val < 1 || val > 15);
}

bool Player::checkPlace(BSVector2 start, BSVector2 end)
{
    start.clampMin(0);

    for (int y = 0; y < ((end.y() - start.y()) + 1); y++)
    {
        for (int x = 0; x < ((end.x() - start.x()) + 1); x++)
        {
            BSVector2 trueVec(start.x() + x, start.y() + y);
            trueVec.clampMax(14);

            BSVector2 testVec(trueVec.x(), trueVec.y());

            // Loop through top left, middle and bottom right coorindates for tiles to ceheck
            for (int i = 0; i < 2; i++)
            {
                testVec.setX(testVec.x() + (-1 + i));
                testVec.setY(testVec.y() + (-1 + i));
                testVec.clampMin(0);
                //std::cout << ">>DEBUG>> - Place Test: " << testVec.x()<<"/" << testVec.y() << " = " << getPrivateBoard()->getTile(testVec) << std::endl;
                if (getPrivateBoard()->getTile(testVec) != Tile::EMPTY)
                {
                    return false;
                }

                testVec.setX(testVec.x() - (-1 + i));
                testVec.setY(testVec.y() - (-1 + i));
                testVec.clampMin(0);
                //std::cout << ">>DEBUG>> - Place Test: " << testVec.x()<<"/" << testVec.y() << " = " << getPrivateBoard()->getTile(testVec) << std::endl;
                if (getPrivateBoard()->getTile(testVec) != Tile::EMPTY)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int Player::placeShip(Ship *ship)
{
    BSVector2 start(std::rand() % 15, std::rand() % 15);
    int orient = std::rand() % 15;
    //std::cout << ">>DEBUG>> - START: " << start.x()<<"/" << start.y() << " = " << ship->getName() << std::endl;
    BSVector2 end(start.x(), start.y());

    if (orient < 6)
    {
        end.setY(end.y() + 1);
        end.setX(end.x() + ship->getSize());
    }
    else
    {
        end.setX(end.x() + 1);
        end.setY(end.y() + ship->getSize());
    }

    if (end.x() >= 15 || end.y() >= 15)
    {
        return 0;
    }
    // std::cout << ">>DEBUG>> - END: " << end.x()<<"/" << end.y() << " = " << ship->getName() << std::endl;

    bool valid = checkPlace(start, end);

    if (valid)
    {
        BSVector2 trueVec(start.x(), start.y());
        for (int y = 0; y < (end.y() - start.y()); y++)
        {
            for (int x = 0; x < (end.x() - start.x()); x++)
            {
                trueVec.update(start.x() + x, start.y() + y);
                //std::cout << ">>DEBUG>> - Delta X/Y: " << x<<"/" << y << " = " << ship->getName() << std::endl;

                //std::cout << ">>DEBUG>> - True Vec: "<< trueVec.x()<<"/" << trueVec.y() << " = " << ship->getName() << std::endl;
                getPrivateBoard()->setTile(trueVec, ship->getId());
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void Player::genBoard()
{
    mBoard = new Board();
    mHitBrd = new Board();

    int cvCount = 0;
    while (cvCount != 1)
    {
        std::cout << "\t - ... Attempting cv placement for player" << std::endl;
        cvCount += placeShip(mShips[cvCount]);
    }

    std::cout << "\t - Added Aircraft Carriers to board." << std::endl;

    int bbCount = 0;
    while (bbCount < 2)
    {
        std::cout << "\t - ... Attempting Battleships placement for player" << std::endl;
        bbCount += placeShip(mShips[bbCount + 1]);
    }

    std::cout << "\t - Added Battleships to board." << std::endl;
    int ddCount = 0;
    while (ddCount < 3)
    {
        std::cout << "\t - ... Attempting Destroyer placement for player" << std::endl;
        ddCount += placeShip(mShips[ddCount + 3]);
    }

    std::cout << "\t - Added Destroyers to board." << std::endl;
    int crCount = 0;
    while (crCount < 4)
    {
        std::cout << "\t - ... Attempting Cruiser placement for player" << std::endl;
        crCount += placeShip(mShips[crCount + 6]);
    }

    std::cout << "\t - Added Cruisers to board." << std::endl;
}
void Player::displayBoard(bool hitBoard)
{

    Board *refBrd = getPrivateBoard();
    if (hitBoard)
    {
        refBrd = getHitBoard();
    }
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 15; x++)
        {

            int tile = refBrd->getTile(BSVector2(x, y));

            if (tile != 0 && tile >= 10 && !hitBoard)
            {
                // std::cout << " - - - " << "Converting " << tile << " to " << mShips[tile]->getName() << std::endl;
                tile = mShips[tile - 10]->getType(); // Get Ship off ID (same as array index)
            }

            switch (tile)
            {
            case Tile::EMPTY:
                std::cout << "`"
                          << " ";
                break;
            case Tile::AIRCRAFT_CARRIER:
                std::cout << "A"
                          << " ";
                break;
            case Tile::BATTLESHIP:
                std::cout << "B"
                          << " ";
                break;
            case Tile::DESTROYER:
                std::cout << "D"
                          << " ";
                break;
            case Tile::CRUISER:
                std::cout << "C"
                          << " ";
                break;
            case Tile::HIT:
                std::cout << "*"
                          << " ";
                break;
            case Tile::MISS:
                std::cout << "o"
                          << " ";
                break;
            default:
                std::cout << "! ";
                break;
            }
        }
        std::cout << std::endl;
    }
}
Board *Player::getPrivateBoard()
{
    return mBoard;
}
Board *Player::getHitBoard()
{
    return mHitBrd;
}

std::string Player::getName(){
    return mName;
}

Ship* Player::getShip(int id){
    return mShips[id];
}