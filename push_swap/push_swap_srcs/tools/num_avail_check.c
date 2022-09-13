/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_avail_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:07:04 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 21:26:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_is_num(char *str)
{
	t_size	i;
	t_size	len;
	int		status;

	i = 0;
	len = ft_strlen(str);
	status = 1;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
		{
			status = 0;
			break ;
		}
		i++;
	}
	return (status);
}

int	num_avail_check(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!ft_is_num((char *)str))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (result * sign > INTMAX || result * sign < INTMIN)
		return (0);
	else
		return (1);
}
