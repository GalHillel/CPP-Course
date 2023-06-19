#include "MagicalContainer.hpp"

namespace ariel
{
    // Constructor with index parameter
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t index)
        : container(container), index(index) {}

    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(container), index(0) {}

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), index(other.index) {}

    // Move constructor
    MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept
        : container(other.container), index(other.index) {}

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Copy assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this != &other)
        {
            if (&other.container != &container)
            {
                throw std::runtime_error("Iterators are not from the same container");
            }
            index = other.index;
        }

        return *this;
    }

    // Move assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
    {
        if (this != &other)
        {
            container = std::move(other.container);
            index = std::move(other.index);
        }

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index == other.index;
    }

    // Inequality comparison operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }

        return index != other.index;
    }

    // Greater than comparison operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }

        return index > other.index;
    }

    // Less than comparison operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }

        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const
    {
        if (index >= container.elementsPrime.size())
        {
            throw std::out_of_range("Iterator out of range");
        }

        return *(container.elementsPrime.at(index));
    }

    // Prefix increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (index >= container.elementsPrime.size())
        {
            throw std::runtime_error("Iterator out of range");
        }

        ++index;
        return *this;
    }

    // Returns an iterator pointing to the beginning of the container
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return PrimeIterator(container, 0);
    }

    // Returns an iterator pointing to the end of the container
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator(container, container.elementsPrime.size());
    }
}
