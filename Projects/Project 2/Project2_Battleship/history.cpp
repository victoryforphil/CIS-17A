#include "history.hpp"

History::History(char *lstPth, char *fullPth)
{
    mFile(lstPth);
}

void History::finishedGame(Player *plyr[2])
{
}
HistoryEntry History::getLastGame()
{
}
HistoryList History::getAllGames()
{
}
History::~History()
{
    mFile.close();
}