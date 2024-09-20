# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 16:03:27 by dhuss             #+#    #+#              #
#    Updated: 2024/06/24 14:51:35 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g -I . -I operations
CFILES = push_swap.c error_check.c error_check_2.c clear.c small_sort.c big_sort.c determine.c cost_calculation.c\
	algorithm.c helpers.c \
	operations/push.c operations/reverse_rotate.c\
	operations/rotate.c operations/swap.c
OBJ_DIR = Ofiles
OFILES = $(addprefix $(OBJ_DIR)/,$(notdir $(CFILES:.c=.o)))

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INCLUDES = -I $(FT_PRINTF_DIR)

all: $(LIBFT) $(FT_PRINTF) $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR) all

$(NAME): $(OFILES) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(FT_PRINTF) -o $(NAME) $(LIBFT_INCLUDES)

$(OBJ_DIR)/%.o: operations/%.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o rmdir $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re