#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.hpp"

namespace ariel
{
    class Player
    {
    private:
        int stackSize = 0;
        int cardsTaken = 0;
        std::string name;
        std::vector<Card> stack;

    public:
        Player();
        explicit Player(std::string name);
        Player(const Player &player);
        Player(Player &&other) noexcept;
        ~Player();
        std::vector<Card> &getCards();
        std::string getName() const;
        int stacksize();
        int cardesTaken();
        void setCards(std::vector<Card> *deck);
        void setStackSize(int stackSize);
        void setCardsTaken(int cardsTaken);
        Player &operator=(const Player &player);
        Player &operator=(Player &&other) noexcept;
    };
}

#endif