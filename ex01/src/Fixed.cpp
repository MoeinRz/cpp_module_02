#include "../include/Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed() : _ixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed& cp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cp;
    return ;
}

Fixed::Fixed(const int input)
{
    std::cout << "Int constructor called" << std::endl;
    this->_ixed_point = input << this->_fractional;
    return ;
}

Fixed::Fixed(const float input)
{
    std::cout << "Float constructor called" << std::endl;
    this->_ixed_point = roundf(input * (1 << this->_fractional));
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->_ixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    this->_ixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_ixed_point / (float)(1 << this->_fractional));
}

int Fixed::toInt(void) const
{
    return (this->_ixed_point >> this->_fractional);
}

Fixed &Fixed::operator=(const Fixed &cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cp)
		this->_ixed_point = cp.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
