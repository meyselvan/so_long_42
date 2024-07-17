/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:56:30 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 21:46:33 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_line(t_game *game, char **map)
{
	int	i;

	i = -1;
	while (++i < game->map->col_y)
		free(map[i]);
	free(map);
}

int	finish_game(t_game *game)
{
	free_line(game, game->map->all_map);
	free_line(game, game->map->copy_map);
	exit(0);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
