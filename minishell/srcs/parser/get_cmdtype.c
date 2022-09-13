/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:19:33 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 14:50:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

enum e_cmdtype	get_cmdtype(char *cmd)
{
	if (check_builtin(cmd))
		return (E_BUILTIN);
	else
		return (E_CMD);
}
