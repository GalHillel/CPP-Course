#include "MagicalContainer.hpp"

using namespace std;

namespace ariel
{
    // Helper function to check if a number is prime
    bool MagicalContainer::isPrime(int num)
    {
        if (num < 0)
            num = -num;

        if (num <= 1)
        {
            return false;
        }

        for (int i = 2; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    // Adds an element to the container
    void MagicalContainer::addElement(int element)
    {
        auto in = elements.insert(element);

        if (in.second)
        {
            const int *address = &(*in.first);

            // Insert the element into elementsAscend vector while maintaining the ascending order
            elementsAscend.insert(
                upper_bound(elementsAscend.begin(), elementsAscend.end(), address, [](const int *a, const int *b)
                            { return *a < *b; }),
                address);

            elementsSidecross.clear();
            elementsSidecross.reserve(elementsAscend.size());

            size_t start = 0, end = elementsAscend.size() - 1;

            if (isPrime(element))
            {
                // Insert the element into elementsPrime vector while maintaining the ascending order
                elementsPrime.insert(
                    upper_bound(elementsPrime.begin(), elementsPrime.end(), address, [](const int *a, const int *b)
                                { return *a < *b; }),
                    address);
            }

            if (size() == 1)
            {
                elementsSidecross.push_back(elementsAscend.front());
                return;
            }

            // Generate the elementsSidecross vector by inserting elements from both ends of elementsAscend
            while (start <= end && end != 0)
            {
                elementsSidecross.push_back(elementsAscend.at(start));

                if (start != end)
                {
                    elementsSidecross.push_back(elementsAscend.at(end));
                }

                start++;
                end--;
            }
        }
    }

    // Removes an element from the container
    void MagicalContainer::removeElement(int element)
    {
        auto it = elements.find(element);

        if (it == elements.end())
        {
            throw runtime_error("Error: element not found");
        }

        const int *address = &(*it);
        elements.erase(it);

        if (isPrime(element))
        {
            // Remove the element from elementsPrime vector
            auto it_prime = find(elementsPrime.begin(), elementsPrime.end(), address);
            if (it_prime != elementsPrime.end())
            {
                elementsPrime.erase(it_prime);
            }
        }

        // Remove the element from elementsAscend vector
        auto it_ascending = find(elementsAscend.begin(), elementsAscend.end(), address);
        if (it_ascending != elementsAscend.end())
        {
            elementsAscend.erase(it_ascending);
        }

        elementsSidecross.clear();
        elementsSidecross.reserve(elementsAscend.size());

        if (size() == 0)
            return;

        else if (size() == 1)
        {
            elementsSidecross.push_back(elementsAscend.front());
            return;
        }

        size_t start = 0, end = elementsAscend.size() - 1;

        // Generate the elementsSidecross vector by inserting elements from both ends of elementsAscend
        while (start <= end && end != 0)
        {
            elementsSidecross.push_back(elementsAscend.at(start));

            if (start != end)
            {
                elementsSidecross.push_back(elementsAscend.at(end));
            }

            start++;
            end--;
        }
    }

    // Returns the size of the container
    int MagicalContainer::size() const
    {
        return elements.size();
    }

    // Help function for personal tests
    int MagicalContainer::contains(int num) const { return (elements.contains(num)) ? 0 : 1; }
}
