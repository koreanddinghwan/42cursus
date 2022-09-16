#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("NoName", 25, 5)
{
	std::cout<<"PresidentialPardonForm Constructor Called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form(target, 25, 5)
{

	std::cout<<"PresidentialPardonForm Constructor Called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : Form(copy.getName(), copy.getSignPerm(), copy.getExecPerm())
{
	std::cout<<"PresidentialPardonForm Copy Constructor Called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	(void)copy;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout<<"PresidentialPardonForm Destructor Called"<<std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException)
{
	std::cout<<"PresidentialPardonForm execute called"<<std::endl;
	if (this->getExecPerm() < executor.getGrade())
		throw GradeTooLowException();
	std::cout<<this->getName()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}
