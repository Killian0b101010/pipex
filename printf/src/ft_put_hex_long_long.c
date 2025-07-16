/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_long_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:44:22 by kiteixei          #+#    #+#             */
/*   Updated: 2025/06/18 23:01:07 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Fonction qui permet de print les pointeurs
 *

	* @param unsignedlonglong limite plus grande que le int classique pour print les
	%p

 * @return La len de l'adresse
 */
int	ft_put_hex_long_long(unsigned long long nbr)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_put_hex_long_long(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
