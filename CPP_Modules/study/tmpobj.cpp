#include <iostream>
using namespace std;

class SoSimple
{
	private:
		int num;
	public:
	SoSimple(int n) : num(n)
	{
		cout<<"New Object : "<<this<<endl;
	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout<<"Copy Target Obj : "<<&copy<<endl;
		cout<<"New Copy Obj : "<<this<<endl;
	}
	~SoSimple()
	{
		cout<<"Destroy Obj : "<<this<<endl;
	}
};

SoSimple SoSimpleFunction(SoSimple ob)
{
	cout<<"Param ADR : "<<&ob<<endl;
	return (ob);
}

int main(void)
{
	cout<<"obj(7)"<<endl;
	SoSimple obj(7);
	cout<<endl;
	cout<<"function(obj)"<<endl;
	SoSimpleFunction(obj);
	cout<<endl;

	cout<<endl;
	cout<<"obj = function(obj)"<<endl;
	SoSimple tempref = SoSimpleFunction(obj);
	cout<<endl;
	cout<<"return obj : "<<&tempref<<endl;
	return (0);
}
