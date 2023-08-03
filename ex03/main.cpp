#include "colors.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat bob(1, "Bob");
	Intern intern;
	AForm *f1 = intern.makeForm("presidential pardon", "Michael");
	AForm *f2 = intern.makeForm("robotomy request", "Coding");
	AForm *f3 = intern.makeForm("shrubbery creation", "Home");

	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;
	bob.signForm(*f1);
	bob.signForm(*f2);
	bob.signForm(*f3);
	bob.executeForm(*f1);
	bob.executeForm(*f2);
	bob.executeForm(*f3);
	delete f1;
	delete f2;
	delete f3;
	return 0;
}
