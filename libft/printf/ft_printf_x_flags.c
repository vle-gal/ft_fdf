/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:12:30 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:58:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char* ft_xstrhh(char p)
{
	unsigned long adr;
	char const *base;
	char *res;
	int i;

	adr = (unsigned char) p;
	i = 0;
	while (adr > 9)
	{
		adr /= 10;
		i++;
	}
	adr = (unsigned char) p;
	i--;
	res = ft_strnew(i + 1);
	base = "0123456789abcdef";
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	// printf("\n%s\n", res);
	return (res);
}
