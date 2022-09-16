#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("NoName", 72, 45)
{
	std::cout<<"RobotomyRequestForm Constructor Called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form(target, 72, 45)
{

	std::cout<<"RobotomyRequestForm Constructor Called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : Form(copy.getName(), copy.getSignPerm(), copy.getExecPerm())
{
	std::cout<<"RobotomyRequestForm Copy Constructor Called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	(void)copy;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout<<"RobotomyRequestForm Destructor Called"<<std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException)
{
	std::cout<<"RobotomyRequestForm execute called"<<std::endl;
	if (this->getExecPerm() < executor.getGrade())
		throw GradeTooLowException();
	std::cout<<"Drilllll...."<<std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout<<this->getName()<<" has been robotomized"<<std::endl;
	else
		std::cout<<this->getName()<<" robotomy failed"<<std::endl;
}
