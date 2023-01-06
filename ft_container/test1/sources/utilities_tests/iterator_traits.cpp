#include "../system/system_methods.ipp"
#include <iterator>
#include <iostream>
#include UTILITIES
#include VECTOR

void test(std::vector<string> v1, std::vector<string> v2) {
	auto b1 = v1.begin();
	auto b2 = v2.begin();
	for (int i = 0; b1 < v1.end(); b1++, b2++, i++){
		if (!(*b1 == *b2)) {
			std::cout<<"======="<<std::endl;
			std::cout<<i<<std::endl;
			std::cout<<*b1<<std::endl;
			std::cout<<*b2<<std::endl;
			std::cout<<"======="<<std::endl;
		}
	}
}

bool iterator_traits_test() {
	std::vector<string> res;
	std::vector<string> res2;
	g_start1 = g_end1 = timer();

	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());


	res2.push_back(typeid(_vector<int>::iterator::iterator_category).name());
	res2.push_back(typeid(_vector<int>::iterator::value_type).name());
	res2.push_back(typeid(_vector<int>::iterator::difference_type).name());
	res2.push_back(typeid(_vector<int>::iterator::iterator_type).name());
	res2.push_back(typeid(_vector<int>::iterator::pointer).name());
	res2.push_back(typeid(_vector<int>::iterator::reference).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::iterator_category).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::value_type).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::difference_type).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::pointer).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::reference).name());

	test(res, res2);

	return res == res2;
}

int main() {

	exit(run_bool_unit_test("iterators_traits", iterator_traits_test));
}
