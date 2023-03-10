/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:46:14 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/10 15:31:24 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sub_putnbr_n(size_t *n, int i, int fd)
{
	if (i == 0)
		return ;
	ft_sub_putnbr_n(n, i / 10, fd);
	ft_putchar_n(n, i % 10 + '0', fd);
}

void	ft_putnbr_n(size_t *n, int i, int fd)
{
	if (i == 0)
	{
		ft_putchar_n(n, '0', fd);
		return ;
	}
	if (i == -2147483648)
	{
		ft_putstr_n(n, "-214748364", fd);
		i = 8;
	}
	if (i < 0)
	{
		i *= -1;
		ft_putchar_n(n, '-', fd);
	}
	ft_sub_putnbr_n(n, i, fd);
	return ;
}
