#include "iter.hpp"

std::ostream& operator<<(std::ostream& out, Test const& rhs) {
	out << rhs.getn();
	return out;
}

int main(void)
{
	int tab[]= {0,1,2,3,4};
	Test tab2[5];

	// print is used here without instantiation. invalid
	iter(tab, 5, print);//made print<int>
	iter(tab2, 5, print);//made print<Awesome>
}
