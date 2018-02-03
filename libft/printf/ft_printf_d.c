/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:15:06 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/07 15:00:57 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char* ft_dstr(int d)
{
	char* dstr;
	int len;
	int len_n;
	int less;

	less = 0;
	d < 0 ? less = 1 && (d = d * -1) : 0;
	// d < 0 ? d = d * -1 : 0;
	len = 1;
	less == 1 ? len++ : 0;
	len_n = d;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	less != 1 ? len-- : 0;
	while (len > 0)
	{
		less == 1 ? dstr[len + 1] = (d % 10) + '0': (dstr[len] = (d % 10) + '0');
		d /= 10;
		len--;
	}
	less == 1 ? dstr [len + 1] = d + '0' : (dstr[len] = d + '0');
	less == 1 ? dstr [len] = '-' : 0;
	return  (dstr);
}

static char* ft_dstrz(size_t d)
{
	char* dstr;
	int len;
	int len_n;

	// d < 0 ? less = 1 : 0;
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	// less == 1 ? len++ : 0;
	len_n = d;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	// less == 1 ? len-- : 0;
	while (len > 0)
	{
		(dstr[len] = (d % 10) + '0');
		d /= 10;
		len--;
	}
	(dstr[len] = d + '0');
	// less == 1 ? dstr [len] = '-' : 0;
	return  (dstr);
}

void ft_d(t_struct * para, char* d)
{
	int len;
	int len_less;

	len = ft_strlen(d);
	d[0] == '-' ? para->third = '\0' : 0;
	if (para->fourth != -1)
		d = ft_flags_dot_int(d, len, para);
	len = ft_strlen(d);
	if (para->first != '\0')
		d = ft_flags_height(d, len, para);
	// if (para->first != '\0' && para->second == '0')
	// 	d = ft_zero(d, len, para);
	if (para->first != '\0' && para->first <= len && para->fourth == -1 &&
	para->second == '\0' && para->third != '\0')
		ft_putchar(para->third);
	len_less = ft_strlen(d);
	if (para->second == '-')
		d = ft_flags_less(d, len, len_less, para);
	if (para->third != '\0' &&
	(para->first == '\0' || para->first <= para->fourth || para->first == '0') &&
	para->second != '-' &&	(para->fourth != -1 || para->second == '0'))
		ft_putchar(para->third);
	ft_putstr(d);
	free (d);
}

void ft_d_main(t_struct * para, va_list args)
{
	char* d;

	para->flags_one == '\0' ? d = ft_dstr(va_arg(args, int)) : 0;
	if (para->flags_one == 'l')
	{
		para->flags_two == '\0' ? d = ft_dstrl(va_arg(args, long)) : 0;
		para->flags_two == 'l' ? d = ft_dstrll(va_arg(args, long long)) : 0;
	}
	if (para->flags_one == 'h')
	{
		para->flags_two == '\0' ? d = ft_dstrh((short)va_arg(args, int)) : 0;
		para->flags_two == 'h' ? d = ft_dstrhh((char)va_arg(args, int)) : 0;
	}
	para->flags_one == 'j' ? d = ft_dstrll(va_arg(args, long long)) : 0;
	para->flags_one == 'z' ? d = ft_dstrz((size_t)va_arg(args, int)) : 0;
	ft_d(para, d);
}
