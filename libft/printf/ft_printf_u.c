/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/09/05 11:07:19 by anonymous         #+#    #+#             */
/*   updated: 2017/09/05 11:07:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
static char* ft_ustr(int d)
{
	char* dstr;
	int len;
	unsigned int len_n;
	unsigned int less;

	d < 0 ? less = 4294967295u + (d + 1) : (less = d);
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	// less == 1 ? len++ : 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	// less == 1 ? len-- : 0;
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	// less == 1 ? dstr [len] = '-' : 0;
	return  (dstr);
}

static char* ft_ustrl(long d)
{
	char* dstr;
	int len;
	unsigned long len_n;
	unsigned long less;

	d < 0 ? less = 18446744073709551615u + (d + 1) : (less = d);
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	// less == 1 ? len++ : 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	// less == 1 ? len-- : 0;
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	// less == 1 ? dstr [len] = '-' : 0;
	return  (dstr);
}

static char* ft_ustrll(long long d)
{
	char* dstr;
	int len;
	unsigned long long len_n;
	unsigned long long less;

	d < 0 ? less = 18446744073709551615u + (d + 1) : (less = d);
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	// less == 1 ? len++ : 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	// less == 1 ? len-- : 0;
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	// less == 1 ? dstr [len] = '-' : 0;
	return  (dstr);
}

static char* ft_ustrh(int d)
{
	char* dstr;
	int len;
	unsigned short len_n;
	unsigned short less;

	d < 0 ? less = 65535u + (d + 1) : (less = d);
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	// less == 1 ? len++ : 0;
	len_n = less;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	// less == 1 ? len-- : 0;
	while (len > 0)
	{
		(dstr[len] = (less % 10) + '0');
		less /= 10;
		len--;
	}
	(dstr[len] = less + '0');
	// less == 1 ? dstr [len] = '-' : 0;
	return  (dstr);
}

void ft_u_main(t_struct * para, va_list args)
{
	char* d;

	para->flags_one == '\0' ? d = ft_ustr(va_arg(args, int)) : 0;
	if (para->flags_one == 'l')
	{
		para->flags_two == '\0' ? d = ft_ustrl(va_arg(args, long)) : 0;
		para->flags_two == 'l' ? d = ft_ustrll(va_arg(args, long long)) : 0;
	}
	if (para->flags_one == 'h')
	{
		para->flags_two == '\0' ? d = ft_ustrh((short)va_arg(args, int)) : 0;
		para->flags_two == 'h' ? d = ft_ustrhh((char)va_arg(args, int)) : 0;
	}
	para->flags_one == 'j' ? d = ft_ustrll(va_arg(args, long long)) : 0;
	para->flags_one == 'z' ? d = ft_ustrl(va_arg(args, long)) : 0;
	ft_d(para, d);
}
