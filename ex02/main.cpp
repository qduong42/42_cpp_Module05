#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << C_GREEN << "AForm Tom" << C_DEF << std::endl;
	AForm *t = NULL;
	try
	{
		t = new ShrubberyCreationForm("Tom");
		Bureaucrat b(10, "James");
		b.signForm(*t);
	}
	catch(std::exception& e)
	{
		// if (t)
		// 	delete t;
		std::cerr << e.what() << '\n';
	}
	// delete t;
}
