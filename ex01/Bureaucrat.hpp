#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
// #pragma once
#include "colors.hpp"
#include "Form.hpp"

#include <iostream>
#include <exception>

#ifndef DEBUG
#define DEBUG 0
#endif

class Form;

class Bureaucrat
{
	public:

		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(Bureaucrat const& obj);
		Bureaucrat& operator=(Bureaucrat const& obj);
		~Bureaucrat();

		int	getGrade()const;
		const std::string& getName()const;
		void increaseGrade();
		void decreaseGrade();
		void signForm(Form & form);
		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
	private:

		int					_grade;
		std::string const	_name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
