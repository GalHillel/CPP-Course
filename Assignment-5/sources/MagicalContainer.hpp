#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <set>
#include <stdexcept>
#include <cstdlib>
#include <memory>
#include <algorithm>
#include <cmath>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::set<int> elements;                     // Set to store unique elements
        std::vector<const int *> elementsAscend;    // Vector to store pointers to elements in ascending order
        std::vector<const int *> elementsSidecross; // Vector to store pointers to elements that satisfy side-cross property
        std::vector<const int *> elementsPrime;     // Vector to store pointers to prime elements

        static bool isPrime(int num); // Helper function to check if a number is prime

    public:
        void addElement(int element);    // Adds an element to the container
        void removeElement(int element); // Removes an element from the container
        int size() const;                // Returns the size (number of elements) in the container
        int contains(int num) const;     // For personal tests

        class AscendingIterator
        {
        private:
            MagicalContainer &container; // Reference to the container being iterated
            size_t index;                // Current index in the iterator

        public:
            AscendingIterator(MagicalContainer &container, size_t index); // Constructor with container and index
            AscendingIterator(MagicalContainer &container);               // Constructor with container (initializes index to 0)
            AscendingIterator(const AscendingIterator &other);            // Copy constructor
            AscendingIterator(AscendingIterator &&other) noexcept;        // Move constructor
            ~AscendingIterator();                                         // Destructor

            AscendingIterator &operator=(AscendingIterator &&other) noexcept; // Move assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);     // Assignment operator

            bool operator==(const AscendingIterator &other) const; // Equality comparison operator
            bool operator!=(const AscendingIterator &other) const; // Inequality comparison operator
            bool operator<(const AscendingIterator &other) const;  // Less than comparison operator
            bool operator>(const AscendingIterator &other) const;  // Greater than comparison operator

            int operator*() const; // Dereference operator to get the value at the current iterator position

            AscendingIterator &operator++(); // Prefix increment operator to move to the next element

            AscendingIterator begin(); // Returns the iterator to the beginning of the container
            AscendingIterator end();   // Returns the iterator to the end of the container
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container; // Reference to the container being iterated
            size_t index;                // Current index in the iterator

        public:
            SideCrossIterator(MagicalContainer &container, size_t index); // Constructor with container and index
            SideCrossIterator(MagicalContainer &container);               // Constructor with container (initializes index to 0)
            SideCrossIterator(const SideCrossIterator &other);            // Copy constructor
            SideCrossIterator(SideCrossIterator &&other) noexcept;        // Move constructor
            ~SideCrossIterator();                                         // Destructor

            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept; // Move assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);     // Assignment operator

            bool operator==(const SideCrossIterator &other) const; // Equality comparison operator
            bool operator!=(const SideCrossIterator &other) const; // Inequality comparison operator
            bool operator<(const SideCrossIterator &other) const;  // Less than comparison operator
            bool operator>(const SideCrossIterator &other) const;  // Greater than comparison operator

            int operator*() const; // Dereference operator to get the value at the current iterator position

            SideCrossIterator &operator++(); // Prefix increment operator to move to the next element

            SideCrossIterator begin(); // Returns the iterator to the beginning of the container
            SideCrossIterator end();   // Returns the iterator to the end of the container
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container; // Reference to the container being iterated
            size_t index;                // Current index in the iterator

        public:
            PrimeIterator(MagicalContainer &container, size_t index); // Constructor with container and index
            PrimeIterator(MagicalContainer &container);               // Constructor with container (initializes index to 0)
            PrimeIterator(const PrimeIterator &other);                // Copy constructor
            ~PrimeIterator();                                         // Destructor

            PrimeIterator(PrimeIterator &&other) noexcept;            // Move constructor
            PrimeIterator &operator=(PrimeIterator &&other) noexcept; // Move assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);     // Assignment operator

            bool operator==(const PrimeIterator &other) const; // Equality comparison operator
            bool operator!=(const PrimeIterator &other) const; // Inequality comparison operator
            bool operator<(const PrimeIterator &other) const;  // Less than comparison operator
            bool operator>(const PrimeIterator &other) const;  // Greater than comparison operator

            int operator*() const; // Dereference operator to get the value at the current iterator position

            PrimeIterator &operator++(); // Prefix increment operator to move to the next element

            PrimeIterator begin(); // Returns the iterator to the beginning of the container
            PrimeIterator end();   // Returns the iterator to the end of the container
        };
    };
}

#endif
