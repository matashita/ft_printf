/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:48:09 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/10 15:39:01 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conv(const char **fmt, size_t *n, va_list *ap)
{
	void	*p;

	(*fmt)++;
	if (**fmt == 'c')
		ft_print_c(n, (char)va_arg(*ap, int));
	else if (**fmt == 's')
		ft_print_s(n, (char *)va_arg(*ap, char *));
	else if (**fmt == 'p')
		ft_print_p(n, (void *)va_arg(*ap, void *));
	else if (**fmt == 'd' || **fmt == 'i' )
		ft_putnbr_n(n, (int)va_arg(*ap, int), 1);
	else if (**fmt == 'u')
		ft_putunbr_n(n, (unsigned int)va_arg(*ap, int), 1);
	else if (**fmt == 'x')
		ft_itoa_hex(n, (unsigned int)va_arg(*ap, int), 'x');
	else if (**fmt == 'X')
		ft_itoa_hex(n, (unsigned int)va_arg(*ap, int), 'X');
	else if (**fmt == '%')
		ft_putchar_n(n, '%', 1);
	else
	{
		ft_putchar_n(n, '%', 1);
		ft_putchar_n(n, **fmt, 1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	size_t		n;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
	{
		va_end(ap);
		return (-1);
	}
	while (n >= 0 && *fmt)
	{
		if (*fmt != '%')
			ft_putchar_n(&n, *fmt, 1);
		else
			check_conv(&fmt, &n, &ap);
		fmt++;
	}
	va_end(ap);
	return ((int)n);
}
