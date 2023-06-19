#include "doctest.h"
#include "sources/MagicalContainer.hpp"

bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

TEST_CASE("MagicalContainer - Add Element")
{
    ariel::MagicalContainer container;

    CHECK(container.size() == 0);
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    CHECK(container.size() == 3);
    for (int i = 0; i < 20; i++)
    {
        CHECK_NOTHROW(container.addElement(i));
    }
}

TEST_CASE("MagicalContainer - Remove Element")
{
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    CHECK(container.size() == 3);
    container.removeElement(10);
    CHECK(container.size() == 2);
    container.removeElement(5);
    container.removeElement(15);
    CHECK(container.size() == 0);
    for (int i = 0; i < 20; i++)
    {
        container.addElement(i);
    }

    for (int i = 0; i < 20; i++)
    {
        CHECK_NOTHROW(container.removeElement(i));
        CHECK(container.size() == 19 - i);
    }
}

TEST_CASE("MagicalContainer - Ascending Iterator")
{
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    container.addElement(20);

    ariel::MagicalContainer::AscendingIterator iter(container);

    CHECK(*iter == 5);
    ++iter;
    CHECK(*iter == 10);
    ++iter;
    CHECK(*iter == 15);
    ++iter;
    CHECK(*iter == 20);
}

TEST_CASE("MagicalContainer - Side Cross Iterator")
{
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    container.addElement(20);

    ariel::MagicalContainer::SideCrossIterator iter(container);

    CHECK(*iter == 5);
    ++iter;
    CHECK(*iter == 20);
    ++iter;
    CHECK(*iter == 10);
    ++iter;
    CHECK(*iter == 15);
}

TEST_CASE("MagicalContainer - Prime Iterator")
{
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(10);
    container.addElement(11);
    container.addElement(15);
    container.addElement(17);

    ariel::MagicalContainer::PrimeIterator iter(container);

    CHECK(*iter == 5);
    ++iter;
    CHECK(*iter == 11);
    ++iter;
    CHECK(*iter == 17);

    ariel::MagicalContainer container1;

    for (int i = 2; i < 50; i++)
    {
        container1.addElement(i);
    }

    ariel::MagicalContainer::PrimeIterator iter1(container1);

    for (int i = 0; i < 15; i++)
    {
        CHECK(isPrime(*iter1));
        ++iter1;
    }
}