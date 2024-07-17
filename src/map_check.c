/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:48 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 20:03:42 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char *path, t_map *map)
{
	int		i;
	int		fd;

	i = 0;
	fd = open_file_control(path);
	map->col_y = map_line_count(path);
	map->all_map = (char **)malloc(sizeof(char *) * (map->col_y + 1));
	if (!map->all_map)
		ft_error("Error\nMalloc doesn't work!");
	while (i < map->col_y)
	{
		map->all_map[i] = get_next_line(fd);
		i++;
	}
	map->all_map[i] = 0;
	map->row_x = ft_strlen(map->all_map[0]) - 1;
	close(fd);
}

void	copy_map(t_map *map, char *path)
{
	int		i;
	int		fd;

	i = 0;
	fd = open_file_control(path);
	map->copy_map = (char **)malloc(sizeof(char *) * (map->col_y + 1));
	if (!map->copy_map)
		ft_error("Error\nMalloc doesn't work!");
	while (i < map->col_y)
	{
		map->copy_map[i] = get_next_line(fd);
		i++;
	}
	map->copy_map[i] = 0;
	close(fd);
}

void	is_line_equal(t_map *map)
{
	int	i;
	int	count;

	i = 0;
	while (map->all_map[i])
	{
		count = ft_strlen(map->all_map[i]);
		if (i == map->col_y - 1)
		{
			if (map->row_x != count)
				ft_error("Error\nInconsistent line length!");
		}
		else if (map->row_x != count - 1)
			ft_error("Error\nInconsistent line length!");
		i++;
	}
}
