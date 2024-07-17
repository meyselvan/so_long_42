/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:43:05 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 20:03:12 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFile can't open!");
	return (fd);
}

int	map_line_count(char *path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open_file_control(path);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nEmpty map!");
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	reachable_exit(t_game *game)
{
	loc_exit(game);
	if (game->map->copy_map[game->loc_exit_y][game->loc_exit_x - 1] == 'F')
		return ;
	else if (game->map->copy_map[game->loc_exit_y][game->loc_exit_x + 1] == 'F')
		return ;
	else if (game->map->copy_map[game->loc_exit_y - 1][game->loc_exit_x] == 'F')
		return ;
	else if (game->map->copy_map[game->loc_exit_y + 1][game->loc_exit_x] == 'F')
		return ;
	else
		ft_error("Error\nNon-reachable exit!");
}
