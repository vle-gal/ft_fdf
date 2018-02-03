/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:10:06 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/27 22:54:41 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iterative_power(int nb, int power)
{
	int n;

	n = nb;
	if (power == 0)
		return (1);
	if (power < 1)
	{
		return (0);
	}
	while (power > 1)
	{
		nb = nb * n;
		power--;
	}
	return (nb);
}
