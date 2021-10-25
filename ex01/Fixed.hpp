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
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed(const Fixed& obj);
        int     getRawBits(void ) const;
        void    setRawBits(int const raw);
        void    operator=(const Fixed& obj);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);