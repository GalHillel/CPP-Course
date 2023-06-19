#ifndef POINT_HPP
#define POINT_HPP

#include <string>

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double xCoord = 0, double yCoord = 0);
        double distance(const Point &other) const;
        std::string getX() const;
        std::string getY() const;
        std::string toString() const;
        static Point moveTowards(const Point &source, const Point &destination, double distance);
    };
}

#endif