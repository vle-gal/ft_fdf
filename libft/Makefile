# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/16 23:06:16 by vle-gal           #+#    #+#              #
#    Updated: 2018/02/03 11:44:49 by vle-gal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a #Makefile simple
#les Path finding

vpath %.c basic ft_mem ft_put ft_str
vpath_h = -Idoth

#les couleurs et autre

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

#les pré-règles

OBJDIR := objdiro
OBJS := $(addprefix $(OBJDIR)/,ft_get_next_line.o ft_isdigit.o  ft_memmove.o  ft_strcmp.o \
ft_strlen.o ft_strequ.o ft_isprint.o ft_memset.o ft_strcpy.o ft_strmap.o \
ft_strrchr.o ft_memalloc.o ft_putchar.o ft_strdel.o ft_strncat.o ft_strsplit.o \
ft_atoi.o ft_memccpy.o ft_putnbr.o ft_strdup.o ft_strncmp.o ft_strstr.o \
ft_bzero.o ft_memchr.o ft_putstr.o ft_striter.o ft_strncpy.o ft_strsub.o \
ft_isalnum.o ft_memcmp.o ft_strcat.o ft_striteri.o ft_strnew.o ft_strtrim.o \
ft_isalpha.o ft_memcpy.o ft_strchr.o ft_strjoin.o  ft_strnequ.o ft_tolower.o \
ft_isascii.o ft_memdel.o ft_strclr.o ft_strlcat.o ft_strnstr.o ft_toupper.o \
ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
ft_strmapi.o ft_itoa.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o \
ft_lstiter.o ft_lstmap.o ft_swap.o ft_iterative_power.o \
ft_iterative_factorial.o ft_is_negative.o ft_div_mod.o)
$(OBJDIR)/%.o : %.c
	@echo ${Y}Compiling [$@]...${X}
	@gcc $(CPPFLAGS) $(CFLAGS) $(vpath_h) -Wall -Wextra -Werror -c \
	$(OUTPUT_OPTION) $<
	@printf ${UP}${CUT}

#les règles

all: $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo ${Y}Success"  "[${NAME}]${X}
	@echo $(R)Oh, God. Never underestimate the power of stupid things \
	in large numbers!
$(OBJS): | $(OBJDIR)
$(OBJDIR):
	@mkdir $(OBJDIR)

#les outils

clean :
	@rm -rf $(OBJDIR)
	@echo $(R)Die when I kill you!
fclean : clean
	@rm libft.a
re : fclean
	@make
