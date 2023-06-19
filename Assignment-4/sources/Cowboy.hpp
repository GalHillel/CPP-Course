#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(const std::string &name, const Point &loc);
        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
    };
}

#endif