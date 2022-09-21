#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:

		Intern();
		Intern(Intern const& obj);
		Intern& operator=(Intern const& obj);
		~Intern();

		AForm* makeForm(std::string const& name, std::string const& target);
	private:


};

#endif
