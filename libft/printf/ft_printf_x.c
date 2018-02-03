/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:07:42 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:58:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


static char* ft_xstr(int p)
{
	unsigned long adr;
	char const *base;
	char *res;
	int i;

	adr = (unsigned long) p;
	i = 0;
	while (p > 9)
	{
		p /= 10;
		i++;
	}
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
	return (res);
}

static char* ft_xstrl(long p)
{
	unsigned long adr;
	char const *base;
	char *res;
	int i;

	adr = (unsigned long) p;
	i = 0;
	while (p > 9)
	{
		p /= 10;
		i++;
	}
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

static char* ft_xstrll(long long p)
{
	unsigned long adr;
	char const *base;
	char *res;
	int i;

	adr = (unsigned long) p;
	i = 0;
	while (p > 9)
	{
		p /= 10;
		i++;
	}
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

static char* ft_xstrh(short p)
{
	unsigned long adr;
	char const *base;
	char *res;
	int i;

	adr = (unsigned long) p;
	i = 0;
	while (p > 9)
	{
		p /= 10;
		i++;
	}
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
void ft_x_main(t_struct *para, va_list args)
{
	char *x;

	para->flags_one == '\0' ? x = ft_xstr(va_arg(args, int)) : 0;
	if (para->flags_one == 'l')
	{
		para->flags_two == '\0' ? x = ft_xstrl(va_arg(args, long)) : 0;
		para->flags_two == 'l' ? x = ft_xstrll(va_arg(args, long long)) : 0;
	}
	if (para->flags_one == 'h')
	{
		para->flags_two == '\0' ? x = ft_xstrh((short)va_arg(args, int)) : 0;
		para->flags_two == 'h' ? x = ft_xstrhh((char)va_arg(args, int)) : 0;
	}
	para->flags_one == 'j' ? x = ft_xstrll(va_arg(args, long long)) : 0;
	para->flags_one == 'z' ? x = ft_xstrl(va_arg(args, long)) : 0;
	ft_d(para, x);
}
