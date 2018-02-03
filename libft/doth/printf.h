#ifndef PRINTF_H
# define PRINTF_H
#	include "libft.h"
# include <string.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>
#	include <fcntl.h>
#	include <stdarg.h>
#	include <wchar.h>
#	include <stdint.h>
// # include <stddef.h>

typedef struct		s_struct
{
	int i;
	int nbr;
	char chara;
	int flag;
	int first;
	char second;
	char third;
	int fourth;
	char flags_one;
	char flags_two;
	char *s1;
	va_list *args;
}									t_struct;

int   ft_printf(const char* format, ...);
void  ft_putaddr(void* p);
void  ft_puthex(unsigned int p);
void  ft_putoctal(unsigned int p);
void  ft_putoctal_long(unsigned long p);
void  ft_puthex_long(unsigned long p);
void  ft_s_main(t_struct * para, va_list args);
void  ft_putstr_ls(t_struct * para, wchar_t * s);
char* ft_flags_dot(char* s, size_t len, t_struct * para);
char* ft_flags_dot_int(char* s, size_t len, t_struct * para);
char* ft_flags_height(char* s, size_t len, t_struct * para);
char* ft_flags_less(char* s, size_t len, size_t len_less, t_struct * para);
void  ft_p_main(t_struct *para, va_list args);
void  ft_d_main(t_struct *para, va_list args);
char* ft_dstrl(long d);
char* ft_dstrll(long long d);
char* ft_dstrh(short d);
char* ft_dstrhh(char d);
void  ft_d(t_struct * para, char* d);
void  ft_u_main(t_struct * para, va_list args);
char* ft_ustrhh(char d);
char* ft_ustrz(size_t d);
void ft_o_main(t_struct *para, va_list args);
void ft_x_main(t_struct *para, va_list args);
void ft_c_main(t_struct *para, va_list args);
char* ft_xstrhh(char p);
char* ft_ostrhh(char p);
int ft_parseur_flag(t_struct * para, const char* format);
int ft_parseur_c(t_struct * para);
#endif
