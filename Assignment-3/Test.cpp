#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Creating fractions")
{
    CHECK_NOTHROW(Fraction(3, 4));
    CHECK_THROWS_AS(Fraction(1, 0), std::invalid_argument);
}

TEST_CASE("Adding fractions")
{
    Fraction a(1, 2), b(1, 3);
    CHECK((a + b) == Fraction(5, 6));

    Fraction c(-3, 4), d(1, 4);
    CHECK((c + d) == Fraction(-1, 2));
}

TEST_CASE("Subtracting fractions")
{
    Fraction a(1, 2), b(1, 3);
    CHECK((a - b) == Fraction(1, 6));

    Fraction c(-3, 4), d(1, 4);
    CHECK((c - d) == Fraction(-1, 1));
}

TEST_CASE("Multiplying fractions")
{
    Fraction a(1, 2), b(1, 3);
    CHECK((a * b) == Fraction(1, 6));

    Fraction c(-3, 4), d(1, 4);
    CHECK((c * d) == Fraction(-3, 16));
}

TEST_CASE("Dividing fractions")
{
    Fraction a(1, 2), b(1, 3);
    CHECK((a / b) == Fraction(3, 2));

    Fraction c(-3, 4), d(1, 4);
    CHECK((c / d) == Fraction(-3, 1));
}

TEST_CASE("Multiplying fraction with double")
{
    Fraction a(1, 2);
    double b = 2.5;
    CHECK((a * b) == Fraction(25, 20));
}

TEST_CASE("Multiplying double with fraction")
{
    Fraction a(1, 2);
    double b = 2.5;
    CHECK((b * a) == Fraction(25, 20));
}

TEST_CASE("Adding fraction with double")
{
    Fraction a(1, 2);
    double b = 0.5;
    CHECK((a + b) == Fraction(1, 1));
}

TEST_CASE("Subtracting fraction with double")
{
    Fraction a(1, 2);
    double b = 0.25;
    CHECK((a - b) == Fraction(1, 4));
}

TEST_CASE("Comparing fractions")
{
    Fraction a(1, 2), b(1, 3), c(2, 4);
    CHECK(a == c);
    CHECK(a != b);
    CHECK(a > b);
    CHECK(a >= b);
}

TEST_CASE("Comparing fraction with double")
{
    Fraction a(3, 4);
    double b = 0.5;
    CHECK(a > b);
}

TEST_CASE("Multiplication Operator")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 5);
    Fraction f4(6, 20);

    CHECK(f1 * f2 == Fraction(3, 8));
    CHECK(f1 * f3 == Fraction(1, 5));
    CHECK(f2 * f3 == Fraction(3, 10));
    CHECK(f1 * f4 == Fraction(3, 20));
}

TEST_CASE("Division Operator")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 5);
    Fraction f4(6, 20);

    CHECK(f1 / f2 == Fraction(2, 3));
    CHECK(f1 / f3 == Fraction(5, 4));
    CHECK(f2 / f3 == Fraction(15, 8));
    CHECK(f1 / f4 == Fraction(5, 3));
}

TEST_CASE("Multiplication Operator with Double")
{
    Fraction f1(1, 2);
    double d1 = 2.5;
    double d2 = 0.5;

    CHECK(f1 * d1 == Fraction{25, 20});
    CHECK(f1 * d2 == Fraction{25, 100});
}

TEST_CASE("Multiplication Operator with Double (commutative)")
{
    Fraction f1(1, 2);
    double d1 = 2.5;
    double d2 = 0.5;

    CHECK(d1 * f1 == Fraction(25, 20));
    CHECK(d2 * f1 == Fraction(25, 100));
}

TEST_CASE("Addition Operator with Double")
{
    Fraction f1(1, 2);
    double d1 = 2.5;
    double d2 = 0.5;

    CHECK(f1 + d1 == Fraction(3, 1));
    CHECK(f1 + d2 == Fraction(1, 1));
}

TEST_CASE("Subtraction Operator with Double")
{
    Fraction f1(1, 2);
    double d1 = 2.5;
    double d2 = 0.5;

    CHECK(f1 - d1 == Fraction(-4, 2));
    CHECK(f1 - d2 == Fraction(0, 1));
}

TEST_CASE("Equality Operator")
{
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(3, 5);

    CHECK(f1 == f2);
    CHECK(f2 == f1);
    CHECK_FALSE(f1 == f3);
}