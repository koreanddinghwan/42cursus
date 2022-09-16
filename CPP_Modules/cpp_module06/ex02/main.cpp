#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
	int i = rand() % 3;
	switch (i) {
		case 0:
			std::cout<<"A generated"<<std::endl;
			return (new A());
		case 1:
			std::cout<<"B generated"<<std::endl;
			return (new B());
		case 2:
			std::cout<<"C generated"<<std::endl;
			return (new C());
	}
	return (NULL);
}

void identify(Base *p)
{
	std::cout<<std::endl<<std::endl<<std::endl;
	std::cout<<"static_cast tset"<<std::endl;
	static_cast<A *>(p)->WhoAmI();
	//check with non-polymorphic class
	//if class is not a polymorphic, compiler will <call fnc by pointer>
	std::cout<<std::endl;
	for (int i = 0; i < 3; i++)
	{
		switch (i) {
			case 0:
			{
				A *a = dynamic_cast<A *>(p);//downcasting with not polymorphic class is forbidden by rtti
				if (a) //if failed, dynamic_cast return NULL
				{
					a->WhoAmI();
					return ;
				}
			}
			case 1:
			{
				B *b = dynamic_cast<B *>(p);
				if (b)
				{
					b->WhoAmI();
					return ;
				}
			}
			case 2:
			{
				C *c = dynamic_cast<C *>(p);
				if (c)
				{
					c->WhoAmI();
					return ;
				}
			}
		}
	}
}

void identify(Base &p)
{
	for (int i = 0; i < 3; i++)
	{
		try {
				switch (i) {
					case 0:
					{
						A &a = dynamic_cast<A &>(p);//dynamic_cast to ref throw exception if failed
						a.WhoAmI();
						return ;
					}
					case 1:
					{
						B &b = dynamic_cast<B &>(p);
						b.WhoAmI();
						return ;
					}
					case 2:
					{
						C &c = dynamic_cast<C &>(p);
						c.WhoAmI();
						return ;
					}
			}
		} catch (std::exception &e)
		{
			std::cout<<i<<" : "<<e.what()<<std::endl;
		}
	}
}

int main(void)
{
	srand(time(NULL));

	Base *unknownptr = generate();
	identify(unknownptr);
	std::cout<<std::endl<<std::endl<<std::endl<<std::endl;
	std::cout<<"dynamic cast by ref"<<std::endl;
	identify(*unknownptr);
	return 0;
}
