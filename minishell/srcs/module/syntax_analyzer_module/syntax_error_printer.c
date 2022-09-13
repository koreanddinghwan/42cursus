/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:10:34 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 10:24:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyzer.h"

int	syntax_error_printer(char *str)
{
	ft_putstr_fd("mgyush > syntax error near unexpected token ", 2);
	ft_putendl_fd(str, 2);
	return (FAIL);
}
