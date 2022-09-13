#include "../../includes/map.h"

void fill_data(char *map, t_data *data)
{
	int 	fd;
	char *str;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error(FD_ERROR);
	str = get_next_line(fd);
}
