#ifndef DATA_HPP
# define DATA_HPP
#include <stdint.h>
#include <iostream>

typedef struct s_data
{
	int n;
} Data;

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif
