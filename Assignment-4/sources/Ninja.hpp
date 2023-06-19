#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(const std::string &name, int hp, const Point &loc, int ninjaSpeed);
        void move(Character *enemy);
        void slash(Character *enemy);
    };
}

#endif