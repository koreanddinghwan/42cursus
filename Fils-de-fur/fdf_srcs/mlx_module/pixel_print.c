/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:45:20 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 20:59:29 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel	*find_right_pixel(t_dlst *cur, t_pixel *start)
{
	int		map_x;
	int		map_y;
	t_dlst	*next;

	map_x = start->map_x;
	map_y = start->map_y;
	next = cur->next;
	if (!next)
		return (0);
	if ((map_x + 1 == ((t_pixel *)next->content)->map_x)
		&& (map_y == ((t_pixel *)next->content)->map_y))
		return ((t_pixel *)next->content);
	else
		return (0);
	return (0);
}

static t_pixel	*find_down_pixel(t_dlst *cur, t_pixel *start)
{
	int	map_x;
	int	map_y;

	map_x = start->map_x;
	map_y = start->map_y;
	while (cur && (((t_pixel *)cur->content)->map_y == map_y))
		cur = cur->next;
	if (!cur)
		return (0);
	while (cur && (((t_pixel *)cur->content)->map_y == map_y + 1))
	{
		if (((t_pixel *)cur->content)->map_x == map_x)
			return (cur->content);
		cur = cur->next;
	}
	return (0);
}

void	pixel_print(t_mlx *mlx)
{
	t_dlst	*cur;
	t_pixel	*start;
	t_pixel	*right;
	t_pixel	*down;

	cur = *(mlx->pixel_list);
	while (cur)
	{
		start = (t_pixel *)(cur->content);
		right = find_right_pixel(cur, start);
		down = find_down_pixel(cur, start);
		if (right)
			bresenham(start, right, mlx, right->color);
		if (down)
			bresenham(start, down, mlx, down->color);
		cur = cur->next;
	}
}
