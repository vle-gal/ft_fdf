# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 15:16:47 by vle-gal           #+#    #+#              #
#    Updated: 2018/02/13 14:51:24 by vle-gal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf #Makefile simple
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
OBJS := $(addprefix $(OBJDIR)/,main.o octant.o octant_bis.o vert_hor.o \
									gathering_bis.o)

$(OBJDIR)/%.o : %.c
	@gcc $(CPPFLAGS) $(CFLAGS) $(vpath_h) -Wall -Wextra -Werror -g -c \
	$(OUTPUT_OPTION) $<

#les règles
all: $(OBJS)
	@make -C minilibx_macos/
	@make -C libft/
	@gcc $(LIB) $(frameworks) -o fdf $(OBJS)
	@echo $(R)Hail to the King Baby!
	@echo --------------$(X)
	# ./fdf test_maps/10-2.fdf
	# ./fdf test_maps/10-70.fdf
	# ./fdf test_maps/100-6.fdf
	# ./fdf test_maps/20-60.fdf
	# ./fdf test_maps/42.fdf
	# ./fdf test_maps/50-4.fdf
	# ./fdf test_maps/basictest.fdf
	# ./fdf test_maps/elem.fdf
	# ./fdf test_maps/mars.fdf
	# ./fdf test_maps/pentenegpos.fdf
	# ./fdf test_maps/plat.fdf
	# ./fdf test_maps/pnp_flat.fdf
	# ./fdf test_maps/pylone.fdf
	# ./fdf test_maps/pyra.fdf
	# ./fdf test_maps/pyramide.fdf

	@echo $(R)--------------


$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

#les outils
clean :
	@rm -rf $(OBJDIR)
	@echo $(R)Hmm... so there is life after death..

fclean : clean
	@rm fdf

re : fclean
	@make

clib :
	@make -C libft/ clean
