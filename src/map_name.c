/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:55 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 20:03:26 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_name(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len >= 4)
	{
		if (str[len - 1] == 'r' && str[len - 2] == 'e'
			&& str[len - 3] == 'b' && str[len - 4] == '.')
			return ;
		else
			ft_error("Error\nInvalid file extension name, try again");
		i = open(str, O_RDONLY);
		if (i < 0)
			ft_error("Error\nThe specified file path is invalid or not found!");
		close(i);
	}
	else
		ft_error("Error\nInvalid file name, try again.");
}
