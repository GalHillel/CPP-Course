#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        using Team::Team;

        void attack(Team *enemy) override
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

                // If a new leader is found, set it as the leader of the team
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

            // Find the victim (living enemy character closest to the leader)
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
                    else if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
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

        void print() override
        {
            for (Character *fighter : fighters)
            {
                fighter->voidPrint();
            }
        }

        int stillAlive() override
        {
            int aliveCount = 0;
            for (Character *fighter : fighters)
            {
                if (fighter->isAlive())
                {
                    aliveCount++;
                }
            }
            return aliveCount;
        }
    };
}

#endif