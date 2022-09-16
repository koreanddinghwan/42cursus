#include <iostream>
#include <string>

class Interfaces
{
	public:
		virtual ~Interfaces(void);
	public:
		virtual void InterfacesFnc(void) const = 0;
};

class Derived : public Interfaces
{
	private:
		std::string *test;
	public:
		Derived(void);
		~Derived(void);
	public:
		void InterfacesFnc(void) const;
};

Derived::Derived(void) : Interfaces()
{
	this->test = new std::string[10];
}

void Derived::InterfacesFnc(void) const
{
	std::cout<<"test"<<std::endl;
}

Derived::~Derived(void)
{
	delete []this->test;
}

int main(void)
{
	Derived obj1;

	return (0);
}
