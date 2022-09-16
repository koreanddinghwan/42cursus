#include <iostream>
#include "Array.hpp"

class Test 
{
	private:
		int n;
	public:
		Test(void) : n(42)
		{
			std::cout<<"test constructor called"<<std::endl;
		}
		~Test()
		{
			std::cout<<"test destructor called"<<std::endl;
		}
};

#define MAX_VAL 750
void test1()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

void test2()
{
	{
		Array<Test> classarray(5);
	}
	{
		Array<Test> *heaparray = new Array<Test>[2];
		delete []heaparray;
	}
}

void test3()
{
	Array<int> testarray(5);

	testarray[0] = 1;
	testarray[1] = 2;
	testarray[2] = 3;
	testarray[3] = 4;
	testarray[4] = 5;
	try
	{
		testarray[5] = 6;
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<"test array\n"<<testarray<<std::endl;

	Array<int> copiedarray(testarray);
	std::cout<<"copied array element changed"<<std::endl;
	copiedarray[0] = 10;
	std::cout<<"copiedarray\n"<<copiedarray<<std::endl;
	std::cout<<"test array\n"<<testarray<<std::endl;

	std::cout<<"copiedarray = testarray"<<std::endl;
	copiedarray = testarray;
	std::cout<<"copiedarray\n"<<copiedarray<<std::endl;
	std::cout<<"test array\n"<<testarray<<std::endl;
}



int main(int, char**)
{
	test1();
	std::cout<<"\n\n\n";
	test2();
	std::cout<<"\n\n\n";
	test3();
    return 0;
}
