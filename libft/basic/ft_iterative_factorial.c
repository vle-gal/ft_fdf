/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:18:58 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/27 22:54:10 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iterative_factorial(int nbr)
{
	int n;

	if (nbr == 0 || nbr == 1)
	{
		return (1);
	}
	if (nbr > 12 || nbr < 0)
	{
		return (0);
	}
	else
	{
		n = nbr - 1;
		while (n != 1)
		{
			nbr = nbr * n;
			n--;
		}
	}
	return (nbr);
}
