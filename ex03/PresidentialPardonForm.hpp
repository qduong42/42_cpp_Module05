#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& obj);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& obj);
		~PresidentialPardonForm();

		virtual void beSigned(Bureaucrat const& b);
		virtual AForm* clone() const;
};

#endif
