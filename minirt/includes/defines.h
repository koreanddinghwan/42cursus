#ifndef DEFINES_H
# define DEFINES_H

#include "vector3.h"
#define FALSE 0
#define TRUE 1

#define FAIL 0
#define SUCCESS 1

#define ARG_ERROR "Invalid Map Name\nError\n"
#define FD_ERROR "No Map Found!\nError\n"
#define MAP_VALIDATION_ERROR "Wrong Map Used\nError\n"

//주변광
typedef struct s_amblight
{
	double ratio;
	t_vec3 rgb;
} t_amblight;

//카메라
typedef struct s_camera
{
	t_vec3 view_point;
	t_vec3 normalize;
	double fov;
} t_camera;

//주광
typedef struct s_light
{
	t_vec3 lightpoint;
	double    ratio;
	t_vec3 rgb;
} t_light;

//도형
typedef struct s_sphere
{
	int status;
	t_vec3 center;
	double diameter;
	t_vec3 rgb;
} t_sphere;

typedef struct s_plane
{
	int status;
	t_vec3 center;
	t_vec3 normalize;
	t_vec3 rgb;
} t_plane;

typedef struct s_cylinder
{
	int status;
	t_vec3 center;
	t_vec3 normalize;
	double diameter;
	double height;
	t_vec3 rgb;
} t_cylinder;

typedef struct s_cone
{
	int status;
	t_vec3 center;
	t_vec3 normalize;
	double diameter;
	double height;
	t_vec3 rgb;
} t_cone;

typedef struct s_data
{
	t_camera	camera;
	t_light	light;
	t_amblight	amblight;
	t_sphere	sphere;
	t_plane 	plane;
	t_cylinder 	cylinder;
	t_cone 	cone;
} t_data;

#endif
