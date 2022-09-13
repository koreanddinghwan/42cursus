/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_correction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:28:45 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 20:59:55 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_min_x(t_dlst *pixel_list)
{
	double	rtn;
	double	x;

	rtn = 0;
	while (pixel_list)
	{
		x = ((t_pixel *)pixel_list->content)->x_in_window;
		if (x < rtn && x < 0)
			rtn = ((t_pixel *)pixel_list->content)->x_in_window;
		pixel_list = pixel_list->next;
	}
	return (rtn);
}

static double	get_min_y(t_dlst *pixel_list)
{
	double	rtn;
	double	y;

	rtn = 0;
	while (pixel_list)
	{
		y = ((t_pixel *)pixel_list->content)->y_in_window;
		if (y < rtn && y < 0)
			rtn = ((t_pixel *)pixel_list->content)->y_in_window;
		pixel_list = pixel_list->next;
	}
	return (rtn);
}

static void	correction(double min_x, double min_y, t_pixel *pixel)
{
	pixel->x_in_window += fabs(min_x);
	pixel->y_in_window += fabs(min_y);
}

void	pixel_correction(t_dlst **pixel_list)
{
	double	min_x;
	double	min_y;
	t_dlst	*pixel_cur;

	min_x = get_min_x(*pixel_list);
	min_y = get_min_y(*pixel_list);
	pixel_cur = *pixel_list;
	while (pixel_cur)
	{
		correction(min_x, min_y, (t_pixel *)pixel_cur->content);
		pixel_cur = pixel_cur->next;
	}
}
