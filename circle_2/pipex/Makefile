# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 08:29:21 by dhuss             #+#    #+#              #
#    Updated: 2024/07/19 09:53:13 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
NAME = pipex
CFLAGS = -Wall -Werror -Wextra -g
CFILES = pipex.c get_path.c errors.c helper_and_free.c check_file.c

OFILES = $(CFILES:.c=.o)

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INCLUDES = -I $(FT_PRINTF_DIR)

INCLUDES = $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR) all

$(NAME): $(OFILES) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re