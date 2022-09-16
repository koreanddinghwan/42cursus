#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::shrubbery = "\n \
                                              .\n \
                                   .         ;\n \
      .              .              ;%     ;;\n \
        ,           ,                :;%  %;\n \
         :         ;                   :;%;\'     .,\n \
,.        %;     %;            ;        %;\'    ,;\n \
  ;       ;%;  %%;        ,     %;    ;%;    ,%\'\n \
   %;       %;%;      ,  ;       %;  ;%;   ,%;\'\n \
    ;%;      %;        ;%;        % ;%;  ,%;\'\n \
     `%;.     ;%;     %;\'         `;%%;.%;\'\n \
      `:;%.    ;%%. %@;        %; ;@%;%\'\n \
         `:%;.  :;bd%;          %;@%;\'\n \
           `@%:.  :;%.         ;@@%;\'\n \
             `@%.  `;@%.      ;@@%;\n \
               `@%%. `@%%    ;@@%;\n \
                 ;@%. :@%%  %@@%;\n \
                   %@bd%%%bd%%:;\n \
                     #@%%%%%:;;\n \
                     %@@%%%::;\n \
                     %@@@%(o);  . \'\n \
                     %@@@o%;:(.,\'\n \
                 `.. %@@@o%::;\n \
                    `)@@@o%::;\n \
                     %@@(o)::;\n \
                    .%@@@@%::;\n \
                    ;%@@@@%::;.\n \
                   ;%@@@@%%:;;;.\n \
               ...;%@@@@@%%:;;;;,..  \n";

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("NoName", 145, 137)
{
	std::cout<<"ShrubberyCreationForm Constructor Called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form(target, 145, 137)
{
	std::cout<<"ShrubberyCreationForm Constructor Called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy.getName(), copy.getSignPerm(), copy.getExecPerm())
{
	std::cout<<"ShrubberyCreationForm Copy Constructor Called"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	(void)copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout<<"ShrubberyCreationForm Destructor Called"<<std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, FileOpenError)
{
	std::cout<<"ShrubberyCreationForm execute called"<<std::endl;
	if (this->getExecPerm() < executor.getGrade())
		throw GradeTooLowException();
	generator();
}

void ShrubberyCreationForm::generator(void) const throw(FileOpenError)
{
	std::fstream fs;
	std::string  file_name;

	std::cout<<"Generating trees...."<<std::endl;
	file_name = this->getName().append("_shrubbery");
	fs.open(file_name, std::fstream::out);
	if (!fs.is_open())
		throw FileOpenError();//stack unwinding
	fs.write(ShrubberyCreationForm::shrubbery.data(), ShrubberyCreationForm::shrubbery.length());
	fs.close();
}

const char *ShrubberyCreationForm::FileOpenError::what() const throw()
{
	return "File Not Open";
}
