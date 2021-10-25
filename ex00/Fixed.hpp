#include <iostream>

class Fixed
{
    private:
        int                 Fixed_Point_Raw;
        static const int    Fractional_Bits;
    public:
        Fixed();
        Fixed(const Fixed& obj);
        int     getRawBits(void ) const;
        void    setRawBits(int const raw);
        ~Fixed();
        void    operator=(const Fixed& obj);
};
