/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:42:29 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 18:42:29 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_before_line(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\n' && temp[i])
		i++;
	line = (char *)malloc(i + 2);
	i = 0;
	while (temp[i] != '\n' && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_after_line(char *temp)
{
	char	*after_line;
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	after_line = (char *)malloc(ft_strlen(temp) - i + 1);
	if (!after_line)
		return (NULL);
	j = 0;
	i++;
	while (temp[i])
		after_line[j++] = temp[i++];
	after_line[j] = 0;
	free(temp);
	return (after_line);
}

char	*add_temp(int fd, char *buffer, char *temp)
{
	int	check_read;

	check_read = 1;
	while (!ft_chrcmp(temp, '\n') && check_read != 0)
	{
		check_read = read(fd, buffer, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer[check_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp = add_temp(fd, buffer, temp);
	if (!temp)
		return (NULL);
	line = get_before_line(temp);
	temp = get_after_line(temp);
	return (line);
}
