#include "../system/system_methods.ipp"
#include "__service.ipp"
#include <exception>

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
		std::cout<<"B hi!"<<std::endl;
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
		std::cout<<"B bye"<<std::endl;
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
		std::cout<<"A hi!"<<std::endl;
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
		std::cout<<"A bye"<<std::endl;
        delete this->l;
        this->l = nullptr;
    };
};

template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    g_start1 = timer();
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    g_end1 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());


	std::cout<<"start"<<std::endl;
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    
	std::cout<<"A vector construct"<<std::endl;
	std::vector<A> vv;
	std::cout<<"B vector construct"<<std::endl;
    std::vector<B*> v1;

	std::cout<<"======="<<std::endl;
	std::cout<<"======="<<std::endl;
	std::cout<<"pushback#1"<<std::endl;
    v1.push_back(&(*k2));
	std::cout<<"pushback#1"<<std::endl;
    v1.push_back(&(*k3));
	std::cout<<"pushback#1"<<std::endl;
    v1.push_back(&(*k4));
	std::cout<<"start insert"<<std::endl;
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }
	std::cout<<"======="<<std::endl;
	std::cout<<"======="<<std::endl;
	std::cout<<"======="<<std::endl;
    return v;
}

template <typename T>
std::vector<int> insert_test_3(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    g_start2 = timer();
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    g_end2 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

	std::cout<<"======="<<std::endl;
	std::cout<<"======="<<std::endl;
	std::cout<<"start"<<std::endl;
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
	std::cout<<"A vector construct"<<std::endl;
    _vector<A> vv;
	std::cout<<"B vector construct"<<std::endl;
    _vector<B*> v1;

	std::cout<<"pushback#1"<<std::endl;
    v1.push_back(&(*k2));
	std::cout<<"pushback#1"<<std::endl;
    v1.push_back(&(*k3));
	std::cout<<"pushback#1"<<std::endl;
    v1.push_back(&(*k4));
	std::cout<<"start insert"<<std::endl;
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("insert(range)", insert_test_3, insert_test_3));
}
