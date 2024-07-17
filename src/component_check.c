/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:21 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 20:04:26 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row_x)
	{
		if (map->all_map[0][i] != '1'
			|| map->all_map[map->col_y - 1][i] != '1')
			ft_error("Error\nInvalid wall!");
		i++;
	}
	i = 1;
	while (i < map->col_y - 1)
	{
		if (map->all_map[i][0] != '1'
			|| map->all_map[i][map->row_x - 1] != '1')
			ft_error("Error\nInvalid wall!");
		i++;
	}
}

void	min_component(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->col_y - 1)
	{
		j = 0;
		while (++j < map->row_x - 1)
		{
			if (map->all_map[i][j] == 'E')
				map->exit_count++;
			else if (map->all_map[i][j] == 'C')
				map->collec_count++;
			else if (map->all_map[i][j] == 'P')
				map->player_count++;
		}
	}
	if (map->exit_count != 1)
		ft_error("Error\nInvalid exit count!");
	else if (map->player_count != 1)
		ft_error("Error\nInvalid player count!");
	else if (map->collec_count < 1)
		ft_error("Error\nInvalid collectable count!");
}

void	component_check(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->col_y)
	{
		i = 0;
		while (i < map->row_x)
		{
			if (!ft_strchr("1CEP0", map->all_map[j][i]))
				ft_error("Error\nThe map has the wrong type of component!");
			i++;
		}
		j++;
	}
}
