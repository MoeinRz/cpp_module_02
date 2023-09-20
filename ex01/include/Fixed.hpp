# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <float.h>

class Fixed
{
    private:
        static const int    _fractional;
        int                 _ixed_point;
    public:
        Fixed();
		Fixed(const int input);
		Fixed(const float input);
        Fixed(const Fixed& cp);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        Fixed &operator=(const Fixed &src);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

# endif