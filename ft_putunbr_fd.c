/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:46:14 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/06 02:15:29 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sub_putnbr(unsigned int n, int fd)
{
	if (n == 0)
		return ;
	ft_sub_putnbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == 4294967295)
	{
		ft_putstr_fd("4294967295", fd);
		return ;
	}
	ft_sub_putnbr(n, fd);
	return ;
}

static void	ft_sub_putnbr_n(int *n, unsigned int u, int fd)
{
	if (u == 0)
		return ;
	ft_sub_putnbr_n(n, u / 10, fd);
	ft_putchar_n(n, u % 10 + '0', fd);
}

void	ft_putunbr_n(int *n, unsigned int u, int fd)
{
	if (u == 0)
	{
		ft_putchar_n(n, '0', fd);
		return ;
	}
	if (u == 4294967295)
	{
		ft_putstr_n(n, "4294967295", fd);
		return ;
	}
	ft_sub_putnbr_n(n, u, fd);
	return ;
}
