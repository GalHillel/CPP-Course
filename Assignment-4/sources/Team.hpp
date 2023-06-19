#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

namespace ariel
{
    class Team
    {
    public:
        std::vector<Character *> fighters;
        Character *leader;
        Team(Character *leaderChar);
        void add(Character *fighter);
        virtual void attack(Team *enemy);
        virtual int stillAlive();
        virtual void print();
        virtual ~Team();
    };
}

#endif