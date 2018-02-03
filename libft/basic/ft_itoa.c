/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 04:57:49 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/27 21:58:53 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 1)
		return (0);
	if (power > 1)
		return (nb * ft_recursive_power(nb, power - 1));
	return (nb);
}

static	char	*ft_reverse(char *str, int n, int i, int len)
{
	if (n == -2147483648)
	{
		str[i] = '-';
		str[i + 1] = '2';
		n = 147483648;
		i = i + 2;
		len--;
		ft_reverse(str, n, i, len);
	}
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
	if (n == 0)
		str[i] = '0';
	while (len)
	{
		str[i] = (n / ft_recursive_power(10, len - 1) + '0');
		n = n % ft_recursive_power(10, len - 1);
		i++;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	int		x;

	x = n;
	len = 0;
	while (x != 0)
	{
		x = x / 10;
		len++;
	}
	i = 0;
	if (!(str = (char*)ft_strnew(12)))
		return (0);
	ft_bzero(str, ((size_t)len));
	str = ft_reverse(str, n, i, len);
	return (str);
}
