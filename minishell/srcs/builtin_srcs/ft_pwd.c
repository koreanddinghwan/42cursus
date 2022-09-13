/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:46 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/30 11:13:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_pwd(void)
{
	char	*loc;

	loc = (char *)malloc(sizeof(char) * 256);
	if (!getcwd(loc, 256))
		return ;
	else
		printf("%s\n", loc);
	free(loc);
}
