#include "../../includes/vector3.h"

inline t_vec3 *vec3_add_to(t_vec3 *a, t_vec3 *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

inline t_vec3 *vec3_multiple_to(t_vec3 *a, t_vec3 *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
	return (a);
}

inline t_vec3 vec3_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3 rtn;

	rtn.x = a->x + b->x;
	rtn.y = a->y + b->y;
	rtn.z = a->z + b->z;
	return (rtn);
}

inline t_vec3 vec3_minus(t_vec3 *a, t_vec3 *b)
{
	t_vec3 rtn;

	rtn.x = a->x - b->x;
	rtn.y = a->y - b->y;
	rtn.z = a->z - b->z;
	return (rtn);
}

inline t_vec3 vec3_mul(t_vec3 *a, double f)
{
	t_vec3 rtn;

	rtn.x = a->x * f;
	rtn.y = a->y * f;
	rtn.z = a->z * f;
	return (rtn);
}

inline t_vec3 vec3_divide(t_vec3 *a, double f)
{
	return (vec3_mul(a, 1/f));
}

/*
 * 벡터 내적
 * 두 벡터가 얼마나 같은 방향을 가리키는가?
 * */
inline double vec3_dot_product(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z + b->z);
}

/*
 * 벡터 외적, 벡터 곱
 * */
inline t_vec3 vec3_cross_product(t_vec3 *a, t_vec3 *b)
{
	t_vec3 rtn;

	rtn.x = a->y * b->z - a->z * b->y;
	rtn.y = a->z * b->x - a->x * b->z;
	rtn.z = a->x * b->y - a->y * b->x;
	return (rtn);
}

inline double vec3_len(t_vec3 *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}
