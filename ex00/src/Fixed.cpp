#include "../include/Fixed.hpp"

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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_ixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits function called" << std::endl;
    this->_ixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cp)
		this->_ixed_point = cp.getRawBits();
	return *this;
}
