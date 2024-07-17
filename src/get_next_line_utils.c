/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:12 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 18:42:12 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	if (!str)
		return (0);
	while (*end)
		end++;
	return (end - str);
}

int	ft_chrcmp(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *tmp, char *buff)
{
	char	*new_temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_temp = (char *)malloc(ft_strlen(tmp) + ft_strlen(buff) + 1);
	if (!new_temp)
		return (NULL);
	if (tmp)
	{
		while (tmp[i])
		{
			new_temp[i] = tmp[i];
			i++;
		}
	}
	while (buff[j])
		new_temp[i++] = buff[j++];
	new_temp[i] = 0;
	free(tmp);
	return (new_temp);
}
