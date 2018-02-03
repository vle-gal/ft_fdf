# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 15:16:47 by vle-gal           #+#    #+#              #
#    Updated: 2018/02/03 12:11:54 by vle-gal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = NORMAL #Makefile simple
#les Path finding
vpath %.c basic #les .c
vpath_h = -Idoth -Ilibft/doth -Iminilibx_macos #les .h
LIB = -Llibft -lft -Lminilibx_macos -lmlx
frameworks = -framework OpenGL -framework AppKit

#les couleurs et autre
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

#les pré règles
OBJDIR := objdiro
OBJS := $(addprefix $(OBJDIR)/,main.o)

$(OBJDIR)/%.o : %.c
	@gcc $(CPPFLAGS) $(CFLAGS) $(vpath_h) -Wall -Wextra -Werror -c \
	$(OUTPUT_OPTION) $<

#les règles
all: $(OBJS)
	@make -C minilibx_macos/
	@make -C libft/
	@gcc $(LIB) -o NORMAL $(OBJS)
	@echo $(R)Hail to the King Baby!
	@echo --------------$(X)
	@./NORMAL
	@echo $(R)--------------


$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

#les outils
clean :
	@rm -rf $(OBJDIR)
	@echo $(R)Hmm... so there is life after death..

fclean : clean
	@rm NORMAL

re : fclean
	@make

clib :
	@make -C libft/ clean
