# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vparis <vparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 17:37:24 by vparis            #+#    #+#              #
#    Updated: 2017/12/18 00:29:51 by vparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
CC			=	cc
SRCD		=	srcs
INCD		=	includes
LIBFTD		=	libft
MLXD		=	minilibx_macos

SRCS		=	$(SRCD)/main.c $(SRCD)/ft_mlx.c $(SRCD)/ft_pixel.c \
				$(SRCD)/ft_line.c $(SRCD)/ft_stack.c $(SRCD)/map_parse.c \
				$(SRCD)/matrix.c $(SRCD)/vertex.c $(SRCD)/env.c
OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CFLAGS		+=	-I$(INCD) -I$(LIBFTD) -I$(MLXD)

#Warnigs and debug
LDFLAGS		+=	-Wextra -Wall
LDLIBS		+=	$(LIBFTD)/libft.a $(MLXD)/libmlx.a -lm \
				-lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTD)
	make -C $(MLXD)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

clean:
	make -C $(LIBFTD) clean
	make -C $(MLXD) clean
	@rm -vf $(OBJS)

fclean: clean
	@rm -vf $(LDLIBS)
	@rm -vf $(NAME)

re: fclean all

rer:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	make $(NAME)