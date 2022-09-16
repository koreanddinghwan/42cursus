/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:46:33 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 14:42:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

class megaphone
{
	private:
		int argc;
		char **argv;
	public:
		megaphone(int ac, char **av) : argc(ac), argv(av)
		{}
		void broadcast(void);
};

void megaphone::broadcast(void)
{
	int		i;
	int		j;
	char	letter;

	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				letter = toupper(argv[i][j++]);
				std::cout<<letter;
			}
			i++;
		}
		std::cout<<std::endl;
	}
}

char *p = (char *) new int();

int	main(int ac, char **av)
{
	megaphone	megaphone(ac, av);

	megaphone.broadcast();
	return (0);
}
