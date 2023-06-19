#include "Fraction.hpp"
#include <cmath>
#include <algorithm>

namespace ariel
{
    // constructors
    Fraction::Fraction() : numerator(0), denominator(1) {}

    Fraction::Fraction(int num, int den)
        : numerator(num), denominator(den != 0 ? den : throw std::invalid_argument("Invalid argument: Division by zero"))
    {
        reduce();
    }

    Fraction::Fraction(float num) : numerator(num * 1000), denominator(1000)
    {
        reduce();
    }

    Fraction::Fraction(const Fraction &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    // move constructor
    Fraction::Fraction(Fraction &&other) noexcept
        : numerator(other.numerator), denominator(other.denominator)
    {
        other.numerator = 0;
        other.denominator = 1;
    }

    // assignment
    Fraction &Fraction::operator=(const Fraction &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept
    {
        if (this != &other)
        {
            numerator = other.numerator;
            denominator = other.denominator;
            other.numerator = 0;
            other.denominator = 1;
        }
        return *this;
    }

    // check for overflow
    void Fraction::checkOverflow(long num, long den) const
    {
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() || den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("Overflow detected");
        }
    }

    // arithmetic operators

    // +
    Fraction Fraction::operator+(const Fraction &other) const
    {
        long long num = static_cast<long long>(numerator) * other.denominator + static_cast<long long>(other.numerator) * denominator;
        long long den = static_cast<long long>(denominator) * other.denominator;
        checkOverflow(num, den);
        return Fraction(num, den);
    }

    Fraction Fraction::operator+(double other) const
    {
        Fraction other_frac(other);
        return *this + other_frac;
    }

    Fraction operator+(const double &num, const Fraction &fraction)
    {
        Fraction num_frac(num);
        return num_frac + fraction;
    }

    // -
    Fraction Fraction::operator-(const Fraction &other) const
    {
        long long num = static_cast<long long>(numerator) * other.denominator - static_cast<long long>(other.numerator) * denominator;
        long long den = static_cast<long long>(denominator) * other.denominator;
        checkOverflow(num, den);
        return Fraction(num, den);
    }

    Fraction operator-(const double &num, const Fraction &fraction)
    {
        Fraction num_frac(num);
        return num_frac - fraction;
    }

    Fraction Fraction::operator-(double other) const
    {
        Fraction other_frac(other);
        return *this - other_frac;
    }

    // *
    Fraction Fraction::operator*(const Fraction &other) const
    {
        long long num = static_cast<long long>(numerator) * static_cast<long long>(other.numerator);
        long long den = static_cast<long long>(denominator) * static_cast<long long>(other.denominator);
        checkOverflow(num, den);
        return Fraction(static_cast<int>(num), static_cast<int>(den));
    }

    Fraction Fraction::operator*(double other) const
    {
        Fraction other_frac(other);
        return *this * other_frac;
    }

    Fraction operator*(const double &num, const Fraction &fraction)
    {
        Fraction num_frac(num);
        return num_frac * fraction;
    }

    // /
    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.numerator == 0)
        {
            throw std::runtime_error("Invalid operation: Division by zero");
        }
        long long num = static_cast<long long>(numerator) * other.denominator;
        long long den = static_cast<long long>(denominator) * other.numerator;
        checkOverflow(num, den);
        return Fraction(static_cast<int>(num), static_cast<int>(den));
    }

    Fraction Fraction::operator/(double other) const
    {
        Fraction other_frac(other);
        return *this / other_frac;
    }

    Fraction operator/(const double &num, const Fraction &fraction)
    {
        Fraction num_frac(num);
        return num_frac / fraction;
    }

    // comparison operators

    // >
    bool ariel::Fraction::operator>(const Fraction &other) const
    {
        return (numerator * other.denominator > other.numerator * denominator);
    }

    bool operator>(const ariel::Fraction &fraction, const double &num)
    {
        return (static_cast<double>(fraction.numerator) / fraction.denominator > num);
    }

    bool operator>(const double &num, const ariel::Fraction &fraction)
    {
        return (num > static_cast<double>(fraction.numerator) / fraction.denominator);
    }

    // <
    bool ariel::Fraction::operator<(const Fraction &other) const
    {
        return (numerator * other.denominator < other.numerator * denominator);
    }

    bool operator<(const ariel::Fraction &fraction, const double &num)
    {
        return (static_cast<double>(fraction.numerator) / fraction.denominator < num);
    }

    bool operator<(const double &num, const ariel::Fraction &fraction)
    {
        return (num < static_cast<double>(fraction.numerator) / fraction.denominator);
    }

    // ==
    bool ariel::Fraction::operator==(const Fraction &other) const
    {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    bool operator==(const ariel::Fraction &fraction, const double &num)
    {
        return (static_cast<double>(fraction.numerator) / fraction.denominator == num);
    }

    bool operator==(const double &num, const ariel::Fraction &fraction)
    {
        return (num == static_cast<double>(fraction.numerator) / fraction.denominator);
    }

    // !=
    bool ariel::Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    bool operator!=(const ariel::Fraction &fraction, const double &num)
    {
        return !(fraction == num);
    }

    bool operator!=(const double &num, const ariel::Fraction &fraction)
    {
        return !(num == fraction);
    }

    // >=
    bool ariel::Fraction::operator>=(const Fraction &other) const
    {
        return (*this > other || *this == other);
    }

    bool operator>=(const ariel::Fraction &fraction, const double &num)
    {
        return (fraction > num || fraction == num);
    }

    bool operator>=(const double &num, const ariel::Fraction &fraction)
    {
        return (num > fraction || num == fraction);
    }

    // <=
    bool ariel::Fraction::operator<=(const Fraction &other) const
    {
        return (*this < other || *this == other);
    }

    bool operator<=(const ariel::Fraction &fraction, const double &num)
    {
        return (fraction < num || fraction == num);
    }

    bool operator<=(const double &num, const ariel::Fraction &fraction)
    {
        return (num < fraction || num == fraction);
    }

    // increment and decrement operators

    // pre-increment
    ariel::Fraction &ariel::Fraction::operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }

    // post-increment
    const ariel::Fraction ariel::Fraction::operator++(int)
    {
        Fraction temp(*this);
        numerator += denominator;
        reduce();
        return temp;
    }

    // pre-decrement
    ariel::Fraction &ariel::Fraction::operator--()
    {
        numerator -= denominator;
        reduce();
        return *this;
    }

    // post-decrement
    const ariel::Fraction ariel::Fraction::operator--(int)
    {
        Fraction temp(*this);
        numerator -= denominator;
        reduce();
        return temp;
    }

    // input/output operators

    // output operator
    std::ostream &operator<<(std::ostream &ostream, const ariel::Fraction &frac)
    {
        ostream << frac.numerator << "/" << frac.denominator;
        return ostream;
    }

    // input operator
    std::istream &operator>>(std::istream &istream, ariel::Fraction &frac)
    {
        int num, den;
        char str;
        istream >> num;
        if (istream.fail() || den == 0)
        {
            throw std::runtime_error("Invalid input");
        }
        if (istream.peek() == '/')
        {
            istream >> str >> den;
            if (istream.fail() || den == 0)
            {
                throw std::runtime_error("Invalid input");
            }
        }
        else
        {
            istream >> den;
            if (istream.fail() || den == 0)
            {
                throw std::runtime_error("Invalid input");
            }
        }
        frac = Fraction(num, den);
        return istream;
    }

    // Getters
    int ariel::Fraction::getNumerator()
    {
        return numerator;
    }

    int ariel::Fraction::getDenominator()
    {
        return denominator;
    }

    // Helper function to reduce the fraction
    void Fraction::reduce()
    {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
}