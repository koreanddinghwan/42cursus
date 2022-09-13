/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:45:32 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 15:20:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	call_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	call_error_clear(t_dlst **a)
{
	ft_dlst_clear(a, free);
	call_error();
}

void	call_error_stack_clear(t_dlst **a, t_dlst **b)
{
	ft_dlst_clear(a, free);
	ft_dlst_clear(b, free);
	call_error();
}

void	call_error_av_stack_clear(t_dlst **a, char **av)
{
	int	i;

	i = 1;
	while (av[i] != 0)
		free(av[i++]);
	ft_dlst_clear(a, free);
	call_error();
}

void	call_error_av_stack_allclear(t_dlst **a, t_dlst **b,
		char **av, int *list)
{
	int	i;

	i = 1;
	while (av[i] != 0)
		free(av[i++]);
	ft_dlst_clear(a, free);
	ft_dlst_clear(b, free);
	free(list);
	call_error();
}
