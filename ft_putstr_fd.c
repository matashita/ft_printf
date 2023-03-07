/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:46:31 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/06 01:45:32 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putstr_n(int *n, char *s, int fd)
{
	while (*s)
	{
		ft_putchar_n(n, *s, fd);
		s++;
	}
}
