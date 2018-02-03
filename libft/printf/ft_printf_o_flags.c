/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:38:38 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:58:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char* ft_ostrhh(char p)
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
	res = ft_strnew(i + 1);
	base = "01234567";
	while ((adr / 8) > 0 || i > 1)
	{
		res[i] = base[(adr % 8)];
		adr /= 8;
		i--;
	}
	res[0] = base[(adr % 8)];
	return (res);
}
