#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    Character::Character(const std::string &charName, int hp, const Point &loc)
        : name(charName), hitPoints(hp), location(loc)
    {
        inOtherTeam = false;
        type = (hp == 110) ? "Cowboy" : "Ninja";
    }

    bool Character::isAlive() const
    {
        return hitPoints > 0;
    }

    double Character::distance(const Character *other) const
    {
        return location.distance(other->location);
    }

    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw std::invalid_argument("Damage cannot be negative");
        }

        hitPoints -= damage;
    }

    std::string Character::print() const
    {
        std::string type;
        if (isAlive())
        {
            if (dynamic_cast<const Ninja *>(this) != nullptr)
            {
                type = "N";
            }
            else if (dynamic_cast<const Cowboy *>(this) != nullptr)
            {
                type = "C";
            }

            std::string output = type + ": " + getName() + ", Hits: ";
            if (isAlive())
            {
                output += std::to_string(hitPoints);
            }
            else
            {
                output += "-";
            }
            output += ", Position: " + location.toString();

            return output;
        }
        else
        {
            return type + ": " + getName() + " (Dead)";
        }
    }

    void Character::voidPrint() const
    {
        std::string type;
        if (dynamic_cast<const Ninja *>(this) != nullptr)
        {
            type = "N";
        }
        else if (dynamic_cast<const Cowboy *>(this) != nullptr)
        {
            type = "C";
        }
        if (isAlive())
        {
            std::string output = type + ": " + getName() + ", Hits: ";
            if (isAlive())
            {
                output += std::to_string(hitPoints);
            }
            else
            {
                output += "-";
            }
            output += ", Position: " + location.toString();

            cout << output << endl;
        }
        else
        {
            cout << type << ": " + getName() << " (Dead)" << endl;
        }
    }

    void Character::setPosition(const Point &loc)
    {
        location = loc;
    }

    std::string Character::getType() const
    {
        return type;
    }

    int Character::getHitPoints() const
    {
        return hitPoints;
    }

    std::string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }
}