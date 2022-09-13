/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:48:29 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 21:07:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

# define DEFAULT_COLOR 0xFFFFFF
# define DEFAULT_Z_PIXEL_PER_LEN 7

typedef struct s_pixel
{
	int			map_x;
	int			map_y;
	int			map_z;
	double		x_in_window;
	double		y_in_window;
	int			x_printing_win;
	int			y_printing_win;
	int			color;
}	t_pixel;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_dlst	**pixel_list;
}	t_mlx;

typedef struct s_bresen
{
	int	addx;
	int	addy;
	int	dx;
	int	dy;
	int	x;
	int	y;
}	t_bresen;

void	fils_de_fer(char *av);
void	get_map_list(char	*path, t_dlst **line_list);
void	init_pixel(t_dlst *line_list,
			t_dlst **line_list_addr, t_dlst **pixel_list_addr);
int		pixel_color_parser(char *str);
void	pixel_correction(t_dlst **pixel_list);
void	pixel_optimization(t_dlst **pixel_list);
void	mod_mlx(t_dlst **pixel_list);
void	open_window(t_mlx *mlx);
void	pixel_print(t_mlx *mlx);
void	bresenham(t_pixel *start, t_pixel *end, t_mlx *mlx, int color);
void	call_error_free_list(char *str, t_dlst **pixel_list);
void	call_error(char	*str);
void	free_split(char **splited);
int		extension_check_module(char *path);
#endif
