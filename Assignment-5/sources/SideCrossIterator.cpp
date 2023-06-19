#include "MagicalContainer.hpp"

namespace ariel
{
    // Constructor with index parameter
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index)
        : container(container), index(index) {}

    // Default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(container), index(0) {}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), index(other.index) {}

    // Move constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept
        : container(other.container), index(other.index) {}

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Copy assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
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
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
    {
        if (this != &other)
        {
            container = std::move(other.container);
            index = std::move(other.index);
        }

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index == other.index;
    }

    // Inequality comparison operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index != other.index;
    }

    // Greater than comparison operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index > other.index;
    }

    // Less than comparison operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if (index >= container.elementsSidecross.size())
        {
            throw std::out_of_range("Iterator out of range");
        }

        return *(container.elementsSidecross.at(index));
    }

    // Prefix increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (index >= container.elementsSidecross.size())
        {
            throw std::runtime_error("Iterator out of range");
        }

        ++index;
        return *this;
    }

    // Returns an iterator pointing to the beginning of the container
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(container, 0);
    }

    // Returns an iterator pointing to the end of the container
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return SideCrossIterator(container, container.elementsSidecross.size());
    }
}
