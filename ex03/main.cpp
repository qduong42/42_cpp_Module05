#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << C_GREEN << "AForm Tom" << C_DEF << std::endl;
	AForm *t;
	t = new RobotomyRequestForm ("Tom");
	try
	{
		Bureaucrat b(150, "James");
		b.signForm(*t);
		b.executeForm(*t);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		delete t;
}
