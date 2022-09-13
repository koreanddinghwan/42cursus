#include "../../includes/tools.h"

void print_error(char *string)
{
	ft_printf_fd("%s\n", 2, string);
	exit(1);
}
