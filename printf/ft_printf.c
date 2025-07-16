/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:56:23 by kiteixei          #+#    #+#             */
/*   Updated: 2025/05/16 19:00:13 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Fonction principale qui execute et return la len final.
 *
 * @param format C'est l'argument %(d,s,u,x,X,p,c).

 * @return La somme de l'input de l'utilsateur
 */
int	ft_printf(const char *format, ...)
{
	int		result;
	int		index;
	va_list	args;

	result = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[index])
		{
			index++;
			result += ft_parse_printf(format[index], args);
			index++;
		}
		else
		{
			result += ft_putchar(format[index]);
			index++;
		}
	}
	va_end(args);
	return (result);
}
