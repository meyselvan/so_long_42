/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:43:01 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 21:34:36 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_won_game(t_game *game, int x, int y)
{
	if (game->map->collec_count == 0 && game->map->all_map[y][x] == 'E')
	{
		ft_printf("step : %d\nYOU WON!\n", game->step + 1);
		finish_game(game);
	}
}

void	change_player(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->img.player = game->img.left;
	else if (keycode == KEY_D)
		game->img.player = game->img.right;
	else if (keycode == KEY_S)
		game->img.player = game->img.front;
	else if (keycode == KEY_W)
		game->img.player = game->img.back;
}

void	play(t_game *game, int x, int y)
{
	is_won_game(game, x, y);
	if (game->map->all_map[y][x] == '0'
		|| game->map->all_map[y][x] == 'C')
	{
		game->step++;
		ft_printf("step : %d\n", game->step);
		if (game->map->all_map[y][x] == 'C')
			game->map->collec_count--;
		game->map->all_map[game->loc_py][game->loc_px] = '0';
		game->map->all_map[y][x] = 'P';
		game->loc_px = x;
		game->loc_py = y;
	}
}

int	key_hook(int keycode, t_game *game)
{
	change_player(keycode, game);
	if (keycode == KEY_ESC)
		finish_game(game);
	else if (keycode == KEY_A)
		play(game, game->loc_px - 1, game->loc_py);
	else if (keycode == KEY_S)
		play(game, game->loc_px, game->loc_py + 1);
	else if (keycode == KEY_D)
		play(game, game->loc_px + 1, game->loc_py);
	else if (keycode == KEY_W)
		play(game, game->loc_px, game->loc_py - 1);
	mlx_clear_window(game->mlx, game->win);
	ft_place(game);
	return (keycode);
}
