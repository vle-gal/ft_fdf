/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:14:26 by anonymou          #+#    #+#             */
/*   Updated: 2017/09/19 17:58:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"printf.h"

static int ft_flag_bis(const char* format,  t_struct * para)
{
			int a;

			a = 0;
			if (format[para->i] != '.')
				a = format[para->i] - '0';
			para->i++;
			while (format[para->i] <= '9' && format[para->i] >= '0')
			{
				a = a * 10;
				a = a + format[para->i] - '0';
				para->i++;
			}
			para->i--;
			// printf("%c", format[para->i]);
			return (a);
}

static void ft_flags(const char* format, t_struct *para)
{
	para->fourth = -1;
	while((format[para->i] <= '9' && format[para->i] > '0') ||
				format[para->i] == '-' || format[para->i] == '0' ||
				format[para->i] == ' ' || format[para->i] == '+' ||
				format[para->i] == '.' || format[para->i] == 'l' ||
				format[para->i] == 'h' || format[para->i] == 'j' ||
				format[para->i] == 'z')
	{
		ft_parseur_flag(para, format) == 1 ? ft_putstr("error general flags") : 0;
		ft_parseur_flag(para, format) == 1 ?  exit (0) : 0;
		if (format[para->i] == '-' || format[para->i] == '0')
			para->second = format[para->i];
		if (format[para->i] <= '9' && format[para->i] > '0')
			para->first = ft_flag_bis(format, para);
		if (format[para->i] == ' ' || format[para->i] == '+')
			para->third = format[para->i];
		format[para->i] == '.' ? para->fourth = ft_flag_bis(format, para) : 0;
		if (format[para->i] == 'l' || format[para->i] == 'h' ||
				format[para->i] == 'j' || format[para->i] == 'z')
				{
					(para->flags_one == '\0') ? para->flags_one = format[para->i] :
					(para->flags_two = format[para->i]);
				}
		para->i++;
	}
}

static int ft_format(const char* format, t_struct *para)
{
	while ((format[para->i] && format[para->i] != '%') ||
	(format[para->i] == '%' && format[para->i + 1] == '%'))
		{
	if (format[para->i] == '%' && format[para->i + 1] == '%')
		{
			ft_putchar('%');
			para->i = para->i + 2;
		}
			ft_putchar(format[para->i]);
			para->i++;
		}
		if (format[para->i] == '%')
			{
				para->i++;
				// printf("ici\n");
				ft_flags(format, para);
				// printf("%d\n", para->i);
				return (1);
			}
	return (0);
}

static void ft_para(const char* format, t_struct *para, va_list args)
{
	// printf("%c%c", para->flags_one, format[para->i]);
	// printf("%c%c/%d,%ls", format[para->i], para->flags_one, para->first, va_arg(args, wchar_t*));
	para->chara = format[para->i];
		format[para->i] == 's' || format[para->i] == 'S'? ft_s_main(para, args) : 0;
		format[para->i] == 'p' || format[para->i] == 'P'? ft_p_main(para, args) : 0;
		format[para->i] == 'd' || format[para->i] == 'D'? ft_d_main(para, args) : 0;
		format[para->i] == 'i' || format[para->i] == 'I'? ft_s_main(para, args) : 0;
		format[para->i] == 'o' || format[para->i] == 'O'? ft_o_main(para, args) : 0;
		format[para->i] == 'u' || format[para->i] == 'U'? ft_u_main(para, args) : 0;
		format[para->i] == 'x' || format[para->i] == 'X'? ft_x_main(para, args) : 0;
		format[para->i] == 'c' || format[para->i] == 'C'? ft_c_main(para, args) : 0;



		// format[para->i + para->len] == 'd' ||format[para->i + para->len] == 'i'?
		// ft_putnbr(va_arg(args, int)) : 0;
		// format[para->i + para->len] == 'o'?
		// ft_putoctal(va_arg(args, unsigned int)) : 0;
		// format[para->i + para->len] == 'O'?
		// ft_putoctal_long((unsigned long)va_arg(args, wint_t)) : 0;
		// format[para->i + para->len] == 'u'?
		// ft_putnbr_unsigned(va_arg(args, unsigned int)) : 0;
		// format[para->i + para->len] == 'U'?
		// ft_putnbr_unsigned_long((unsigned long)va_arg(args, wint_t)) : 0;
		// format[para->i + para->len] == 'x'?
		// ft_puthex(va_arg(args, unsigned int)) : 0;
		// format[para->i + para->len] == 'X'?
		// ft_puthex_long((unsigned long)va_arg(args, wint_t)) : 0;
		// format[para->i + para->len] == 'D'?
		// ft_putnbr_long(va_arg(args, wint_t)) : 0;
		// format[para->i + para->len] == 'c'?
		// ft_putchar((unsigned char)va_arg(args, unsigned int)) : 0;
		// format[para->i + para->len] == 'C'?
		// ft_putchar((char)va_arg(args, wint_t)) : 0;
}

int	ft_printf(const char* format, ...)
{
	t_struct *para;

	para = NULL;
	if (!(para = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	va_list args;
	va_start(args, format);
	// printf("test\n");
	while (ft_format(format, para))
	{
			// printf("||__%d\n", para->i);
		ft_para(format, para, args);
		para->i++;
	}
	va_end (args);
	return(0);
}
