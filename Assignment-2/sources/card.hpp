#ifndef CARD_H
#define CARD_H

#include <string>

namespace ariel
{
    enum Rank
    {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };
    enum Shape
    {
        Hearts,
        Diamonds,
        Clubs,
        Spades
    };

    class Card
    {
    private:
        Rank rank;
        Shape shape;

    public:
        Card();
        Card(Rank rank, Shape shape);
        Card(const Card &other);
        Card(Card &&other) noexcept;
        Card &operator=(const Card &other);
        Card &operator=(Card &&other) noexcept;
        ~Card();
        Rank getRank();
        Shape getShape();
        std::string toString();
    };
}

#endif
