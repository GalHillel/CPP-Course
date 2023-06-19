#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &loc);
    };
}

#endif