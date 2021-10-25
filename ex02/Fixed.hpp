#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
    private:
        int                 Fixed_Point_Raw;
        static const int    Fractional_Bits;
    public:
        Fixed();
        Fixed(const int val);
        Fixed(const float val);
        Fixed(const Fixed& obj);
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;

        int     getRawBits(void ) const;
        void    setRawBits(int const raw);

        bool    operator==(const Fixed& obj);
        bool    operator!=(const Fixed& obj);
        bool    operator>(const Fixed& obj);
        bool    operator<(const Fixed& obj);
        bool    operator>=(const Fixed& obj);
        bool    operator<=(const Fixed& obj);
        void    operator=(const Fixed& obj);

        Fixed     operator+(const Fixed& obj);
        Fixed     operator-(const Fixed& obj);
        Fixed     operator*(const Fixed& obj);
        Fixed     operator/(const Fixed& obj);


        Fixed     operator++();
        Fixed     operator--();
        Fixed     operator++(int);
        Fixed     operator--(int);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif