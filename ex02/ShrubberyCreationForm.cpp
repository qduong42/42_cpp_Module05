#include "ShrubberyCreationForm.hpp"

//	CONSTRUCTORS | DESTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm()
{
	if (DEBUG)
		std::cout << C_GREY << "ShrubberyCreationForm default constructed" C_DEF << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(target, 145, 137)
{
	if (DEBUG)
		std::cout << C_GREY << "ShrubberyCreationForm target constructed" C_DEF << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getExeGrade())
{
	if (DEBUG)
		std::cout << C_GREY << "ShrubberyCreationForm copy constructed" C_DEF << std::endl;
	(*this) = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& obj)
{
	if (DEBUG)
		std::cout << C_GREY << "ShrubberyCreationForm = operator overload" C_DEF << std::endl;
		(void) obj;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG)
		std::cout << C_GREY << "ShrubberyCreationForm default destructed" C_DEF << std::endl;
}

//	MEMBER FUNCTIONS

void ShrubberyCreationForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getSignGrade() || b.getGrade() > this->getExeGrade())
	{
			std::cout << "Form ShrubberyCreation " << this->getName() << " (not signed) requires " 
			<< this->getSignGrade() << " to sign and " << this->getExeGrade() << " to execute." << std::endl;
		throw AForm::InsufficientGradeException();
	}
	std::string filename = this->getName();
	filename.append("_shrubbery");
	std::ofstream outfile (filename.c_str());
	if (outfile.fail())
		std::cout << "Failed to create file" << std::endl;

outfile << "                     ,,  .. ,,..,.,,,.,, ,..,....*    . ,. ,,                   " << std::endl
		<< "                     ,,  .. ,,..,.,,,.,, ,..,....*    . ,. ,,                   " << std::endl
		<< "     .  ,.     .* ........,..,*,*,,,,/**.*...,.*,**,*..,...,**.,                " << std::endl
		<< "       .*. ..,  .,/* ,.,......./**,**(/*/,*(**,,*,,,..*,..                      " << std::endl
		<< "    . .. ,,,..*..,,..,*,,,.,.,*#%&(#(*/,/,.,**/.,.,.*...,,,,,,//,.,.            " << std::endl
		<< "              ,..,,.,. ***,*/,**(((#(///,,**,/,*,,,.....///,/.*.                " << std::endl
		<< "            .  .,(*,.****,,,,*,,/,.,....,,.,,....*#(%,.*,..*..((##(             " << std::endl
		<< "           .  .  ..,*.,..,/,,.,,,,,,,(,*,**.*#,***%*(/..,,&(,.,*,,./.... ..     " << std::endl
		<< "              .. ...,,*,,,,,(/#,/,/#&*,  /.#*(/.((((#(((/*./,...,...**,. .*(*,. " << std::endl
		<< "           ....,..,**.*.,//,,#/..*/..,//((/%(((#,////.***,,..,,  ..///.*/*..    " << std::endl
		<< "    .  .* .*. ...*,,.//(#/%*/,....*,,,/@/(&/(#,(,/*/###*,,*...*(//((*//.*, ,*,  " << std::endl
		<< "    . ..,,,.. , ***.,/**/*//...,*/*,,*#((&*((/(/(*..*(**(/,/(#(/ .,*,,.   ,     " << std::endl
		<< "     ,..,*.      /.,,..,,*.,. .,.(//(#@%&**,,./. ,###%#%*.**//(((((*. , ,,      " << std::endl
		<< "           .,..,..,.,/,.*/,,,.,#*.//(&%%(/,*,/(/,.#*//(((#%(###(/(#*#**/ , ,    " << std::endl
		<< "                .*//#*,,,%#,/%&.,*(#(%%@@(/&*#((,//%(#(#%*(/(**,,.(,*  .,       " << std::endl
		<< "        ..,....,,,/,,**(///(**/(##(###%&&###(###&#(#(#((/((#/((/(.   .          " << std::endl
		<< "        .   . /. ,,.. (#(/,//(###(*,&&(&@@@&%%((/*(((***../%*(**,*(/**          " << std::endl
		<< "            ..,,/,*,*,.**(**////.(//..%(%(@@#.(/.((/(/,,,,#(/**,**              " << std::endl
		<< "                 .   .*, ,*//,,.*.../*,%##%#%&&@#  ,*         .                 " << std::endl
		<< "                     . ....,  .    .,    (((#%(*(&@@%@&                         " << std::endl
		<< "                               .              ,,/,*@@@@@@,  .                   " << std::endl
		<< "                                               */#&@@@@@@&#                     " << std::endl
		<< "                                               ,**.../@@@@@                     " << std::endl
		<< "                                               .,,*,.&@@@@@                     " << std::endl
		<< "                                              .*(#(#%%@@@@@                     " << std::endl
		<< "                                           ..*%%%/,###@@@@@&                    " << std::endl
		<< "                                     .     ./@&%/..*.(#@@@@@&         .         " << std::endl
		<< "                   .......,,*/,,*,*,,*//,(. ,#,/ .    ,((&@@@@#,,,,.. ..        " << std::endl
		<< "               .       ..  ,,,,.,*/****(**/#/#(%#((((%(#&%@@@&&%%/*/   . ..     " << std::endl
		<< "          .         .,(((##(.,,,**,*,,,*(///*/,*(/&*#/,,,/***&/(&(*,//...     .." << std::endl;
outfile.close();
}
