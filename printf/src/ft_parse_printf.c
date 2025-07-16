/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:28:40 by kiteixei          #+#    #+#             */
/*   Updated: 2025/06/18 23:01:05 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Fonction qui permet de recuperer les flags %
 *
 * @param int Prend le char et l'args en parametre

 * @return La len de l'input de l'utilisateur
 */
int	ft_parse_printf(const char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, int), 1));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
	{
		ft_putchar('%');
		ft_putchar(c);
		return (2);
	}
}
