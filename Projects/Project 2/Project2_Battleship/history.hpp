#ifndef _HISTORY_H_
#define _HISTORY_H_
#include "player.hpp"
#include <fstream>
namespace BSGame
{
    struct HistoryEntry
    {
        std::string winner;
        int shipLft;
    };

    struct HistoryList
    {
        HistoryEntry history[10];
    };

    class History
    {
    private:
        std::ifstream mFile;
    public:
        History(char* lstPth, char* fullPth);
        void finishedGame(Player* plyrs[2]);
        HistoryEntry getLastGame();
        HistoryList getAllGames();

        ~History();
    };

  
} // namespace BSGame

#endif