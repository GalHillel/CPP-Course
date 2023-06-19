#include "MagicalContainer.hpp"

namespace ariel
{
    // Constructor with index parameter
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index)
        : container(container), index(index) {}

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(container), index(0) {}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), index(other.index) {}

    // Move constructor
    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept
        : container(other.container), index(other.index) {}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Copy assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
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
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
    {
        if (this != &other)
        {
            container = std::move(other.container);
            index = std::move(other.index);
        }

        return *this;
    }

    // Equality comparison operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index == other.index;
    }

    // Inequality comparison operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index != other.index;
    }

    // Greater than comparison operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index > other.index;
    }

    // Less than comparison operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        if (&other.container != &container)
        {
            throw std::runtime_error("Iterators are not from the same container");
        }
        return index < other.index;
    }

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const
    {
        if (index >= container.elementsAscend.size())
        {
            throw std::out_of_range("Iterator out of range");
        }

        return *(container.elementsAscend.at(index));
    }

    // Prefix increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (index >= container.elementsAscend.size())
        {
            throw std::runtime_error("Iterator out of range");
        }

        ++index;
        return *this;
    }

    // Returns an iterator pointing to the beginning of the container
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(container, 0);
    }

    // Returns an iterator pointing to the end of the container
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return AscendingIterator(container, container.elementsAscend.size());
    }
}
