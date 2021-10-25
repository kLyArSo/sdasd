#include "Fixed.hpp"

const int Fixed::Fractional_Bits = 8;

Fixed::Fixed()
{
    // std::cout << "DEFAULT_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = 0;
}
Fixed::Fixed(const int val)
{
    // std::cout << "FLOAT_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = roundf(val * (float)(1 << Fractional_Bits));
}
Fixed::Fixed(const float val)
{
    // std::cout << "FLOAT_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = roundf(val * (float)(1 << Fractional_Bits));
}
Fixed::Fixed(const Fixed& obj)
{
    // std::cout << "COPY_CONSTRUCTOR_CALLED" << std::endl;
    *this = obj;
}
Fixed::~Fixed()
{
    // std::cout << "DEFAULT_DESTRUCTOR_CALLED" << std::endl;
}


float Fixed::toFloat( void ) const
{
    return ((this->Fixed_Point_Raw / (float)(1 << Fractional_Bits)));
}
int Fixed::toInt( void ) const
{
    return (this->Fixed_Point_Raw / (float)(1 << Fractional_Bits));
}


int     Fixed::getRawBits( void ) const
{
    // std::cout << "GET_RAW_BIT_MEMBER_FUCNTION_CALLED" << std::endl;
    return (this->Fixed_Point_Raw);
}
void     Fixed::setRawBits(int const raw)
{
    // std::cout << "SET_RAW_BIT_MEMBER_FUCNTION_CALLED" << std::endl;
    this->Fixed_Point_Raw = raw;
}

bool    Fixed::operator==(const Fixed& obj)
{
    return (this->Fixed_Point_Raw == obj.Fixed_Point_Raw);
}
bool    Fixed::operator!=(const Fixed& obj)
{
    return (this->Fixed_Point_Raw != obj.Fixed_Point_Raw);
}
bool    Fixed::operator>(const Fixed& obj)
{
    return (this->Fixed_Point_Raw > obj.Fixed_Point_Raw);
}
bool    Fixed::operator<(const Fixed& obj)
{
    return (this->Fixed_Point_Raw < obj.Fixed_Point_Raw);
}
bool    Fixed::operator>=(const Fixed& obj)
{
    return (this->Fixed_Point_Raw >= obj.Fixed_Point_Raw);
}
bool    Fixed::operator<=(const Fixed& obj)
{
    return (this->Fixed_Point_Raw <= obj.Fixed_Point_Raw);
}
void    Fixed::operator=(const Fixed& obj)
{
    std::cout << "ASSIGNEMENT_OPERATOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = obj.Fixed_Point_Raw;
}



Fixed     Fixed::operator+(const Fixed& obj)
{
    return (this->toFloat() + obj.toFloat());
}
Fixed     Fixed::operator-(const Fixed& obj)
{
    return (this->toFloat() - obj.toFloat());
}
Fixed     Fixed::operator*(const Fixed& obj)
{
    return (this->toFloat() * obj.toFloat());
}
Fixed     Fixed::operator/(const Fixed& obj)
{
    return (this->toFloat() / obj.toFloat());
}


Fixed     Fixed::operator++()
{
    this->Fixed_Point_Raw++;
    return (*this);
}
Fixed     Fixed::operator--()
{
    this->Fixed_Point_Raw--;
    return (*this);
}
Fixed     Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++*this;
    return (tmp);
}
Fixed     Fixed::operator--(int)
{
    Fixed tmp = *this;
    --*this;
    return (tmp);
}

std::ostream&    operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}
