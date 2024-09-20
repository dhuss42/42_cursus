/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:04:13 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:11:51 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_nbr_player(char **map)
{
	size_t	i;
	size_t	counter;
	char	*pos;

	i = 0;
	counter = 0;
	while (map[i] != NULL)
	{
		pos = map[i];
		while (1)
		{
			pos = ft_strchr(pos, 'P');
			if (pos == NULL)
				break ;
			counter++;
			pos++;
		}
		i++;
	}
	if (counter != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Incorrect number of Players\n", 1);
		free_double_exit(map);
	}
}

static void	check_nbr_exit(char **map)
{
	size_t	i;
	size_t	counter;
	char	*pos;

	i = 0;
	counter = 0;
	while (map[i] != NULL)
	{
		pos = map[i];
		while (1)
		{
			pos = ft_strchr(pos, 'E');
			if (pos == NULL)
				break ;
			counter++;
			pos++;
		}
		i++;
	}
	if (counter != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Incorrect number of Exits\n", 1);
		free_double_exit(map);
	}
}

static void	check_nbr_collectables(t_game_state *game)
{
	size_t	i;
	char	*pos;

	i = 0;
	game->collectables = 0;
	while (game->map[i] != NULL)
	{
		pos = game->map[i];
		while (1)
		{
			pos = ft_strchr(pos, 'C');
			if (pos == NULL)
				break ;
			game->collectables++;
			pos++;
		}
		i++;
	}
	if (game->collectables < 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Less than one collectable\n", 1);
		free_double_exit(game->map);
	}
}

void	check_nbr_of(t_game_state *game)
{
	check_nbr_player(game->map);
	check_nbr_exit(game->map);
	check_nbr_collectables(game);
}
