# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        static const int    _fractional;
        int                 _fixed_point;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& cp);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        Fixed &operator=(const Fixed &src);
};


# endif