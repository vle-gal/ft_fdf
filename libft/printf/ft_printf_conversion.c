/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:25:24 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:57:22 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_putaddr(void* p)
{
	unsigned long adr;
	char const *base;
	char res[9];
	int i;

printf("daw\n");
	adr = (unsigned long) p;
	base = "0123456789abcdef";
	i = 10;
	while ((adr / 16) > 0 || i >= 10)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putchar ('0');
	ft_putchar ('x');
	while (i < 11)
	{
		ft_putchar (res[i]);
		i++;
	}
}

void ft_puthex(unsigned int p)
{
	unsigned long adr;
	char const *base;
	char res[9];
	int i;

printf("daw\n");
	adr = (unsigned long) p;
	base = "0123456789abcdef";
	i = 10;
	while ((adr / 16) > 0 || i >= 10)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	while (i < 11)
	{
		ft_putchar (res[i]);
		i++;
	}
}

void ft_putoctal(unsigned int p)
{
	unsigned long adr;
	char const *base;
	char res[9];
	int i;

printf("daw\n");
	adr = (unsigned long) p;
	base = "01234567";
	i = 10;
	while ((adr / 8) > 0 || i >= 10)
	{
		res[i] = base[(adr % 8)];
		adr /= 8;
		i--;
	}
	res[i] = base[(adr % 8)];
	while (i < 11)
	{
		ft_putchar (res[i]);
		i++;
	}
}
