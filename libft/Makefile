# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 08:58:31 by dhuss             #+#    #+#              #
#    Updated: 2024/09/10 10:33:53 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
CFILES = ft_isalnum.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_putendl.fd.c\
	ft_strchr.c\
	ft_strlcat.c\
	ft_strncmp.c\
	ft_substr.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_itoa.c\
	ft_memmove.c\
	ft_putnbr_fd.c\
	ft_strdup.c\
	ft_strlcpy.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_memchr.c\
	ft_memset.c\
	ft_putstr_fd.c\
	ft_striteri.c\
	ft_strlen.c\
	ft_strrchr.c\
	ft_toupper.c\
	ft_calloc.c\
	ft_isdigit.c\
	ft_memcmp.c\
	ft_putchar_fd.c\
	ft_split.c\
	ft_strjoin.c\
	ft_strmapi.c\
	ft_strtrim.c\

BONUS_CFILES = ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstmap_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\

OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

all:	$(NAME)

$(NAME):	$(OFILES)
	@ar rsc $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES) $(BONUS_OFILES)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OFILES)
	ar rsc $(NAME) $(BONUS_OFILES)

.PHONY: all clean fclean re bonus
