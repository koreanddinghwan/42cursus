/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:31:17 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 18:18:08 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_data(t_data *data, char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return ;
	}
	add_history(line);
	data->command = line;
	if (tokenizer(data) == FAIL)
	{
		token_free(data);
		return ;
	}
	if (lexer(data) == FAIL)
	{
		lexer_free(data);
		return ;
	}
	parser(data);
	execute(data);
	cleaner(data);
}
