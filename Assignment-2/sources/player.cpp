#include "player.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace ariel
{
    Player::Player() : name("") {}

    Player::Player(std::string name) : name(name) {}

    Player::Player(const Player &player) : name(player.getName()), stackSize(player.stackSize), cardsTaken(player.cardsTaken), stack(player.stack) {}

    Player::Player(Player &&other) noexcept : name(std::move(other.name)), stackSize(std::move(other.stackSize)), cardsTaken(std::move(other.cardsTaken)), stack(std::move(other.stack)) {}

    Player::~Player() {}

    void Player::setCards(std::vector<Card> *newStack) { this->stack = *newStack; }

    std::vector<Card> &Player::getCards() { return stack; }

    std::string Player::getName() const { return this->name; }

    int Player::stacksize() { return this->stackSize; }

    int Player::cardesTaken() { return this->cardsTaken; }

    void Player::setCardsTaken(int cards) { this->cardsTaken = cards; }

    void Player::setStackSize(int stack) { this->stackSize = stack; }

    Player &Player::operator=(const Player &player)
    {
        if (this == &player)
        {
            return *this;
        }
        this->stackSize = player.stackSize;
        this->cardsTaken = player.cardsTaken;
        this->name = player.name;
        this->stack = player.stack;
        return *this;
    }

    Player &Player::operator=(Player &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        this->name = std::move(other.name);
        this->stackSize = std::move(other.stackSize);
        this->cardsTaken = std::move(other.cardsTaken);
        this->stack = std::move(other.stack);
        return *this;
    }
}