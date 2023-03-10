/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:41:36 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/10 16:02:43 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_n(ssize_t *n, char c, int fd)
{
	if (*n >= 0)
	{
		if (write(fd, &c, 1) != -1)
			*n += 1;
		else
			*n = -1;
	}
}
