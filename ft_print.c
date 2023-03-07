/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:48:09 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/07 20:26:57 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	print_not_per(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*n += *fmt - *start;
	return ;
}

int	check_conv(const char **start, const char **fmt, int *n, va_list *ap)
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
		ft_putchar_n(n, *fmt, 1);
	}
	(*fmt)++;
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
			check_conv(&start, &fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}

// int main()
// {
// 	char p[] = "pp";
// 	printf("%d\n",printf("/----d-----/"));
// 	printf("%d\n",printf("%d"));
// 	printf("%d\n",ft_printf("%d"));
// 	printf("%d\n",printf("%      d"));
// 	printf("%d\n",ft_printf("%      d"));
// 	printf("%d\n",printf("%d",0));
// 	printf("%d\n",ft_printf("%d",0));
// 	printf("%d\n",printf("%d",INT_MAX + 1));
// 	printf("%d\n",ft_printf("%d",INT_MAX + 1));
// 	printf("%d\n",printf("%d",INT_MAX));
// 	printf("%d\n",ft_printf("%d",INT_MAX));
// 	printf("%d\n",printf("%d",LONG_MAX));
// 	printf("%d\n",ft_printf("%d",LONG_MAX));
// 	printf("%d\n",printf("/----c-----/"));
// 	printf("%d\n",printf("[%c]", NULL));
// 	printf("%d\n",ft_printf("[%c]", NULL));
// 	printf("%d\n",printf("[%c]", '\0'));
// 	printf("%d\n",ft_printf("[%c]", '\0'));
// 	printf("%d\n",printf("[%c]", 3));
// 	printf("%d\n",ft_printf("[%c]", 3));
// 	printf("%d\n",printf("/----s-----/"));
// 	printf("%d\n",printf("[%sa]", NULL));
// 	printf("%d\n",ft_printf("[%sa]", NULL));
// 	printf("%d\n",printf("[%sa]", "\0"));
// 	printf("%d\n",ft_printf("[%sa]", "\0"));
// 	printf("%d\n",printf("[%sa]", p));
// 	printf("%d\n",ft_printf("[%sa]", p));
// 	printf("%d\n",printf("/----p-----/"));
// 	printf("%d\n",printf("[%p]", NULL));
// 	printf("%d\n",ft_printf("[%p]", NULL));
// 	printf("%d\n",printf("[%p]", p));
// 	printf("%d\n",ft_printf("[%p]", p));
// 	printf("%d\n",printf("[%p]", 345678));
// 	printf("%d\n",ft_printf("[%p]", 345678));
// 	printf("%d\n",printf("/----x-----/"));
// 	printf("%d\n",printf("[%x]", 12345678));
// 	printf("%d\n",ft_printf("[%x]", 12345678));
// 	printf("%d\n",printf("[%x]", p));
// 	printf("%d\n",ft_printf("[%x]", p));
// 	printf("%d\n",printf("[%x]", 0));
// 	printf("%d\n",ft_printf("[%x]", 0));
// 	printf("%d\n",printf("[%x]", 0x0));
// 	printf("%d\n",ft_printf("[%x]", 0x0));
// 	printf("%d\n",printf("[% x]", p));
// 	printf("%d\n",ft_printf("[% x]", p));
// 	// printf("%p\n",(unsigned long long)0);
// 	// ft_printf("as\n%s\n%p\n%p\n%u\n%u\n#\n","bbb",p,(void *)2345678,(long unsigned int)p,2345678);
// 	return 0;
// }