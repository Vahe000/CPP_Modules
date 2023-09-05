#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea";
	std::cout << "Default constructor for Brain called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor for Brain called\n";
	*this = other;	
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Copy assignment operator for Brain called\n";
	if (this != &other)
	{
        for (int i = 0; i < 100; ++i)
        {
            _ideas[i] = other._ideas[i];
        }
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout << "Destructor for Brain called\n";
}
