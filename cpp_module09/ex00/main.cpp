//Todo cpp, hpp분리
#include "./BitcoinExchange.cpp"
#include "./UserDatabase.cpp"

class User {

	public:
		User() {}
		~User() {}

	private:
		User(User &o) {}
		User& operator=(User &o) {return *this;}

	public:
		void run(void) {

		}
};

int main(int ac, char *av[]) 
{
	UserDatabase userDatabase(ac, av);
	Exchanger exchanger("./data.csv");

	try {
	while(userDatabase.get())
	{

	}
	} catch (e) {

	}
	return 0; 
}
