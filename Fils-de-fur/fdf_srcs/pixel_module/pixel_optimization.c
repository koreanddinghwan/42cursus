/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:57:45 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 21:01:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_printing_cor(t_dlst	**cur_pixel_list,
		t_dlst **pixel_list, t_pixel *cur_pixel, int z_set[2])
{
	int	calculed_x;
	int	calculed_y;

	cur_pixel = (t_pixel *)((*cur_pixel_list)->content);
	calculed_x = cur_pixel->x_in_window * z_set[0];
	calculed_y = cur_pixel->y_in_window * z_set[1];
	if (calculed_x >= 2560 || calculed_y >= 1440)
	{
		if (calculed_x >= 2560)
			z_set[0]--;
		if (calculed_y >= 1440)
			z_set[1]--;
		*cur_pixel_list = *pixel_list;
		return ;
	}
	cur_pixel->x_printing_win = calculed_x;
	cur_pixel->y_printing_win = calculed_y;
	*cur_pixel_list = (*cur_pixel_list)->next;
}

void	pixel_optimization(t_dlst **pixel_list)
{
	t_dlst	*cur_pixel_list;
	t_pixel	*cur_pixel;
	int		z_set[2];

	z_set[0] = DEFAULT_Z_PIXEL_PER_LEN;
	z_set[1] = DEFAULT_Z_PIXEL_PER_LEN;
	cur_pixel_list = *pixel_list;
	while (1)
	{
		while (cur_pixel_list)
		{
			cur_pixel = (t_pixel *)(cur_pixel_list->content);
			set_printing_cor(&cur_pixel_list, pixel_list, cur_pixel, z_set);
		}
		if (!cur_pixel_list)
			break ;
		if (z_set[0] <= 0 || z_set[0] <= 0)
		{	
			call_error_free_list("Too large Map\n", pixel_list);
			break ;
		}
	}
}
