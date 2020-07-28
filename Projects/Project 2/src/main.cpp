#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#include <board.hpp>
#include <math.hpp>
#include <player.hpp>
#include <ship.hpp>
#include "ships/battleship.hpp"
#include "game"
int main(){

    BattleShip::Battleship bs(1);

    bs.print();
    return 0;
}