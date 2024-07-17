/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:42 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 20:03:48 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(t_game *game, int x, int y, char to_fill)
{
	if (y < 0 || y >= game->map->col_y || x < 0 || x >= game->map->row_x
		|| game->map->copy_map[y][x] == to_fill
		|| game->map->copy_map[y][x] == '1'
		|| game->map->copy_map[y][x] == 'E')
		return ;
	game->map->copy_map[y][x] = 'F';
	fill(game, x + 1, y, to_fill);
	fill(game, x - 1, y, to_fill);
	fill(game, x, y + 1, to_fill);
	fill(game, x, y - 1, to_fill);
}

void	flood_fill(t_game *game, int begin_x, int begin_y)
{
	fill(game, begin_x, begin_y, 'F');
}

void	loc_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->map->col_y - 1)
	{
		j = 0;
		while (++j < game->map->row_x - 1)
		{
			if (game->map->all_map[i][j] == 'P')
			{
				game->loc_px = j;
				game->loc_py = i;
			}
		}
	}
}

void	is_reachable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P')
				ft_error("Error\nNon reachable characters detected!");
			j++;
		}
		i++;
	}
}

void	loc_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->map->col_y - 1)
	{
		j = 0;
		while (++j < game->map->row_x - 1)
		{
			if (game->map->all_map[i][j] == 'E')
			{
				game->loc_exit_x = j;
				game->loc_exit_y = i;
			}
		}
	}
}
