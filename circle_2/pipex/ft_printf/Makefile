# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:29:36 by dhuss             #+#    #+#              #
#    Updated: 2024/04/23 09:16:11 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CFILES = ft_putnbr_base.c\
	ft_putnbr_unsigned.c\
	ft_printf.c\
	ft_putnbr_base_lowercase.c\
	ft_putstr.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putptr.c\

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):	$(OFILES) ./ft_printf.h
	ar rsc $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
