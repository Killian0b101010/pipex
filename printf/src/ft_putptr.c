/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:19:45 by kiteixei          #+#    #+#             */
/*   Updated: 2025/06/18 23:01:09 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Fonction qui permet de print les pointeurs
 *
 * @param void Prend en param un void *

 * @return La len du ptr
 */
int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(NILL)", 6));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_put_hex_long_long((unsigned long long)ptr);
	return (count);
}
