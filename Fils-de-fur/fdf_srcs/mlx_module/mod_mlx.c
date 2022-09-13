/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:05:36 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 16:41:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	esc_key(int key, void *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window((*(t_mlx *)mlx).mlx_ptr, (*(t_mlx *)mlx).win_ptr);
		ft_dlst_clear((*(t_mlx *)mlx).pixel_list, free);
		exit(1);
	}
	return (0);
}

void	mod_mlx(t_dlst **pixel_list)
{
	void	*mlx_ptr;
	t_mlx	mlx;

	mlx_ptr = mlx_init();
	mlx.mlx_ptr = mlx_ptr;
	mlx.pixel_list = pixel_list;
	open_window(&mlx);
	pixel_print(&mlx);
	mlx_key_hook(mlx.win_ptr, esc_key, (void *)&mlx);
	mlx_loop(mlx_ptr);
}
