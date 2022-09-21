#include "Intern.hpp"
#include "colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//	CONSTRUCTORS | DESTRUCTOR

Intern::Intern()
{

}

Intern::Intern(Intern const& obj)
{
	*this = obj;
}

Intern& Intern::operator=(Intern const& obj)
{
	(void) obj;
	return (*this);
}

Intern::~Intern()
{

}

//	MEMBER FUNCTIONS

AForm*  Intern::makeForm(std::string const& name, std::string const& target)
{
	PresidentialPardonForm ppf(target);
	RobotomyRequestForm rrf(target);
	ShrubberyCreationForm scf(target);
	AForm* ar[3] = {&rrf, &ppf, &scf};
	std::string arr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (size_t i = 0; i < 3; i++)
	{
		if (name == arr[i])
		{
			std::cout << "Intern creates " << arr[i] << std::endl;
			return ar[i]->clone();
		}
	}
		std::cout << "Form doesnt exist" << std::endl;
	return (NULL);
}
