/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:45:18 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 15:20:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H
# include "structs.h"
# include "getter.h"

int		get_replaced_len(char *str, t_data *data);
char	*get_replaced(t_data *data, char *str);
void	cpy_replaced(char *rtn, char *str, t_data *data, int len);
char	*make_possible_cp(char *str);
#endif
