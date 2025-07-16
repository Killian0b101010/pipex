/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:51:45 by kiteixei          #+#    #+#             */
/*   Updated: 2025/06/18 23:01:08 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Fonction qui permet de print les hexa (x et X)
 *
 * @param unsignedinthexintmaj hex + maj

 * @return La len de hex (count)
 */

int	ft_puthex(unsigned int hex, int maj)
{
	int		count;
	char	*base;

	count = 0;
	if (maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (hex >= 16)
		count += ft_puthex(hex / 16, maj);
	count += ft_putchar(base[hex % 16]);
	return (count);
}
