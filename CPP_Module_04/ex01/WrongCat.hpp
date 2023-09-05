#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& rhs);
		~WrongCat();

		void		makeSound() const;
		std::string	getType() const;
	private:
		std::string	_type;
};


#endif