/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:10:08 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 20:58:19 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	call_upper(t_bresen *bresen_num_set, t_mlx *mlx, int color)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < bresen_num_set->dy)
	{
		bresen_num_set->y += bresen_num_set->addy;
		counter += bresen_num_set->dx;
		if (counter >= bresen_num_set->dy)
		{
			bresen_num_set->x += bresen_num_set->addx;
			counter -= bresen_num_set->dy;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,
			bresen_num_set->x, bresen_num_set->y, color);
		i++;
	}
}

static void	call_lower(t_bresen *bresen_num_set, t_mlx *mlx, int color)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < bresen_num_set->dx)
	{
		bresen_num_set->x += bresen_num_set->addx;
		counter += bresen_num_set->dy;
		if (counter >= bresen_num_set->dx)
		{
			bresen_num_set->y += bresen_num_set->addy;
			counter -= bresen_num_set->dx;
		}
		i++;
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,
			bresen_num_set->x, bresen_num_set->y, color);
	}
}

static void	set_bresen_nums(t_bresen *bresen_num_set,
		t_pixel *start, t_pixel *end)
{
	bresen_num_set->dx = end->x_printing_win - start->x_printing_win;
	bresen_num_set->dy = end->y_printing_win - start->y_printing_win;
	bresen_num_set->x = start->x_printing_win;
	bresen_num_set->y = start->y_printing_win;
	if (bresen_num_set->dx < 0)
	{
		bresen_num_set->addx = -1;
		bresen_num_set->dx *= -1;
	}
	else
		bresen_num_set->addx = 1;
	if (bresen_num_set->dy < 0)
	{
		bresen_num_set->addy = -1;
		bresen_num_set->dy *= -1;
	}
	else
		bresen_num_set->addy = 1;
}

void	bresenham(t_pixel *start, t_pixel *end, t_mlx *mlx, int color)
{
	t_bresen	bresen_num_set;

	set_bresen_nums(&bresen_num_set, start, end);
	if (bresen_num_set.dx >= bresen_num_set.dy)
		call_lower(&bresen_num_set, mlx, color);
	else
		call_upper(&bresen_num_set, mlx, color);
}
