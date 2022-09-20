#include "colors.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << C_GREEN << "Form Tom" << C_DEF << std::endl;
	// Form *t = NULL;
	try
	{
		/* t = new  */Form Tom("Tom", 120, 30);
		Bureaucrat a(1, "Dim Cheaty");
		a.signForm(Tom);
		// std::cout << Tom;
	}
	catch(std::exception& e)
	{
		// if (t)
		// 	delete t;
		std::cerr << e.what() << '\n';
	}
	// delete t;
}
