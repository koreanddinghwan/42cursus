/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:12:34 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 20:58:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max_x(t_dlst *pixel_list)
{
	int	x;

	x = ((t_pixel *)pixel_list->content)->x_printing_win;
	while (pixel_list)
	{
		if (x < ((t_pixel *)pixel_list->content)->x_printing_win)
			x = ((t_pixel *)pixel_list->content)->x_printing_win;
		pixel_list = pixel_list->next;
	}
	return (x);
}

int	get_max_y(t_dlst *pixel_list)
{
	int	y;

	y = ((t_pixel *)pixel_list->content)->y_printing_win;
	while (pixel_list)
	{
		if (y < ((t_pixel *)pixel_list->content)->y_printing_win)
			y = ((t_pixel *)pixel_list->content)->y_printing_win;
		pixel_list = pixel_list->next;
	}
	return (y);
}

void	open_window(t_mlx *mlx)
{
	int	max_x;
	int	max_y;

	max_x = get_max_x(*(mlx->pixel_list));
	max_y = get_max_y(*(mlx->pixel_list));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, max_x, max_y, "fdf");
}
