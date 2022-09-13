/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:58:17 by myukang           #+#    #+#             */
/*   Updated: 2022/04/22 17:44:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_print_conv(char	*fmt, va_list *ap)
{
	int		rtn;
	int		fd;

	rtn = 0;
	fd = 1;
	if (*fmt == 'c')
		rtn += ft_putchar_fd((char)va_arg(*ap, int), fd);
	else if (*fmt == 's')
		rtn += ft_putstr_fd((char *)va_arg(*ap, char *), fd);
	else if (*fmt == 'p')
		rtn += ft_print_pointer((void *)va_arg(*ap, void *));
	else if ((*fmt == 'd') || (*fmt == 'i'))
		rtn += ft_putnbr_fd((int)va_arg(*ap, int), fd);
	else if (*fmt == 'u')
		rtn += ft_putnbr_unsigned((unsigned int)va_arg(*ap, unsigned int), fd);
	else if (*fmt == 'x')
		rtn += ft_putnbr_hex((int)va_arg(*ap, int), -1);
	else if (*fmt == 'X')
		rtn += ft_putnbr_hex((int)va_arg(*ap, int), 1);
	else if (*fmt == '%')
		rtn += ft_putchar_fd('%', fd);
	return (rtn);
}

int	ft_printf(const char *fmt, ...)
{
	int		rtn;
	va_list	ap;

	if (fmt == 0)
		return (0);
	va_start(ap, fmt);
	rtn = 0;
	while (*fmt != 0)
	{
		if (*fmt != 37)
		{
			ft_putchar_fd(*fmt, 1);
			fmt++;
			rtn++;
			continue ;
		}
		fmt++;
		if (*fmt == 0)
			return (rtn);
		rtn += ft_print_conv((char *)fmt, &ap);
		fmt++;
	}
	va_end(ap);
	return (rtn);
}
