/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:43:10 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 18:43:10 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_init(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	game->map->collec_count = 0;
	game->map->exit_count = 0;
	game->map->player_count = 0;
	game->step = 0;
}

void	map_valid(t_game *game)
{
	flood_fill(game, game->loc_px, game->loc_py);
	is_reachable(game->map->copy_map);
	reachable_exit(game);
}

void	total_check(t_game *game, char *path)
{
	read_map(path, game->map);
	component_check(game->map);
	is_line_equal(game->map);
	wall_check(game->map);
	min_component(game->map);
	copy_map(game->map, path);
	open_xpm();
	loc_player(game);
	map_valid(game);
	game->mlx = mlx_init();
	image_paths(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		ft_error("Error\nThe number of arguments is less than required!");
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error\nMalloc doesn't work!");
	if (argc == 2)
	{
		map_name(argv[1]);
		game_init(game);
		total_check(game, argv[1]);
		if (game->map->col_y > 22)
			ft_error("Error\nThis map so big!");
		game->win = mlx_new_window(game->mlx, game->map->row_x * 64,
				game->map->col_y * 64, "so_long");
		ft_place(game);
		mlx_key_hook(game->win, key_hook, game);
		mlx_hook(game->win, 17, 0L, finish_game, game);
		mlx_loop(game->mlx);
	}
	else
		ft_error("Error\nThe number of arguments is more than necessary!");
	return (0);
}
