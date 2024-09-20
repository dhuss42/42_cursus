/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:31:06 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:11:48 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char_2(char c, const char *valid_chars)
{
	while (*valid_chars)
	{
		if (c == *valid_chars)
			return (1);
		valid_chars++;
	}
	return (0);
}

void	locate_positions(t_game_state *game)
{
	size_t		i;
	char		*pos;

	i = 0;
	while (game->map[i] != NULL)
	{
		pos = ft_strchr(game->map[i], 'P');
		if (pos != NULL)
		{
			game->player.x = pos - game->map[i];
			game->player.y = i;
		}
		pos = ft_strchr(game->map[i], 'E');
		if (pos != NULL)
		{
			game->exit.x = pos - game->map[i];
			game->exit.y = i;
		}
		i++;
	}
}

void	check_rectangle_(t_game_state	*game)
{
	int	i;

	i = 1;
	while (i < game->size.y)
	{
		if (game->x_len[i] != game->x_len[i - 1])
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Not a rectangle!\n", 1);
			free(game->x_len);
			free_double_exit(game->map);
		}
		i++;
	}
	free(game->x_len);
}

void	check_if_empty(t_game_state *game)
{
	if (!game->map || !game->map[0])
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("First row of the map is NULL\n", 1);
		if (game->map)
		{
			free(game->x_len);
			free_double_exit(game->map);
		}
	}
	else if (game->map[0][0] == '\0')
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("First row is an empty string\n", 1);
		free(game->x_len);
		free_double_exit(game->map);
	}
}

void	check_valid_chars(char **map)
{
	size_t	y;
	size_t	x;
	size_t	len;

	y = 0;
	len = ft_strlen(map[0]);
	while (map[y] != NULL)
	{
		x = 0;
		while (x < len)
		{
			if (!is_valid_char_2(map[y][x], "01PCE"))
			{
				ft_putstr_fd("Error\n", 1);
				ft_putstr_fd("Map contains invalid characters!\n", 1);
				free_double_exit(map);
			}
			x++;
		}
		y++;
	}
}
