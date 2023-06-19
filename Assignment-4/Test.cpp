
#include "doctest.h"
#include "sources/Team.hpp"

namespace ariel
{
    TEST_CASE("Point class")
    {
        SUBCASE("Distance calculation")
        {
            Point p1(0, 0);
            Point p2(3, 4);
            Point p3(10, 20);
            CHECK(p1.distance(p2) == 5);
            CHECK(p2.distance(p1) == 5);
            CHECK(p1.distance(p3) == sqrt(500));
            CHECK(p3.distance(p1) == sqrt(500));
        }
    }

    TEST_CASE("Cowboy class")
    {
        Cowboy cowboy1("John", Point(0, 0));
        Cowboy cowboy2("Tom", Point(10, 20));

        SUBCASE("Initial properties")
        {
            CHECK(cowboy1.getName() == "John");
            CHECK(cowboy1.hasboolets() == true);
            CHECK(cowboy2.getName() == "Tom");
            CHECK(cowboy2.hasboolets() == true);
        }

        SUBCASE("Shoot method")
        {
            Cowboy target("Target", Point(3, 4));
            for (int i = 0; i < 6; i++)
            {
                cowboy1.shoot(&target);
                cowboy2.shoot(&target);
            }
            CHECK(cowboy1.hasboolets() == false);
            CHECK(cowboy2.hasboolets() == false);
        }

        SUBCASE("Reload method")
        {
            cowboy1.reload();
            CHECK(cowboy1.hasboolets() == true);
            cowboy2.reload();
            CHECK(cowboy2.hasboolets() == true);
        }
    }

    TEST_CASE("OldNinja class")
    {
        OldNinja ninja("Old Ninja", Point(0, 0));

        SUBCASE("Initial properties")
        {
            CHECK(ninja.getName() == "Old Ninja");
        }

        SUBCASE("Slash method")
        {
            Cowboy target("Target", Point(1, 0));
            CHECK(target.isAlive() == true);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            CHECK(target.isAlive() == false);
        }
    }

    TEST_CASE("YountNinja class")
    {
        YoungNinja ninja("Yount Ninja", Point(0, 0));

        SUBCASE("Initial properties")
        {
            CHECK(ninja.getName() == "Yount Ninja");
        }

        SUBCASE("Slash method")
        {
            Cowboy target("Target", Point(1, 0));
            CHECK(target.isAlive() == true);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            CHECK(target.isAlive() == false);
        }
    }

    TEST_CASE("TrainedNinja class")
    {
        TrainedNinja ninja("Trained Ninja", Point(0, 0));

        SUBCASE("Initial properties")
        {
            CHECK(ninja.getName() == "Trained Ninja");
        }

        SUBCASE("Slash method")
        {
            Cowboy target("Target", Point(1, 0));
            CHECK(target.isAlive() == true);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            ninja.slash(&target);
            CHECK(target.isAlive() == false);
        }
    }

}
