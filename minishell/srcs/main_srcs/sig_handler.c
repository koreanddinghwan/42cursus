/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:43:59 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 18:15:45 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sigint_handler(int sig)
{
	(void)sig;
	printf("\033[%dC  \n", rl_end + 9);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	set_handler(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
