/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:14:09 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:58:30 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

static int ft_p_warning(t_struct * para)
{
	if (para->second == '0')
	{
		ft_putstr("warning: '0' flag used with '%p' format");
		return (1);
	}
	if (para->third == '+')
	{
		ft_putstr("warning: '+' flag used with '%p' format");
		return (1);
	}
	if (para->third == ' ')
	{
		ft_putstr("warning: ' ' flag used with '%p' format");
		return (1);
	}
	if (para->fourth != -1)
	{
		ft_putstr("warning: '.' precision flag used with '%p' format");
	}
	if (para->flags_two != '\0' || (para->flags_one != '\0'))
	{
		ft_putstr("warning: flags lenght modifier with '%p' format");
		return (1);
	}
	return (0);
}

static int ft_unsigned_longlen(unsigned long lu)
{
	int len;

	len = 1;
	while (lu > 9)
	{
		len++;
		lu /= 10;
	}
	return (len);
}

static char* ft_putaddrr(void* p)
{
	unsigned long adr;
	char const *base;
	char* res;
	int i;

	res = ft_strnew(11);
	adr = (unsigned long) p;
	base = "0123456789abcdef";
	ft_unsigned_longlen(adr) == 15 ? i = 11: (i = 5);
	while ((adr / 16) > 0 || i >= 11)
	{
		res[i + 2] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i + 2] = base[(adr % 16)];
	res[0] = ('0');
	res[1] = ('x');
	return (res);
}

void ft_p(t_struct *para, char* p)
{
	int len;
	int len_less;

	if (ft_p_warning(para) == 1)
	{
		exit (0);
	}
	len = ft_strlen(p);
	if (para->first != '\0')
		p = ft_flags_height(p, len, para);
	len_less = ft_strlen(p);
	if (para->second != '\0')
		p = ft_flags_less(p, len, len_less, para);
	ft_putstr(p);
	free (p);
}

void ft_p_main(t_struct *para, va_list args)
{
	char *p;
	if (para->flags_one != '\0' || para->flags_two != '\0')
		{
			ft_putstr("warning: flags lenght modifier with % format");
			exit (0);
		}
	if (para->fourth != -1 )
		{
			ft_putstr("warning: precision flags used with % format");
			exit (0);
		}
	if (ft_parseur_c(para) == 1)
		exit (0);
	if (para->flags_one == '\0')
	{
		p = ft_putaddrr(va_arg(args, void *));
		ft_p(para, p);
	}
}
