/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:36:45 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:12:04 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char c, const char *valid_chars)
{
	while (*valid_chars)
	{
		if (c == *valid_chars)
			return (1);
		valid_chars++;
	}
	return (0);
}

static void	fill(char **map, t_game_state *game, int x, int y)
{
	if (y < 0 || y >= game->size.y || x < 0 || x >= game->size.x
		|| !is_valid_char(map[y][x], game->valid_chars))
		return ;
	else
	{
		map[y][x] = '1';
		fill(map, game, x - 1, y);
		fill(map, game, x + 1, y);
		fill(map, game, x, y - 1);
		fill(map, game, x, y + 1);
	}
}

void	flood_fill(char **map, t_game_state *game)
{
	game->valid_chars = "P0CE";
	fill(map, game, game->player.x, game->player.y);
}

void	other_than_one(char **map, char **map_o)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((map[i][j] != '1' && map[i][j] != '0')
				|| map[i][ft_strlen(map[i])] != '\0')
			{
				ft_putstr_fd("Error\n", 1);
				ft_putstr_fd("Unreachable path!\n", 1);
				free_double_array(map_o);
				free_double_exit(map);
			}
			j++;
		}
		i++;
	}
}

char	**copy_map(char **map, t_point size)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = malloc(sizeof(char *) * (size.y + 1));
	if (!map_dup)
	{
		free(map_dup);
		free_double_exit(map);
	}
	while (i < size.y)
	{
		map_dup[i] = malloc(sizeof(char) * (size.x + 1));
		if (!map_dup[i])
		{
			free_double_array(map_dup);
			free_double_exit(map);
		}
		ft_strlcpy(map_dup[i], map[i], size.x + 1);
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}
