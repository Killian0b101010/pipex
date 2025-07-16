/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:19:53 by kiteixei          #+#    #+#             */
/*   Updated: 2025/07/15 15:38:48 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_put_hex_long_long(unsigned long long nbr);
int	ft_putptr(void *ptr);
int	ft_puthex(unsigned int hex, int maj);
int	ft_putunsigned(unsigned int n);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_parse_printf(const char c, va_list args);
int	ft_printf(const char *format, ...);
#endif
