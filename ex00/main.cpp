#include "colors.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << C_GREEN << "Bureaucrat Tom" << std::endl;
	Bureaucrat *t = NULL;
	try
	{
		t = new Bureaucrat(150, "Tom");
	}
	catch(std::exception& e)
	{
		if (t)
		{
			delete t;
			t = NULL;
		}
		std::cerr << e.what() << '\n';
	}
	std::cout << *t;
	std::cout << C_GREEN << "Increasing grade from 150" << C_DEF << std::endl;
	try
	{
		t->increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << C_GREEN << "Instantiate grade with 151" << C_DEF << std::endl;
	try
	{
		Bureaucrat James(151, "James");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (t)
		delete t;
}