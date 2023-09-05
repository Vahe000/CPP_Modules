/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:11:12 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 19:53:02 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n";
	const WrongAnimal* metaa = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	const WrongCat* t = new WrongCat();
	std::cout << metaa->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << t->getType() << " " << std::endl;
	metaa->makeSound();
	k->makeSound();
	t->makeSound();

	delete metaa;
	delete k;
	delete t;
	system("leaks animal");
	return 0;
}