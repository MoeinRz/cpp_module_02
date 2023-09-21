# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        static const int    _fractional;
        int                 _fixed_point;
    public:
        Fixed();
		Fixed(const int input);
		Fixed(const float input);
        Fixed(const Fixed& cp);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        Fixed   &operator=(const Fixed &src);
        float   toFloat( void ) const;
        int     toInt( void ) const;

		bool 	operator>(const Fixed& num) const;
		bool 	operator<(const Fixed& num) const;
		bool 	operator>=(const Fixed& num) const;
		bool 	operator<=(const Fixed& num) const;
		bool 	operator==(const Fixed& num) const;
		bool 	operator!=(const Fixed& num) const;

        Fixed	operator+(const Fixed& num) const;
		Fixed	operator-(const Fixed& num) const;
		Fixed	operator*(const Fixed& num) const;
		Fixed	operator/(const Fixed& num) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

	    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

# endif