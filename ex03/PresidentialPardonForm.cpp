#include "PresidentialPardonForm.hpp"

//	CONSTRUCTORS | DESTRUCTOR

PresidentialPardonForm::PresidentialPardonForm():AForm("unknown", 25, 5)
{
	if (DEBUG)
		std::cout << C_GREY << "PresidentialPardonForm default constructed" C_DEF << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm(target, 25, 5)
{
	if (DEBUG)
		std::cout << C_GREY << "PresidentialPardonForm target constructed" C_DEF << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getExeGrade())
{
	if (DEBUG)
		std::cout << C_GREY << "PresidentialPardonForm copy constructed" C_DEF << std::endl;
	(*this) = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& obj)
{
	(void) obj;
	if (DEBUG)
		std::cout << C_GREY << "PresidentialPardonForm = operator overload" C_DEF << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG)
		std::cout << C_GREY << "PresidentialPardonForm default destructed" C_DEF << std::endl;
}

//	MEMBER FUNCTIONS

void PresidentialPardonForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getSignGrade() || b.getGrade() > this->getExeGrade())
	{
			std::cout << "Form presidential pardon" << this->getName() << " (not signed) requires " 
			<< this->getSignGrade() << " to sign and " <<this->getExeGrade() << " to execute." << std::endl;
		throw AForm::InsufficientGradeException();
	}
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::clone() const
{
	return new PresidentialPardonForm(this->getName());
}
