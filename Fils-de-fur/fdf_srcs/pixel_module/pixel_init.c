/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:29:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 21:00:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static double	get_x(int x, int y, int angle)
{
	double	a;

	a = tan(angle * M_PI / 180);
	return (((x - y) * a));
}

static double	get_y(int x, int y, int z, int angle)
{
	double	a;

	a = cos(angle * M_PI / 180) / sin(angle * M_PI / 180);
	return ((a * (x + y) - z * a));
}

static void	set_x_y_in_window(t_pixel *new)
{
	new->x_in_window = get_x(new->map_x, new->map_y, 60);
	new->y_in_window = get_y(new->map_x, new->map_y, new->map_z, 60);
}

static int	add_pixel_to_list(char *str, t_dlst **pixel_list_addr, int x, int y)
{
	char	**split_by_comma;
	t_pixel	*new;

	split_by_comma = ft_split(str, ',');
	new = ft_calloc(1, sizeof(t_pixel));
	if (!new)
		return (-1);
	new->map_x = x;
	new->map_y = y;
	new->map_z = ft_atoi(split_by_comma[0]);
	set_x_y_in_window(new);
	if (split_by_comma[1])
		new->color = pixel_color_parser(split_by_comma[1]);
	else
		new->color = DEFAULT_COLOR;
	free_split(split_by_comma);
	ft_dlst_pushback(pixel_list_addr, ft_dlst_new(new));
	return (1);
}

void	init_pixel(t_dlst *line_list,
		t_dlst **line_list_addr, t_dlst **pixel_list_addr)
{
	int		x;
	int		y;
	char	**splited;

	y = 0;
	while (line_list)
	{
		splited = ft_split((char *)line_list->content, ' ');
		x = 0;
		while (splited[x])
		{
			if (-1 == add_pixel_to_list(splited[x], pixel_list_addr, x, y))
			{
				free_split(splited);
				ft_dlst_clear(pixel_list_addr, free);
				call_error_free_list("pixel add error\n", line_list_addr);
			}
			x++;
		}
		free_split(splited);
		line_list = line_list->next;
		y++;
	}
}
