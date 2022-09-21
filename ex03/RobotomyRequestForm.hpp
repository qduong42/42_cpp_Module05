#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <fstream>  

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& obj);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& obj);
		~RobotomyRequestForm();

		virtual void beSigned(Bureaucrat const& b);
		virtual AForm* clone() const;
};

#endif
