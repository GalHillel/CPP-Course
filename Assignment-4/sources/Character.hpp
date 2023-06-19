#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel
{
    class Character
    {
    private:
        std::string name;
        std::string type;
        int hitPoints;
        Point location;

    public:
        Character(const std::string &charName, int hp, const Point &loc);
        virtual ~Character() = default;
        int getHitPoints() const;
        bool isAlive() const;
        bool inOtherTeam;
        double distance(const Character *other) const;
        void hit(int damage);
        void setPosition(const Point &loc);
        void voidPrint() const;
        Point getLocation() const;
        std::string getName() const;
        std::string getType() const;
        std::string print() const;
    };
}

#endif