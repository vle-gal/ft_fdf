/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:21:21 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:39:07 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_before(const char *str, int c)
{
	while ((str[c] == '\r' || str[c] == '\t' || str[c] == '\v' ||
	str[c] == '\n' || str[c] == '\f' ||
	str[c] == ' '))
		c++;
	return (c);
}

int				ft_atoi(const char *str)
{
	int c;
	int nbr;
	int n;

	n = 0;
	c = 0;
	nbr = 0;
	c = ft_before(str, c);
	if (str[c] == '-')
		n = 1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (str[c] && str[c] >= '0' && str[c] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (-1 * ('0' - str[c]));
		c++;
	}
	if (n == 1)
		return (-nbr);
	else
		return (nbr);
}
