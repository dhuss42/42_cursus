/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:28:23 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:12:00 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_x_y(char *map_name, t_point *size)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Can't open map\n", 1);
		exit(EXIT_FAILURE);
	}
	size->y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (size->y == 0)
			size->x = ft_strlen(line);
		size->y++;
		free (line);
	}
	close (fd);
}

static size_t	*for_rectangle(t_game_state *game)
{
	size_t	*x_len;

	x_len = (size_t *)malloc(sizeof(size_t)
			* (game->size.y + 1));
	if (!x_len)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Allocation failure\n", 1);
		exit(EXIT_FAILURE);
	}
	return (x_len);
}

static size_t	ft_strlen_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

static char	**populate_map(char **area, t_game_state *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	game->x_len = for_rectangle(game);
	while (i < game->size.y)
	{
		line = get_next_line(fd);
		game->x_len[i] = ft_strlen_newline(line);
		if (!line)
			break ;
		area[i] = malloc(sizeof(char) * game->size.x);
		if (!area[i])
		{
			free(line);
			free_double_exit(area);
		}
		ft_strlcpy(area[i], line, game->size.x);
		free(line);
		i++;
	}
	area[i] = NULL;
	return (area);
}

char	**make_area(t_game_state *game, char *map_name)
{
	char	**area;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Can't open map\n", 1);
		exit(EXIT_FAILURE);
	}
	area = (char **)malloc(sizeof(char *) * (game->size.y + 1));
	if (!area)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Allocation failure\n", 1);
		exit(EXIT_FAILURE);
	}
	area = populate_map(area, game, fd);
	close (fd);
	return (area);
}
