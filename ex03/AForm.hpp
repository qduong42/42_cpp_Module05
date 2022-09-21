#ifndef AForm_HPP
#define AForm_HPP
// #pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#ifndef DEBUG
#define DEBUG 0
#endif
class Bureaucrat;

class AForm
{
	public:

		AForm();
		AForm(std::string const& name, int const& signGrade, int const& exeGrade);
		AForm(AForm const& obj);
		AForm& operator=(AForm const& obj);
		virtual ~AForm();

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
		class InsufficientGradeException:public std::exception
		{
			public:
			virtual const char *what()const throw();
		};
		std::string getName()const; // better string const return or not?
		bool getIsSigned()const;
		int getSignGrade()const;
		int getExeGrade()const;
		virtual void beSigned(Bureaucrat const& b) = 0;
		virtual AForm* clone() const = 0;
		void execute(Bureaucrat const& executor)const;

	private:

		std::string const _name;
		bool			  _isSigned;
		int const		  _signGrade;
		int const		  _exeGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif