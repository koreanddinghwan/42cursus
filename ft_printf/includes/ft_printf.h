/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:52:09 by myukang           #+#    #+#             */
/*   Updated: 2022/03/29 01:56:29 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft_srcs/libft.h"

int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_print_pointer(void *p);
int		ft_putnbr_hex(int n, int big_small);
int		ft_printf(const char *fmt, ...);

#endif
