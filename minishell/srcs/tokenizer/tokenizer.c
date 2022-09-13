/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:41:46 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 10:21:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	all_space(t_token *tok_buf)
{
	int	spcnum;
	int	size;

	spcnum = 0;
	size = 0;
	while (tok_buf->type != END_C)
	{
		if (tok_buf->type == SPC)
			spcnum++;
		size++;
		tok_buf++;
	}
	if (size == spcnum)
		return (TRUE);
	else
		return (FALSE);
}

void	token_init(t_data *data)
{
	data->tok_buf = ft_calloc(sizeof(t_token), ft_strlen(data->command) + 1);
}

int	tokenizer(t_data *data)
{
	if (!data->command)
		return (FAIL);
	token_init(data);
	if (token_buf_build(data) == FAIL)
		return (FAIL);
	if (all_space(data->tok_buf) == TRUE)
		return (FAIL);
	return (SUCESS);
}
