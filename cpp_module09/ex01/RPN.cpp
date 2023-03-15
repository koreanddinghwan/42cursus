#include <exception>
#include <iostream>
#include <stack>
#include <cctype>

class RPN {
	private:
		const char *Arg;
		std::stack<int> Default;
		std::stack<int> Result;
		bool errBit;

	public:
		RPN(int ac, char *av[]) {
			if (ac != 2)
			{
				std::cout<<"Error"<<std::endl;
				throw std::exception();
			}
			this->errBit = 0;
			for (int i = 0; av[1][i]; i++)
			{
				if (av[1][i] == 32)
					continue;
				if (Result.empty() && std::isdigit(av[1][i]))
					Result.push(static_cast<int>(av[1][i] - 48));
				else if (std::isdigit(av[1][i]))
				{	//operand
					Result.push(static_cast<int>(av[1][i] - 48));
				}
				else if (av[1][i] == 42 || av[1][i] == 43 || av[1][i] == 45 || av[1][i] == 47) 
				{
					//if operator but stack is empty, error
					if (Result.empty())
					{
						this->errBit = 1;
						break;
					} else {
						int operand1;
						int operand2;

						operand1 = Result.top();
						Result.pop();
						operand2 = Result.top();
						Result.pop();
						if (av[1][i] == 42)
							Result.push(operand2 * operand1);
						else if (av[1][i] == 43)
							Result.push(operand2 + operand1);
						else if (av[1][i] == 45)
							Result.push(operand2 - operand1);
						else if (av[1][i] == 47)
							Result.push(operand2 / operand1);
					}
				}
				else {
					this->errBit = 1;
					break;
				}
			}
		}
		~RPN() {}

		void printResult() {
			if (!errBit)
				std::cout<<Result.top()<<std::endl;
			else
				std::cout<<"Error"<<std::endl;
		}

	private:
		RPN(RPN &o) {}
		RPN& operator=(RPN &o) { return *this; }

	
};
