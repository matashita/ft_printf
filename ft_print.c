/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:48:09 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/08 00:19:18 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_not_per(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*n += *fmt - *start;
	return ;
}

int	check_conv(const char **fmt, int *n, va_list *ap)
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
	int			n;
	const char	*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*fmt != '%')
			print_not_per(&start, &fmt, &n);
		else
		{
			check_conv(&fmt, &n, &ap);
			fmt++;
		}
	}
	va_end(ap);
	return (n);
}
