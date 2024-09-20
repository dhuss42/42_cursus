/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:00:57 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:11:45 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game_state
{
	char		**map;
	char		*valid_chars;
	size_t		*x_len;
	t_point		size;
	t_point		player;
	t_point		exit;
	int			collectables;
	int			counter;
	mlx_t		*mlx;
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*coin_img;
	mlx_image_t	*player_img;
	mlx_image_t	*enemy_img;
	mlx_image_t	*exit_img;
}	t_game_state;

//--<>--make_map--<>--//
void	get_x_y(char *map_name, t_point *size);
char	**make_area(t_game_state *game, char *map_name);

//--<>--parsing--<>--//
void	check_valid_chars(char **map);
void	check_if_empty(t_game_state *game);
void	check_rectangle_(t_game_state *game);
void	locate_positions(t_game_state *game);
void	check_boarders(char **map, t_point size);
void	check_nbr_of(t_game_state *game);
void	check_paths(t_game_state *game);

void	flood_fill(char **map, t_game_state *game);
void	other_than_one(char **map, char **map_o);
char	**copy_map(char **map, t_point size);

//--<>--texture--<>--//
void	load_textures(t_game_state *game);
void	fill_map(t_game_state *game);

//--<>--game--<>--//
void	game_loop(t_game_state *game);

//--<>--free--<>--//
void	free_double_exit(char **to_free);
void	free_double_array(char **to_free);