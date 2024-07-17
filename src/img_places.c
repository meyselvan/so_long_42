/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_places.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:37 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 21:30:02 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fd_xpm(char *path_xpm)
{
	int	fd;

	fd = open(path_xpm, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_error("Error\n.xpm file can't open!");
	}
	close(fd);
}

void	open_xpm(void)
{
	fd_xpm(COIN_P);
	fd_xpm(WALL_P);
	fd_xpm(FLOOR_P);
	fd_xpm(EXIT_P);
	fd_xpm(LEFT_P);
	fd_xpm(RIGHT_P);
	fd_xpm(BACK_P);
	fd_xpm(FRONT_P);
}

void	image_paths(t_game *game)
{
	int	w;
	int	h;

	game->img.coin = mlx_xpm_file_to_image(game->mlx, COIN_P, &w, &h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR_P, &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT_P, &w, &h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL_P, &w, &h);
	game->img.front = mlx_xpm_file_to_image(game->mlx, FRONT_P, &w, &h);
	game->img.back = mlx_xpm_file_to_image(game->mlx, BACK_P, &w, &h);
	game->img.right = mlx_xpm_file_to_image(game->mlx, RIGHT_P, &w, &h);
	game->img.left = mlx_xpm_file_to_image(game->mlx, LEFT_P, &w, &h);
	game->img.player = game->img.front;
}

void	put_place(t_game *game, char ch, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, x, y);
	if (ch == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.coin, x, y);
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
	else if (ch == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x, y);
	else if (ch == 'P')
	{
		loc_player(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x, y);
	}
}

void	ft_place(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < game->map->col_y)
	{
		i = -1;
		while (++i < game->map->row_x)
		{
			put_place(game, game->map->all_map[j][i], i * 64, j * 64);
		}
	}
}
