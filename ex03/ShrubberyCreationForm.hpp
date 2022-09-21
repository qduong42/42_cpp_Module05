#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <fstream>  

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& obj);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& obj);
		~ShrubberyCreationForm();

		virtual void beSigned(Bureaucrat const& b);
		virtual AForm* clone() const;
};

#endif
