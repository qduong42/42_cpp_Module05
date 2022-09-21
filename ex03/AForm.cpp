#include "AForm.hpp"
#include "colors.hpp"

//	CONSTRUCTORS | DESTRUCTOR

AForm::AForm(): _name("standard"), _isSigned(false), _signGrade(0), _exeGrade(0)
{
	if (DEBUG)
		std::cout << C_GREY << "AForm default constructed" C_DEF << std::endl;
}

AForm::AForm(std::string const& name, int const& signGrade,
int const& exeGrade): _name(name), _isSigned(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (DEBUG)
		std::cout << C_GREY << "AForm explicit constructed" C_DEF << std::endl;
	if (signGrade > 150 || exeGrade > 150)
	{
		std::cout << "Sign/Exe Grade too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (signGrade < 1 || exeGrade < 1)
	{
		std::cout << "Sign/Exe Grade too high" << std::endl;
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(AForm const& obj): _name(obj.getName()),
							 _isSigned(obj.getIsSigned()),
							 _signGrade(obj.getSignGrade()), 
							 _exeGrade(obj.getExeGrade())
{
	if (DEBUG)
		std::cout << C_GREY << "AForm copy constructed" C_DEF << std::endl;
	if (obj.getSignGrade() > 150 || obj.getExeGrade() > 150)
	{
		std::cout << "Sign/Exe Grade too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (obj.getSignGrade() < 1 || obj.getExeGrade() < 1)
	{
		std::cout << "Sign/Exe Grade too high" << std::endl;
		throw AForm::GradeTooHighException();
	}
}

AForm& AForm::operator=(AForm const& obj)
{
	if (DEBUG)
	{
		std::cout << C_GREY << "AForm =op overload" C_DEF << std::endl;
		std::cout << C_GREY << "name, sign and exe grade cant be assigned because const" C_DEF << std::endl;
	}
	if (this != &obj)
	{
		this->_isSigned = obj.getIsSigned();
	}
	return (*this);
}

AForm::~AForm()
{
	if (DEBUG)
		std::cout << C_GREY << "AForm default destructed" C_DEF << std::endl;
}

//	MEMBER FUNCTIONS

int AForm::getSignGrade()const
{
	return (this->_signGrade);
}

int AForm::getExeGrade()const
{
	return (this->_exeGrade);
}

bool AForm::getIsSigned()const
{
	return (this->_isSigned);
}

std::string AForm::getName()const
{
	return (this->_name);
}

void AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getSignGrade())
	{
		if (DEBUG)
			std::cout << C_GREY << "Sign unsuccessful" << C_DEF << std::endl;
		throw AForm::GradeTooHighException();
	}
	if (DEBUG)
		std::cout << C_GREY << "Sign successful"<< C_DEF << std::endl;
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor)const
{
	if (executor.getGrade() > this->getExeGrade())
		throw InsufficientGradeException();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

const char* AForm::GradeTooLowException::what()const throw()
{
	return ("Bureaucrat AForm Too Low for Bureaucrat to sign!");
}

const char* AForm::GradeTooHighException::what()const throw()
{
	return ("Form Too High for Bureaucrat to sign!");
}

const char* AForm::InsufficientGradeException::what()const throw()
{
	return ("Bureaucrat Grade Insufficient!");
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << C_BLUE << "======AFormStats=====: " << std::endl
	<< "Name: " << AForm.getName() << " | " << std::endl;
	if (AForm.getIsSigned() == false)
		os << "isSigned:false | " << std::endl;
	else
		os << "isSigned:true | " << std::endl;
	os << "signGrade: " << AForm.getSignGrade() << " | " << std::endl
	<< "exeGrade: " << AForm.getExeGrade() << " | " << std::endl;
	os << "======Stats End=====: " << C_DEF << std::endl;
	return (os);
}
