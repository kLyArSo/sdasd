#include "Fixed.hpp"

const int Fixed::Fractional_Bits = 8;

Fixed::Fixed()
{
    std::cout << "DEFAULT_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = 0;
}
Fixed::Fixed(const int val)
{
    std::cout << "FLOAT_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = val * (1 << Fractional_Bits);
}
Fixed::Fixed(const float val)
{
    std::cout << "FLOAT_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = roundf(val * (1 << Fractional_Bits));
}
Fixed::Fixed(const Fixed& obj)
{
    std::cout << "COPY_CONSTRUCTOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = obj.Fixed_Point_Raw;
}
Fixed::~Fixed()
{
    std::cout << "DEFAULT_DESTRUCTOR_CALLED" << std::endl;
}


float Fixed::toFloat( void ) const
{
    return (this->Fixed_Point_Raw / (float)(1 << Fractional_Bits));
}
int Fixed::toInt( void ) const
{
    return (this->Fixed_Point_Raw / (float)(1 << Fractional_Bits));
}


std::ostream&    operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}
void    Fixed::operator=(const Fixed& obj)
{
    std::cout << "ASSIGNEMENT_OPERATOR_CALLED" << std::endl;
    this->Fixed_Point_Raw = obj.Fixed_Point_Raw;
}


int     Fixed::getRawBits( void ) const
{
    std::cout << "GET_RAW_BIT_MEMBER_FUCNTION_CALLED" << std::endl;
    return (this->Fixed_Point_Raw);
}
void     Fixed::setRawBits(int const raw)
{
    std::cout << "SET_RAW_BIT_MEMBER_FUCNTION_CALLED" << std::endl;
    this->Fixed_Point_Raw = raw;
}
