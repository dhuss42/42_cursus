/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:35:31 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:12:03 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_moves(t_game_state *game)
{
	char	*move_count;
	int		x;

	x = 0;
	move_count = ft_itoa(game->counter);
	while (game->map[0][x] != '\0')
	{
		mlx_image_to_window(game->mlx, game->wall_img, x * 32,
			(game->size.y -1) * 32);
		x++;
	}
	mlx_put_string(game->mlx, " Moves: ", 0, (game->size.y -1) * 32);
	mlx_put_string(game->mlx, move_count, 75, (game->size.y -1) * 32);
	free(move_count);
}

static void	update_map(t_game_state *game, int old_x, int old_y)
{
	if (game->map[old_y][old_x] == 'E')
		mlx_image_to_window(game->mlx, game->exit_img, old_x * 32, old_y * 32);
	else if (game->map[old_y][old_x] == '0' || game->map[old_y][old_x] == 'P')
		mlx_image_to_window(game->mlx, game->floor_img, old_x * 32, old_y * 32);
	mlx_image_to_window(game->mlx, game->player_img,
		game->player.x * 32, game->player.y * 32);
}

static void	handle_input(t_game_state *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->counter += 1;
		ft_printf("moves: %d\n", game->counter);
	}
	if (game->map[game->player.y][game->player.x] == 'C'
		&& game->collectables > 0)
	{
		game->collectables -= 1;
		game->map[game->player.y][game->player.x] = '0';
		mlx_image_to_window(game->mlx, game->floor_img,
			game->player.x * 32, game->player.y * 32);
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectables == 0)
		mlx_close_window(game->mlx);
}

static void	my_keyhook(mlx_key_data_t key_data, void *param)
{
	int				old_x;
	int				old_y;
	t_game_state	*game;

	game = (t_game_state *)param;
	old_x = game->player.x;
	old_y = game->player.y;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_W)
			handle_input(game, old_x, old_y -1);
		else if (key_data.key == MLX_KEY_S)
			handle_input(game, old_x, old_y + 1);
		else if (key_data.key == MLX_KEY_A)
			handle_input(game, old_x -1, old_y);
		else if (key_data.key == MLX_KEY_D)
			handle_input(game, old_x +1, old_y);
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		update_map(game, old_x, old_y);
		display_moves(game);
	}
}

void	game_loop(t_game_state *game)
{
	game->counter = 0;
	mlx_set_setting(MLX_MAXIMIZED, false);
	game->mlx = mlx_init((game->size.x - 1)
			* 32, game->size.y * 32, "so_long", true);
	if (!game->mlx)
	{
		ft_putstr_fd("mlx_init failed", 2);
		free_double_exit(game->map);
	}
	load_textures(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	fill_map(game);
	display_moves(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
