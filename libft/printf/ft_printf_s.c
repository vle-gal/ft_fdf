/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:09:57 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:58:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int ft_s_warning(t_struct * para)
{
	if (para->second == '0')
	{
		ft_putstr("warning: '0' flag used with '%s' format");
		return (1);
	}
	if (para->third == '+')
	{
		ft_putstr("warning: '+' flag used with '%s' format");
		return (1);
	}
	if (para->third == ' ')
	{
		ft_putstr("warning: ' ' flag used with '%s' format");
		return (1);
	}
	if (para->flags_two != '\0' || (para->flags_one != 'l' &&
	para->flags_one != '\0'))
	{
		ft_putstr("warning: flags lenght modifier with '%s' format");
		return (1);
	}
	return (0);
}

static char* ft_switch_wchar(wchar_t* s_l)
{
	char* new_s;
	int n;
	int a;

	a = 0;
	n = 0;
	while (s_l[n])
	{
		n++;
	}
	new_s = ft_strnew(n);
	while (n > 0)
	{
		new_s[a] = (char)s_l[a];
		n--;
		a++;
	}
	return (new_s);
}

static void ft_ls(t_struct * para, wchar_t * s_l )
{
	int len;
	int len_less;
	char * s;

	s = ft_switch_wchar(s_l);
	// printf("%s", s);
	if (ft_s_warning(para) == 1)
		{
			exit (0);
		}
	len = ft_strlen(s);
	if (para->fourth != -1)
		s = ft_flags_dot(s, len, para);
	len = ft_strlen(s);
	if (para->first != '\0')
		s = ft_flags_height(s, len, para);
	len_less = ft_strlen(s);
	if (para->second != '\0')
	  s = ft_flags_less(s, len, len_less, para);
	ft_putstr(s);
	free (s);
}

static void ft_s(t_struct * para, char* s)
{
	int len;
	int len_less;

	if (ft_s_warning(para) == 1)
		{
			exit (0);
		}
	len = ft_strlen(s);
	if (para->fourth != -1)
		s = ft_flags_dot(s, len, para);
	len = ft_strlen(s);
	if (para->first != '\0')
		s = ft_flags_height(s, len, para);
	len_less = ft_strlen(s);
	printf("%d-%d", len, len_less);
	if (para->second != '\0')
	  s = ft_flags_less(s, len, len_less, para);
	printf("LEEE");
	ft_putstr(s);
	free (s);
}

void ft_s_main(t_struct * para, va_list args)
{
	if (para->flags_one == '\0' && para->chara == 's' )
		ft_s(para, va_arg(args, char *));
	else
		ft_ls(para, va_arg(args, wchar_t*));
}
