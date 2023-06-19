#include "doctest.h"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"

using namespace ariel;

TEST_CASE("Test player")
{
    Player p("John");
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p.getName() == "John");
    CHECK(p1.getName() == "Alice");
    CHECK(p2.getName() == "Bob");
    CHECK(p.cardesTaken() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p.stacksize() == 0);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    Game g(p1, p2);
    for (int i = 0; i < 10; i++)
    {
        g.playTurn();
        CHECK(g.getTurn1() > i);
        g.playTurn();
        CHECK(g.getTurn2() > i);
    }
}

TEST_CASE("Test card")
{
    Card c(Shape::SPADE, Rank::ACE);
    Card c1(Shape::HEART, Rank::KING);
    Card c2(Shape::DIAMOND, Rank::QUEEN);
    CHECK(c.getShape() == Shape::SPADE);
    CHECK(c1.getShape() == Shape::HEART);
    CHECK(c2.getShape() == Shape::DIAMOND);
    CHECK(c.getRank() == Rank::ACE);
    CHECK(c1.getRank() == Rank::KING);
    CHECK(c2.getRank() == Rank::QUEEN);
}

TEST_CASE("Test game")
{
    Player p1("John");
    Player p2("Jane");
    Game g(p1, p2);
    Player p3("Alice");
    Player p4("Bob");
    Game g1(p3, p4);
    CHECK(g.getPLayer1().getName() == "John");
    CHECK(g.getPLayer2().getName() == "Jane");
    CHECK(g1.getPLayer1().getName() == "Alice");
    CHECK(g1.getPLayer2().getName() == "Bob");
}