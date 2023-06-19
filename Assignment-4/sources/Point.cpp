#include "Point.hpp"
#include <iostream>
#include <cmath>

namespace ariel
{
    Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double Point::distance(const Point &other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    std::string Point::toString() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    Point Point::moveTowards(const Point &source, const Point &destination, double distance)
    {
        if (distance < 0)
        {
            throw std::invalid_argument("Distance cannot be negative");
        }

        double dx = destination.x - source.x;
        double dy = destination.y - source.y;
        double currentDistance = std::sqrt(dx * dx + dy * dy);
        if (currentDistance <= distance || currentDistance < 0.001)
        {
            return destination;
        }
        else
        {
            double ratio = distance / currentDistance;
            double newX = source.x + dx * ratio;
            double newY = source.y + dy * ratio;
            return Point(newX, newY);
        }
    }
}