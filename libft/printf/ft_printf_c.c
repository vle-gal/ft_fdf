/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:20:45 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:57:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char* ft_cstr(char c)
{
	char *new_c;

	new_c = ft_strnew(2);
	new_c[0] = c;
	return (new_c);
}

int ft_parseur_c(t_struct * para)
{
	if (para->second == '0')
	{
		ft_putstr("warning: '0' flag used with % format");
		return (1);
	}
	if (para->third == '+')
	{
		ft_putstr("warning: '+' flag used with % format");
		return (1);
	}
	if (para->third == ' ')
	{
		ft_putstr("warning: ' ' flag used with % format");
		return (1);
	}
	if (para->flags_two != '\0' || (para->flags_one != 'l' &&
	para->flags_one != '\0'))
	{
		ft_putstr("warning: flags lenght modifier with % format");
		return (1);
	}
	return (0);
}

void ft_c_main(t_struct *para, va_list args)
{
	char *c;

	if (para->fourth != -1 )
	{
		ft_putstr("warning: precision flags used with % format");
		exit (0);
	}
	if (ft_parseur_c(para) == 1)
		exit (0);
	c = ft_cstr((char)va_arg(args, int));
	ft_d(para, c);
}
