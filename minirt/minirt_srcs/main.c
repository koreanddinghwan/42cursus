#include "../includes/main.h"

void arg_validation(int ac)
{
	if (ac < 2 || ac > 2)
	{
		write(2, ARG_ERROR, ft_strlen(ARG_ERROR)); 
		exit(1);
	}
}

int main(int ac, char *av[])
{
	t_data data;

	arg_validation(ac);
	ft_memset(&data, 0, sizeof(t_data));
	fill_data(av[1], &data);
	//

	//start_rendering(data);
	return (0);
}
