#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &loc);
    };
}

#endif