/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boarders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:02:56 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:12:08 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	top_and_bottom(char **map, t_point size)
{
	size_t	x;

	x = 0;
	while (map[0][x] != '\0')
	{
		if (map[0][x] != '1')
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Map is not enclosed by Walls!\n", 1);
			free_double_exit(map);
		}
		x++;
	}
	x = 0;
	while (map[size.y - 1][x] != '\0')
	{
		if (map[size.y - 1][x] != '1')
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Map is not enclosed by Walls!\n", 1);
			free_double_exit(map);
		}
		x++;
	}
}

static void	sides(char **map, t_point size)
{
	size_t	y;

	y = 0;
	while (map[y] != NULL)
	{
		if ((map[y][0] != '1') || (map[y][size.x - 2] != '1'))
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Map is not enclosed by Walls!\n", 1);
			free_double_exit(map);
		}
		y++;
	}
}

void	check_boarders(char **map, t_point size)
{
	top_and_bottom(map, size);
	sides(map, size);
}

void	check_paths(t_game_state *game)
{
	char	**map_dup;

	map_dup = copy_map(game->map, game->size);
	flood_fill(map_dup, game);
	other_than_one(map_dup, game->map);
	free_double_array(map_dup);
}
