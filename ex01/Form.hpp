#ifndef FORM_HPP
#define FORM_HPP
// #pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#ifndef DEBUG
#define DEBUG 0
#endif
class Bureaucrat;

class Form
{
	public:

		Form();
		Form(std::string const& name, bool const& isSigned, int const& signGrade, int const& exeGrade);
		Form(Form const& obj);
		Form& operator=(Form const& obj);
		~Form();

		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char* what()const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char* what()const throw();
		};
		std::string const getName()const;
		bool getIsSigned()const;
		int getSignGrade()const;
		int getExeGrade()const;
		void beSigned(Bureaucrat const& b);
	private:

		std::string const _name;
		bool			  _isSigned;
		int const		  _signGrade;
		int const		  _exeGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif