#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const std::string &name, const Point &loc)
        : Character(name, 110, loc), bullets(6) {}

    void Cowboy::shoot(Character *enemy)
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
        else if (isAlive() && hasboolets())
        {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasboolets() const
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            std::__throw_runtime_error("Dead Cowboy cannot reload");
        }
        else
        {
            bullets = 6;
        }
    }
}