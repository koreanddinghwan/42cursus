#ifndef VECTOR3_H
# define VECTOR3_H

#include <math.h>

typedef struct s_vec3
{
	double x;
	double y;
	double z;
}t_vec3;

inline t_vec3 *vec3_add_to(t_vec3 *a, t_vec3 *b);
inline t_vec3 *vec3_multiple_to(t_vec3 *a, t_vec3 *b);
inline t_vec3 vec3_add(t_vec3 *a, t_vec3 *b);
inline t_vec3 vec3_minus(t_vec3 *a, t_vec3 *b);
inline t_vec3 vec3_mul(t_vec3 *a, double f);
inline t_vec3 vec3_divide(t_vec3 *a, double f);
inline double vec3_dot_product(t_vec3 *a, t_vec3 *b);
inline t_vec3 vec3_cross_product(t_vec3 *a, t_vec3 *b);
inline double vec3_len(t_vec3 *a);

#endif
