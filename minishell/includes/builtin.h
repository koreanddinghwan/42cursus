/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:44:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 13:39:02 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <string.h>
# include "structs.h"
# include "libft.h"
# include "lexer.h"

void	ft_swap(char **s1, char **s2);
int		ft_isunder(int c);
int		get_argv_count(char **argv);
void	update_env_arr(t_data *data);
void	free_env_lst(t_envlst *lst);
void	ft_env(t_data *data, char **args);
void	ft_cd(t_data *data, char **path);
void	ft_pwd(void);
void	ft_export(t_data *data, char **args);
void	ft_unset(t_data *data, char **args);
void	ft_echo(t_data *data, char **argv);
void	ft_exit(t_data *data, char **argv);
int		ft_isunder(int c);

#endif
