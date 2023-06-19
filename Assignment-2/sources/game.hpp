#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.hpp"

namespace ariel
{
    class Game
    {
    private:
        Player &player1;
        Player &player2;
        std::string log;
        std::string lastTurn;
        bool tie;
        int numOfTie;
        int draws;
        int turns;
        int p1Wins;
        int p2Wins;
        int p1CardsWon;
        int p2CardsWon;

    public:
        Game();
        Game(Player &player1, Player &player2);
        Game(const Game &other);
        Game &operator=(const Game &other);
        Game(Game &&other) noexcept;
        Game &operator=(Game &&other) noexcept;
        ~Game();
        int playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        Player getFirstPlayer();
        Player getSecondPlayer();
    };
}

#endif
