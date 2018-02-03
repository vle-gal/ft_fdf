/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 07:11:58 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:57:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char* ft_flags_height (char * s, size_t len, t_struct * para)
{
	int a;
	int n;
	char* new_s;

	n = 0;
	a = para->first - (int)len;
	if (a > 0)
	{
		new_s = ft_strnew((size_t)para->first);
		while (a > 0)
		{
			para->second == '0' ? new_s[n] = '0' : (new_s[n] = ' ');
			n++;
			a--;
		}
		(para->third != '\0' && para->second != '0') ? new_s[n - 1] = para->third:0;
		while (s[a])
		{
			new_s[n] = s[a];
			n++;
			a++;
		}
		para->second == '0' && para->third != '\0' ? new_s[0] = para->third : 0;
		return (new_s);
	}
	return (s);
}

char* ft_flags_less(char * s, size_t len, size_t len_less, t_struct * para)
{
	int a;
	int n;
	char* new_s;

	new_s = ft_strnew(len_less);
	n = 0;
	a = (int)len_less - (int)len;
		para->third != '\0' ? new_s[n] = para->third : 0;
	while (n < (int)len)
	{
		para->third == '\0' ? new_s[n] = s[a] : (new_s[n + 1] = s[a]);
		n++;
		a++;
	}
		para->third != '\0' ? a-- : 0;
	while (n < a)
	{
		para->third == '\0' ? new_s[n] = ' ' : (new_s[n + 1] = ' ');
		n++;
	}
	return (new_s);
}

char* ft_flags_dot(char* s, size_t len, t_struct * para)
{
	int n;
	char* new_s;

	n = 0;
	if(para->fourth > (int)len)
		return (s);
	else
		{
			new_s = ft_strnew((size_t)para->fourth);
			while (para->fourth > 0)
			{
				new_s[n] = s[n];
				n++;
				para->fourth--;
			}
			return (new_s);
		}
	return (s);
}

char* ft_flags_dot_int(char* s, size_t len, t_struct * para)
{
	char* new_s;
	int n;
	int x;

	x = 0;
	n = 0;
	if (para->fourth < (int)len)
		return (s);
	s[0] != '-' ?
	new_s = ft_strnew(para->fourth) : (new_s = ft_strnew(para->fourth + 1));
	s[0] == '-' ? new_s[0] = '-' : 0;
	s[0] == '-' ? new_s[1] = '0' : 0;
	while (n < (para->fourth - (int)len))
	{
		s[0] != '-' ? new_s[n] = '0' : (new_s[n + 2] = '0');
		n++;
	}
	while (n < para->fourth)
	{
		s[0] != '-' ? new_s[n] = s[x] : (new_s[n + 2] = s[x + 1]);
		x++;
		n++;
	}
	return (new_s);
}


int ft_parseur_flag(t_struct * para, const char* format)
{
	if ((format[para->i] == '-' || format[para->i] == '0') && para->second != 0)
		return (1);
	if ((format[para->i] <= '9' && format[para->i] > '0') && para->first != 0)
		return (1);
	if ((format[para->i] == ' ' || format[para->i] == '+') && para->third != 0)
		return (1);
	if (format[para->i] == '.' && para->fourth != -1)
		return (1);
	if ((format[para->i] == 'j' || format[para->i] == 'z') &&
	para->flags_one != 0)
		return (1);
	if ((format[para->i] == 'l' || format[para->i] == 'h') &&
	para->flags_one != 0 && para->flags_two != 0)
		return (1);
	return (0);
}
