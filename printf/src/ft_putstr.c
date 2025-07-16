/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:58:00 by kiteixei          #+#    #+#             */
/*   Updated: 2025/05/16 18:51:04 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Fonction qui permet de print %s
 *
 * @param char Prend un char et le parcours

 * @return La len de l'input de l'utilisateur (return null si chaine vide)
 */
#include "../ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
