#include <iostream>

class Marine
{
	private:
		int hp;
		int coord_x, coord_y;
		const int damage;
		bool is_dead;
		static int total_marine_num;
	public:
		Marine();
		Marine(int x, int y);
		Marine(int x, int y, int default_damage);

		int attack();
		void be_attacked(int damage_earn);
		void move(int x, int y);

		void show_status();
		static void show_total_marine();
		~Marine()
		{
			std::cout<<"ASDF"<<std::endl;
			total_marine_num--;
		}
};

int Marine::total_marine_num = 0;

Marine::Marine()
	: hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false)
{
	total_marine_num++;
}

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false)
{
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : hp(50), coord_x(x), coord_y(y), damage(default_damage), is_dead(false)
{
	total_marine_num++;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack()
{
	return damage;
}

void Marine::be_attacked(int damage_earn)
{
	if (is_dead == false)
	{
		if (hp <= damage_earn)
		{
			hp = 0;
			is_dead = true;
		}
		else
		{
			hp -= damage_earn;
		}
	}
}

void Marine::show_status()
{
	std::cout<<"*** Marine ***"<<std::endl;
	std::cout<<"Location : "<<coord_x<<","<<coord_y<<std::endl;
	std::cout<<"HP"<< hp<<std::endl;
	std::cout<<"전체 마린 수"<<total_marine_num<<std::endl;
}

void	create_marine()
{
	Marine marine3(10, 10, 4);
	marine3.show_status();
}

void Marine::show_total_marine()
{
	std::cout<<"show total marine전체 마린 수 : "<<total_marine_num<<std::endl;
}

int main()
{
	Marine marine1(2, 3);
	Marine::show_total_marine();
	Marine marine2(3, 5);
	Marine::show_total_marine();

	marine1.show_status();
	marine2.show_status();
	create_marine();
	std::cout<<std::endl<<"marine 1 attacked 2"<<std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	return (0);
}
