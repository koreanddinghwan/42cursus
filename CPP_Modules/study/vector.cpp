#include <string>

class Vector {
	std::string *data;
	int capacity;
	int length;

	public:
		Vector (int n = 1) : data(new std::string[n]), capacity(n), length(0)
		{

		}
}
