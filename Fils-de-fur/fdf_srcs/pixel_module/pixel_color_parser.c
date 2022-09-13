/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:00:28 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 19:42:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	get_index(char c, char *small, char *cap)
{
	int		i;

	i = 0;
	while (cap[i])
	{
		if (c == cap[i])
			return (i);
		i++;
	}
	i = 0;
	while (small[i])
	{
		if (c == small[i])
			return (i);
		i++;
	}
	return (0);
}

static int	find_hex_str(char c)
{
	char	*cap;
	char	*small;

	small = "0123456789abcdef";
	cap = "0123456789ABCDEF";
	return (get_index(c, small, cap));
}

static int	convert_hex_ascii(char *str)
{
	int		rtn;

	rtn = 0;
	while (*str)
	{
		rtn = 16 * rtn + find_hex_str(*str);
		str++;
	}
	return (rtn);
}

int	pixel_color_parser(char *str)
{
	while (*str != 'x')
		str++;
	str++;
	return (convert_hex_ascii(str));
}
