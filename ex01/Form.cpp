#include "Form.hpp"
#include "colors.hpp"

//	CONSTRUCTORS | DESTRUCTOR

Form::Form(): _name("standard"), _isSigned(false), _signGrade(0), _exeGrade(0)
{
	if (DEBUG)
		std::cout << C_GREY << "Form default constructed" C_DEF << std::endl;
}

Form::Form(std::string const& name, bool const& isSigned, int const& signGrade, \
int const& exeGrade): _name(name), _isSigned(isSigned), _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (DEBUG)
		std::cout << C_GREY << "Form explicit constructed" C_DEF << std::endl;
	if (signGrade > 150 || exeGrade > 150)
	{
		std::cout << "Sign/Exe Grade too low" << std::endl;
		throw Form::GradeTooLowException();
	}
	else if (signGrade < 1 || exeGrade < 1)
	{
		std::cout << "Sign/Exe Grade too high" << std::endl;
		throw Form::GradeTooHighException();
	}
}

Form::Form(Form const& obj): _name(obj.getName()),
							 _isSigned(obj.getIsSigned()),
							 _signGrade(obj.getSignGrade()), 
							 _exeGrade(obj.getExeGrade())
{
	if (DEBUG)
		std::cout << C_GREY << "Form copy constructed" C_DEF << std::endl;
	if (obj.getSignGrade() > 150 || obj.getExeGrade() > 150)
	{
		std::cout << "Sign/Exe Grade too low" << std::endl;
		throw Form::GradeTooLowException();
	}
	else if (obj.getSignGrade() < 1 || obj.getExeGrade() < 1)
	{
		std::cout << "Sign/Exe Grade too high" << std::endl;
		throw Form::GradeTooHighException();
	}
}

Form& Form::operator=(Form const& obj)
{
	if (DEBUG)
	{
		std::cout << C_GREY << "Form =op overload" C_DEF << std::endl;
		std::cout << C_GREY << "name, sign and exe grade cant be assigned because const" C_DEF << std::endl;
	}
	if (this != &obj)
	{
		this->_isSigned = obj.getIsSigned();
	}
	return (*this);
}

Form::~Form()
{
	if (DEBUG)
		std::cout << C_GREY << "Form default destructed" C_DEF << std::endl;
}

//	MEMBER FUNCTIONS

int Form::getSignGrade()const
{
	return (this->_signGrade);
}

int Form::getExeGrade()const
{
	return (this->_exeGrade);
}

bool Form::getIsSigned()const
{
	return (this->_isSigned);
}

std::string const Form::getName()const
{
	return (this->_name);
}

void Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getSignGrade())
	{
		if (DEBUG)
			std::cout << C_GREY << "Sign unsuccessful" << C_DEF << std::endl;
		throw Form::GradeTooHighException();
	}
	if (DEBUG)
		std::cout << C_GREY << "Sign successful"<< C_DEF << std::endl;
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what()const throw()
{
	return ("Form Too High for Bureaucrat to sign!");
}

const char* Form::GradeTooLowException::what()const throw()
{
	return ("Bureaucrat Form Too Low for Bureaucrat to sign!");
}



std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << C_BLUE << "======FormStats=====: " << std::endl
	<< "Name: " << form.getName() << " | " << std::endl;
	if (form.getIsSigned() == false)
		os << "isSigned:false | " << std::endl;
	else
		os << "isSigned:true | " << std::endl;
	os << "signGrade: " << form.getSignGrade() << " | " << std::endl
	<< "exeGrade: " << form.getExeGrade() << " | " << std::endl;
	os << "======Stats End=====: " << C_DEF << std::endl;
	return (os);
}
