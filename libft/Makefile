# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vparis <vparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 17:37:24 by vparis            #+#    #+#              #
#    Updated: 2017/12/04 04:55:32 by vparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
LIBFT_SRCS	= ft_putchar_fd.c ft_putrevendl_fd.c \
			ft_putchar_nonprint.c ft_putendl_fd.c \
			ft_putchar.c ft_putrevendl.c \
			ft_putnbr_fd.c ft_putnbr.c \
			ft_putendl.c ft_putstr_nonprint_fd.c \
			ft_putrevstr.c ft_putstr_fd.c \
			ft_putstr_nonprint.c ft_putrevstr_fd.c \
			ft_putchar_nonprint_fd.c ft_putstr.c \
			ft_strncpy.c ft_strsub.c \
			ft_strsplit.c ft_strnequ.c \
			ft_striter.c ft_strstr.c \
			ft_strsplit_str.c ft_strmap.c \
			ft_strlen.c ft_striteri.c \
			ft_strnstr.c ft_strcat.c \
			ft_strclr.c ft_strmapi.c \
			ft_strlcat.c ft_strcat2.c \
			ft_strchr.c ft_strsplit_whitespaces.c \
			ft_strequ.c ft_strncat.c \
			ft_strrev.c ft_strdup.c \
			ft_strnew_fast.c ft_strjoin.c \
			ft_strcmp.c ft_strrchr.c \
			ft_strcpy.c \
			ft_strdel.c ft_strtrim.c \
			ft_strnew.c ft_strncmp.c \
			ft_memccpy_fast.c ft_memset.c \
			ft_memalloc_fast.c ft_memchr.c \
			ft_memmove.c ft_memccpy.c \
			ft_memcmp.c ft_memalloc.c \
			ft_memdel.c ft_memchr_fast.c \
			ft_memrealloc.c ft_memrealloc_fast.c \
			ft_memcpy.c ft_bzero.c \
			ft_sqrt.c ft_find_next_prime.c \
			ft_isprime.c ft_max3.c \
			ft_abs.c ft_min.c ft_min3.c \
			ft_fibonacci.c ft_max.c \
			ft_power.c ft_factorial.c \
			ft_atoi_base.c ft_lstdel_raw.c \
			ft_itoa.c ft_atoi.c \
			ft_toupper.c ft_islower.c \
			ft_isgraph.c ft_isupper.c \
			ft_isspace.c ft_isdigit.c \
			ft_iscntrl.c ft_ischarset.c \
			ft_isalnum.c ft_isblank.c \
			ft_isalpha.c ft_ispunct.c \
			ft_tolower.c ft_isprint.c \
			ft_isxdigit.c ft_isascii.c \
			ft_lstnew.c ft_lstdelone.c \
			ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_lstshift.c
OBJS		= $(patsubst %.c, %.o, $(LIBFT_SRCS))
LDFLAGS		+= -Wextra -Wall -Werror
CFLAGS		+=

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rs $@ $^
	ranlib $@

$(OBJS): $(LIBFT_SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
