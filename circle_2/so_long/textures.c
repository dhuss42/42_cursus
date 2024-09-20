/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:11 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 12:53:39 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error(t_game_state *game)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("failed to load texture\n", 1);
	if (game->map)
		free_double_exit(game->map);
	exit(EXIT_FAILURE);
}

void	fill_map(t_game_state *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			mlx_image_to_window(game->mlx, game->floor_img, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall_img, x * 32, y * 32);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->coin_img, x * 32, y * 32);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->player_img,
		game->player.x * 32, game->player.y * 32);
}

static void	handle_textures(t_game_state *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = NULL;
	texture = mlx_load_png(path);
	if (!texture)
		ft_error(game);
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!(*img))
		ft_error(game);
}

void	load_textures(t_game_state *game)
{
	handle_textures(game, &game->floor_img, "./sprites/floor.png");
	handle_textures(game, &game->wall_img, "./sprites/wall.png");
	handle_textures(game, &game->coin_img, "./sprites/key.png");
	handle_textures(game, &game->exit_img, "./sprites/exit.png");
	handle_textures(game, &game->player_img, "./sprites/player.png");
}
