# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larlyne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 13:38:08 by larlyne           #+#    #+#              #
#    Updated: 2019/06/15 10:38:00 by larlyne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_memset.c \
	 ft_bzero.c \
	 ft_memcpy.c \
	 ft_memmove.c \
	 ft_strlen.c \
	 ft_strcmp.c \
	 ft_atoi.c \
	 ft_memalloc.c \
	 ft_memdel.c \
	 ft_strnew.c \
	 ft_strsplit.c \
	 ft_putchar.c \
	 ft_putstr.c \
	 ft_putnbr.c \
	 ft_putchar_fd.c \
	 ft_putstr_fd.c \
	 ft_putnbr_fd.c \
	 ft_realloc.c \
	 ft_putstrn.c \
	 ft_putstrn_fd.c \
	 ft_putcharn_fd.c \
	 ft_isint.c \
	 ft_itoa.c \
\
	 ft_lstr_new_empty.c \
	 ft_lstr_new.c \
	 ft_lstr_new_raw.c \
	 ft_lstr_new_copy.c \
	 ft_lstr_insert_c.c \
	 ft_lstr_insert_s.c \
	 ft_lstr_insert_sn.c \
	 ft_lstr_put_fd.c \
	 ft_lstr_put.c \
	 ft_lstr_destroy.c \
	 ft_lstr_resize.c \
	 ft_lstr_minimize.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -I . -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

makeitclear: all clean
