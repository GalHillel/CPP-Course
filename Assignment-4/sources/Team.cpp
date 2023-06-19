#include "Team.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <limits>

namespace ariel
{
    Team::Team(Character *leaderChar) : leader(leaderChar)
    {
        add(leader);
    }

    void Team::add(Character *fighter)
    {
        if (fighters.size() >= 10)
        {
            throw std::runtime_error("Maximum number of fighters reached");
        }
        if (fighter->inOtherTeam)
        {
            throw std::runtime_error("Fighter already in another team");
        }
        fighters.push_back(fighter);
        fighter->inOtherTeam = true;
    }

    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("Enemy is nullptr");
        }

        if (enemy->stillAlive() == 0)
        {
            throw std::runtime_error("Enemy team is dead");
        }

        if (stillAlive() == 0)
        {
            throw std::runtime_error("Dead team cannot attack");
        }

        if (enemy == this)
        {
            throw std::invalid_argument("Team cannot attack itself");
        }

        // Check if the leader of the attacking team is alive and Find the living character closest to the dead leader
        if (!leader->isAlive())
        {
            double closestDist = std::numeric_limits<double>::max();
            Character *newLeader = nullptr;
            for (Character *fighter : fighters)
            {
                if (fighter != leader && fighter->isAlive())
                {
                    double dist = leader->distance(fighter);
                    if (dist < closestDist)
                    {
                        closestDist = dist;
                        newLeader = fighter;
                    }
                }
            }

            if (newLeader != nullptr)
            {
                leader = newLeader;
            }
            else
            {
                // No living character found, attack cannot proceed
                return;
            }
        }

        // Find the victim
        Character *victim = nullptr;
        double closestDist = std::numeric_limits<double>::max();
        for (Character *enemyFighter : enemy->fighters)
        {
            if (enemyFighter->isAlive())
            {
                double dist = leader->distance(enemyFighter);
                if (dist < closestDist)
                {
                    closestDist = dist;
                    victim = enemyFighter;
                }
            }
        }

        if (!victim->isAlive())
        {
            throw std::runtime_error("No alive victim found");
        }

        // Attack the victim with all living members of the attacking team
        for (Character *fighter : fighters)
        {
            if (!victim->isAlive())
            {
                if (enemy->stillAlive() == 0)
                {
                    break;
                }

                double closestDist = std::numeric_limits<double>::max();
                for (Character *enemyFighter : enemy->fighters)
                {
                    if (enemyFighter->isAlive())
                    {
                        double dist = leader->distance(enemyFighter);
                        if (dist < closestDist)
                        {
                            closestDist = dist;
                            victim = enemyFighter;
                        }
                    }
                }
            }

            if (fighter->isAlive() && victim->isAlive())
            {
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
                {
                    if (cowboy->hasboolets())
                    {
                        cowboy->shoot(victim);
                    }
                    else
                    {
                        cowboy->reload();
                    }
                }
            }
        }

        for (Character *fighter : fighters)
        {
            if (!victim->isAlive())
            {
                if (enemy->stillAlive() == 0)
                {
                    break;
                }

                double closestDist = std::numeric_limits<double>::max();
                for (Character *enemyFighter : enemy->fighters)
                {
                    if (enemyFighter->isAlive())
                    {
                        double dist = leader->distance(enemyFighter);
                        if (dist < closestDist)
                        {
                            closestDist = dist;
                            victim = enemyFighter;
                        }
                    }
                }
            }

            if (fighter->isAlive() && victim->isAlive())
            {
                if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
                {
                    if (ninja->isAlive() && ninja->distance(victim) <= 1.0)
                    {
                        ninja->slash(victim);
                    }
                    else
                    {
                        ninja->move(victim);
                    }
                }
            }
        }
    }

    int Team::stillAlive()
    {
        int aliveCount = 0;
        for (Character *fighter : fighters)
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
            {
                if (cowboy->isAlive())
                {
                    aliveCount++;
                }
            }
        }

        for (Character *fighter : fighters)
        {
            if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
            {
                if (ninja->isAlive())
                {
                    aliveCount++;
                }
            }
        }
        return aliveCount;
    }

    void Team::print()
    {
        for (Character *fighter : fighters)
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
            {
                cowboy->voidPrint();
            }
        }

        for (Character *fighter : fighters)
        {
            if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
            {
                ninja->voidPrint();
            }
        }
    }

    Team::~Team()
    {
        for (Character *fighter : fighters)
        {
            delete fighter;
        }
    }
}