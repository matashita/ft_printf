/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:15:34 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/10 16:03:11 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_hex(ssize_t *n, unsigned long long int ui, char flag)
{
	if (ui > 15)
	{
		ft_itoa_hex(n, ui / 16, flag);
		ft_itoa_hex(n, ui % 16, flag);
	}
	else if (ui >= 10 && flag == 'x')
		ft_putchar_n(n, (char)(ui + 87), 1);
	else if (ui >= 10 && flag == 'X')
		ft_putchar_n(n, (char)(ui + 55), 1);
	else
		ft_putchar_n(n, (char)(ui + 48), 1);
	return ;
}

void	ft_print_c(ssize_t *n, char ap)
{
	ft_putchar_n(n, ap, 1);
}

void	ft_print_s(ssize_t *n, char *ap)
{
	if (ap == NULL)
	{
		ft_putstr_n(n, "(null)", 1);
		return ;
	}
	ft_putstr_n(n, ap, 1);
}

void	ft_print_p(ssize_t *n, void *ap)
{
	unsigned long long int	ui;

	if (ap == NULL)
	{
		ft_putstr_n(n, "0x0", 1);
		return ;
	}
	ui = (unsigned long long int)ap;
	ft_putstr_n(n, "0x", 1);
	ft_itoa_hex(n, ui, 'x');
}
