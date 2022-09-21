#include "RobotomyRequestForm.hpp"
#include <cstdlib>


//	CONSTRUCTORS | DESTRUCTOR

RobotomyRequestForm::RobotomyRequestForm():AForm("unknown", 72, 45)
{
	if (DEBUG)
		std::cout << C_GREY << "RobotomyRequestForm default constructed" C_DEF << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm(target, 72, 45)
{
	if (DEBUG)
		std::cout << C_GREY << "RobotomyRequestForm target constructed" C_DEF << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getExeGrade())
{
	if (DEBUG)
		std::cout << C_GREY << "RobotomyRequestForm copy constructed" C_DEF << std::endl;
	(*this) = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& obj)
{
	if (DEBUG)
		std::cout << C_GREY << "RobotomyRequestForm = operator overload" C_DEF << std::endl;
		(void) obj;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG)
		std::cout << C_GREY << "RobotomyRequestForm default destructed" C_DEF << std::endl;
}

//	MEMBER FUNCTIONS

void RobotomyRequestForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getSignGrade() || b.getGrade() > this->getExeGrade())
	{
			std::cout << "Form RobotomyRequest " << this->getName() << " (not signed) requires " 
			<< this->getSignGrade() << " to sign and " << this->getExeGrade() << " to execute." << std::endl;
		throw AForm::InsufficientGradeException();
	}
	std::cout << "BRRRRRRR!" << std::endl;
	std::srand(std::time(NULL)); // use current time as seed for random generator
	if (std::rand() % 2)
		std::cout << this->getName() << "has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy has failed successfully" << std::endl;
}
