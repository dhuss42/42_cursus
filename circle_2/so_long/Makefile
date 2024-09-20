# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 15:59:36 by dhuss             #+#    #+#              #
#    Updated: 2024/09/18 10:11:53 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
CFLAGS = -Wall -Werror -Wextra -g
CFILES = so_long.c parsing.c make_map.c flood_fill.c clear.c textures.c game.c boarders.c nbr_of.c

OBJ_DIR = Ofiles
OFILES = $(addprefix $(OBJ_DIR)/,$(notdir $(CFILES:.c=.o)))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)

REPO_URL = https://github.com/codam-coding-college/MLX42
REPO_DIR = MLX42
BUILD_DIR = $(REPO_DIR)/build
MLX42_LIB = $(BUILD_DIR)/libmlx42.a
MLX42_INCLUDES = -I $(REPO_DIR)/include

FRAMEWORKS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

COMPILE_MSG = "\033[33m Compiling $<... \033[0m"

all: $(LIBFT) mlx42 $(OBJ_DIR) $(NAME)

$(REPO_DIR):
	@echo "\033[34mCloning the MLX42 repository...\033[0m"
	@git clone $(REPO_URL)

$(BUILD_DIR): $(REPO_DIR)
	@echo "\033[34mConfiguring the MLX42 project with CMake...\033[0m"
	@cmake -B $(BUILD_DIR) -S $(REPO_DIR)

mlx42: $(BUILD_DIR)
	@echo "\033[34mBuilding the MLX42 project...\033[0m"
	@make -C $(BUILD_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OFILES) $(LIBFT) $(MLX42_LIB)
	@echo "\033[33m Linking... \033[0m"
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(MLX42_LIB) -o $(NAME) $(FRAMEWORKS)
	@echo "\033[32m Build complete \033[0m"

$(OBJ_DIR)/%.o: %.c
	@echo $(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(LIBFT_INCLUDES) $(MLX42_INCLUDES) -c $< -o $@

clean:
	@echo "\033[33m Cleaning up... \033[0m"
	@rm -rf $(OBJ_DIR)/*.o rmdir $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[33mCleaning up build files...\033[0m"
	@rm -rf $(BUILD_DIR)
	@echo "\033[33mRemoving the cloned MLX42 repository...\033[0m"
	@rm -rf $(REPO_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re mlx42