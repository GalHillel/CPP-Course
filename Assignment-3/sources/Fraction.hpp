#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

namespace ariel
{
    class Fraction
    {
    public:
        // constructors
        Fraction();
        Fraction(int num, int den);
        Fraction(float num);
        Fraction(const Fraction &other);

        // move constructor
        Fraction(Fraction &&other) noexcept;

        // distructor
        ~Fraction() {}

        // assignment
        Fraction &operator=(const Fraction &other);
        Fraction &operator=(Fraction &&other) noexcept;

        // check for overflow
        void checkOverflow(long num, long den) const;

        // arithmetic operators

        // +
        Fraction
        operator+(const Fraction &other) const;
        Fraction operator+(double other) const;
        friend Fraction operator+(const double &num, const Fraction &fraction);

        // -
        Fraction operator-(const Fraction &other) const;
        friend Fraction operator-(const double &num, const Fraction &fraction);
        Fraction operator-(double other) const;

        // *
        Fraction operator*(const Fraction &other) const;
        Fraction operator*(double other) const;
        friend Fraction operator*(const double &num, const Fraction &fraction);

        // /
        Fraction operator/(const Fraction &other) const;
        Fraction operator/(double other) const;
        friend Fraction operator/(const double &num, const Fraction &fraction);

        // comparison operators

        // >
        bool operator>(const Fraction &other) const;
        friend bool operator>(const Fraction &fraction, const double &num);
        friend bool operator>(const double &num, const Fraction &fraction);

        // <
        bool operator<(const Fraction &other) const;
        friend bool operator<(const Fraction &fraction, const double &num);
        friend bool operator<(const double &num, const Fraction &fraction);

        // ==
        bool operator==(const Fraction &other) const;
        friend bool operator==(const Fraction &fraction, const double &num);
        friend bool operator==(const double &num, const Fraction &fraction);

        // !=
        bool operator!=(const Fraction &other) const;
        friend bool operator!=(const Fraction &fraction, const double &num);
        friend bool operator!=(const double &num, const Fraction &fraction);

        // >=
        bool operator>=(const Fraction &other) const;
        friend bool operator>=(const Fraction &fraction, const double &num);
        friend bool operator>=(const double &num, const Fraction &fraction);

        // <=
        bool operator<=(const Fraction &other) const;
        friend bool operator<=(const Fraction &fraction, const double &num);
        friend bool operator<=(const double &num, const Fraction &fraction);

        // increment and decrement operators
        Fraction &operator++();         // pre-increment
        const Fraction operator++(int); // post-increment
        Fraction &operator--();         // pre-decrement
        const Fraction operator--(int); // post-decrement

        // input/output operators
        friend std::ostream &operator<<(std::ostream &ostream, const Fraction &frac);
        friend std::istream &operator>>(std::istream &istream, Fraction &frac);

        // Getters
        int getNumerator();
        int getDenominator();

    private:
        int numerator;
        int denominator;
        void reduce(); // helper function to reduce the fraction
    };
}

#endif
