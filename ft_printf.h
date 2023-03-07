/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyamada <teyamada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:41:35 by teyamada          #+#    #+#             */
/*   Updated: 2023/03/06 22:23:48 by teyamada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *fmt, ...);
int		check_conv(const char **start, const char **fmt, int *n, va_list *ap);
void	print_not_per(const char **start, const char **fmt, int *n);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar_n(int *n, char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_n(int *n, int i, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putunbr_n(int *n, unsigned int u, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_n(int *n, char *s, int fd);
void	ft_itoa_hex(int *n, unsigned long long int ui, char flag);
void	ft_print_c(int *n, char ap);
void	ft_print_s(int *n, char *ap);
void	ft_print_p(int *n, void *ap);

#endif