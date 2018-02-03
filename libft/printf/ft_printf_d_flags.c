/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:35:02 by anonymou          #+#    #+#             */
/*   Updated: 2017/11/07 15:06:43 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char* ft_dstrl(long d)
{
	char* dstr;
	int len;
	int len_n;
	int less;

	less = 0;
	d < 0 ? less = 1 && (d = d * -1) : 0;
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	less == 1 ? len++ : 0;
	len_n = d;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	less == 1 ? len-- : 0;
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
char* ft_dstrh(short d)
{
	char* dstr;
	int len;
	int len_n;
	int less;

	less = 0;
	d < 0 ? less = 1 && (d = d * -1) : 0;
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	less == 1 ? len++ : 0;
	len_n = d;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	less == 1 ? len-- : 0;
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

char* ft_dstrll(long long d)
{
	char* dstr;
	int len;
	int len_n;
	int less;

	less = 0;
	d < 0 ? less = 1 && (d = d * -1) : 0;
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	less == 1 ? len++ : 0;
	len_n = d;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	less == 1 ? len-- : 0;
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

char* ft_dstrhh(char d)
{
	char* dstr;
	int len;
	int len_n;
	int less;

	less = 0;
	d < 0 ? less = 1 && (d = d * -1) : 0;
	// d < 0 ? d = d * -1 : 0;
	len = 0;
	less == 1 ? len++ : 0;
	len_n = d;
	while (len_n > 9)
	{
		len_n /= 10;
		len++;
	}
	dstr = ft_strnew((size_t)len);
	less == 1 ? len-- : 0;
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



// char* ft_dstrj(wint_t d)
// {
// 	char* dstr;
// 	int len;
// 	int len_n;
// 	int less;
//
// 	d < 0 ? less = 1 : 0;
// 	d < 0 ? d = d * -1 : 0;
// 	len = 0;
// 	less == 1 ? len++ : 0;
// 	len_n = d;
// 	while (len_n > 9)
// 	{
// 		len_n /= 10;
// 		len++;
// 	}
// 	dstr = ft_strnew((size_t)len);
// 	less == 1 ? len-- : 0;
// 	while (len > 0)
// 	{
// 		less == 1 ? dstr[len + 1] = (d % 10) + '0': (dstr[len] = (d % 10) + '0');
// 		d /= 10;
// 		len--;
// 	}
// 	less == 1 ? dstr [len + 1] = d + '0' : (dstr[len] = d + '0');
// 	less == 1 ? dstr [len] = '-' : 0;
// 	return  (dstr);
// }
