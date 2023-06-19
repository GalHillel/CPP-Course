#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const std::string &name, int hp, const Point &loc, int ninjaSpeed)
        : Character(name, hp, loc), speed(ninjaSpeed) {}

    void Ninja::move(Character *enemy)
    {
        double dist = distance(enemy);
        if (dist < speed)
        {
            Point newPoint = Point::moveTowards(getLocation(), enemy->getLocation(), dist);
            setPosition(newPoint);
        }
        else
        {
            Point newPoint = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
            setPosition(newPoint);
        }
    }

    void Ninja::slash(Character *enemy)
    {
        if (!isAlive())
        {
            throw std::runtime_error("Dead character cannot attack");
        }
        else if (!enemy->isAlive())
        {
            throw std::runtime_error("Cannot attack dead enemy");
        }
        else if (enemy == this)
        {
            throw std::runtime_error("Cannot attack myself");
        }
        else if (isAlive() && distance(enemy) < 1 && enemy->isAlive())
        {
            enemy->hit(40);
        }
    }

}