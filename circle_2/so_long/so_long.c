/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:50:13 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:11:47 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(t_game_state *game)
{
	check_if_empty(game);
	check_rectangle_(game);
	check_valid_chars(game->map);
	check_nbr_of(game);
	check_boarders(game->map, game->size);
	locate_positions(game);
	check_paths(game);
}

void	so_long(char *map_name)
{
	t_game_state	game;

	get_x_y(map_name, &game.size);
	game.map = make_area(&game, map_name);
	parsing(&game);
	game_loop(&game);
	free_double_array(game.map);
}

void	check_input(int argc, char *argv[])
{
	size_t	len;
	char	*file_name;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Wrong number of arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	file_name = ft_strrchr(argv[1], '/');
	if (!file_name)
		file_name = argv[1];
	else
		file_name++;
	len = ft_strlen(file_name);
	if (len <= 4 || ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Bad extenstion\n", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	check_input(argc, argv);
	so_long(argv[1]);
	return (0);
}
