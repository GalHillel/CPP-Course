#include "card.hpp"
#include <iostream>

namespace ariel
{
    Card::Card() : rank(Ace), shape(Hearts) {}

    Card::Card(Rank rank, Shape shape) : rank(rank), shape(shape) {}

    Card::Card(const Card &card) : rank(card.rank), shape(card.shape) {}

    Card::Card(Card &&other) noexcept
    {
        this->rank = other.rank;
        this->shape = other.shape;
    }

    Card &Card::operator=(const Card &other)
    {
        if (this != &other)
        {
            this->rank = other.rank;
            this->shape = other.shape;
        }
        return *this;
    }

    Card &Card::operator=(Card &&other) noexcept
    {
        if (this != &other)
        {
            this->rank = other.rank;
            this->shape = other.shape;
        }
        return *this;
    }

    Rank Card::getRank() { return this->rank; }

    Shape Card::getShape() { return this->shape; }

    std::string Card::toString()
    {
        std::string rank_str;
        switch (rank)
        {
        case Ace:
            rank_str = "Ace";
            break;
        case Two:
            rank_str = "Two";
            break;
        case Three:
            rank_str = "Three";
            break;
        case Four:
            rank_str = "Four";
            break;
        case Five:
            rank_str = "Five";
            break;
        case Six:
            rank_str = "Six";
            break;
        case Seven:
            rank_str = "Seven";
            break;
        case Eight:
            rank_str = "Eight";
            break;
        case Nine:
            rank_str = "Nine";
            break;
        case Ten:
            rank_str = "Ten";
            break;
        case Jack:
            rank_str = "Jack";
            break;
        case Queen:
            rank_str = "Queen";
            break;
        case King:
            rank_str = "King";
            break;
        }

        std::string shape_str;
        switch (shape)
        {
        case Hearts:
            shape_str = "Hearts";
            break;
        case Diamonds:
            shape_str = "Diamonds";
            break;
        case Clubs:
            shape_str = "Clubs";
            break;
        case Spades:
            shape_str = "Spades";
            break;
        }

        return rank_str + " of " + shape_str;
    }

    Card::~Card() {}
}
