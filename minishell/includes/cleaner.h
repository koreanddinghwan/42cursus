/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:04 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 11:15:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANER_H
# define CLEANER_H
# include "structs.h"

void	lexer_tok_free(void *cur);
void	cleaner(t_data *data);
void	lexer_free(t_data *data);
void	token_free(t_data *data);
void	cmd_cont_free(void *param);

#endif
