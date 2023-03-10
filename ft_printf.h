/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:41:35 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/10 15:54:55 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *fmt, ...);
int		check_conv(const char **fmt, ssize_t *n, va_list *ap);
void	ft_putchar_n(ssize_t *n, char c, int fd);
void	ft_putnbr_n(ssize_t *n, int i, int fd);
void	ft_putunbr_n(ssize_t *n, unsigned int u, int fd);
void	ft_putstr_n(ssize_t *n, char *s, int fd);
void	ft_itoa_hex(ssize_t *n, unsigned long long int ui, char flag);
void	ft_print_c(ssize_t *n, char ap);
void	ft_print_s(ssize_t *n, char *ap);
void	ft_print_p(ssize_t *n, void *ap);

#endif