#include "Bureaucrat.hpp"
#include "colors.hpp"

//	CONSTRUCTORS | DESTRUCTOR

Bureaucrat::Bureaucrat(): _grade(0), _name("unknown")
{
	if (DEBUG)
		std::cout << C_GREY << "Bureaucrat default constructed" C_DEF << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name): _grade(0), _name(name)
{
	if (DEBUG)
		std::cout << C_GREY << "Bureaucrat grade & name constructed" C_DEF << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& obj): _grade(obj.getGrade()), _name(obj._name) 
{
	if (DEBUG) 
	std::cout << C_GREY << "Bureaucrat copy constructed" C_DEF << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& obj)
{
	if (DEBUG)
	{
		std::cout << C_GREY << "Bureaucrat =op overload" C_DEF << std::endl;
		std::cout << C_GREY << "name cant be assigned:const" C_DEF << std::endl;
	}
	if (this != &obj)
	{
		this->_grade = obj.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
		std::cout << C_GREY << "Bureaucrat default destructed" C_DEF << std::endl;	
}

//	MEMBER FUNCTIONS

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::signForm(Form & form)
{
	try 
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e) 
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		return;
	}
	if (form.getIsSigned() == true)
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::increaseGrade() {
	if (this->_grade - 1 < 1) throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (this->_grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat's grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat's grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}
