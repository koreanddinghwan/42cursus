/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:35:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 13:10:50 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include "structs.h"
# include "cleaner.h"
# include "builtin.h"

void	initialize_main(t_data *data, char **envp);
void	set_handler(void);
void	set_env_lst(t_data *data, char **envp);
void	set_env_arr(t_data *data);
char	**add_env_arr(t_data *data, char **args);
void	display_bash(t_data *data);
void	initialize_data(t_data *data, char *line);
int		tokenizer(t_data *data);
int		lexer(t_data *data);
void	parser(t_data *data);
void	execute(t_data *data);
#endif
