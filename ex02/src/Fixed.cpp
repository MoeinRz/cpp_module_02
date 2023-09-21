#include "../include/Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed() : _fixed_point(0)
{
    return ;
}

Fixed::Fixed(const Fixed& cp)
{
    *this = cp;
    return ;
}

Fixed::Fixed(const int input)
{
    this->_fixed_point = input << this->_fractional;
    return ;
}

Fixed::Fixed(const float input)
{
    this->_fixed_point = roundf(input * (1 << this->_fractional));
    return ;
}

Fixed::~Fixed()
{
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->_fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixed_point / (float)(1 << this->_fractional));
}

int Fixed::toInt(void) const
{
    return (this->_fixed_point >> this->_fractional);
}

Fixed   &Fixed::operator=(const Fixed &cp)
{
	if (this != &cp)
		this->_fixed_point = cp.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

bool 	Fixed::operator>(const Fixed& num) const
{
    return (this->_fixed_point > num.getRawBits());
}

bool     Fixed::operator<(const Fixed& num) const
{
    return (this->_fixed_point < num.getRawBits());
}

bool     Fixed::operator>=(const Fixed& num) const
{
    return (this->_fixed_point >= num.getRawBits());
}

bool     Fixed::operator<=(const Fixed& num) const
{
    return (this->_fixed_point <= num.getRawBits());
}

bool     Fixed::operator==(const Fixed& num) const
{
    return (this->_fixed_point == num.getRawBits());
}

bool     Fixed::operator!=(const Fixed& num) const
{
    return (this->_fixed_point != num.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& num) const
{
    return (Fixed(this->toFloat() + num.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& num) const
{
    return (Fixed(this->toFloat() - num.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& num) const
{
    return (Fixed(this->toFloat() * num.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& num) const
{
    return (Fixed(this->toFloat() / num.toFloat()));
}

Fixed	&Fixed::operator++()
{
    this->_fixed_point++;
    return (*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed	&Fixed::operator--()
{
    this->_fixed_point--;
    return (*this);
}

Fixed	Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
