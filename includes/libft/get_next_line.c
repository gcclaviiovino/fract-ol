/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:12:55 by liovino           #+#    #+#             */
/*   Updated: 2025/01/10 23:07:21 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buff)
{
	char	*temp;
	char	*start;

	start = ft_strchr(buff, '\n');
	if (!start || *(start + 1) == '\0')
		return (NULL);
	temp = ft_strdup(start + 1);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*find_line(int fd)
{
	int		check_read;
	char	*temp_buff;

	temp_buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	check_read = read(fd, temp_buff, BUFFER_SIZE);
	if (check_read <= 0)
	{
		free(temp_buff);
		return (NULL);
	}
	temp_buff[check_read] = '\0';
	return (temp_buff);
}

char	*fill_line(char **buffer)
{
	char	*new_start;
	char	*line;
	char	*temp;

	new_start = ft_strchr(*buffer, '\n');
	if (new_start != NULL)
	{
		line = (char *) malloc((sizeof(char)) * ((new_start - *buffer) + 2));
		if (!line)
			return (NULL);
		line = ft_strchrcpy(line, *buffer, '\n');
		temp = next_line(*buffer);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*new_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_buff = find_line(fd);
	while (new_buff)
	{
		if (!buffer)
			buffer = ft_strdup(new_buff);
		else
			buffer = ft_strjoin(buffer, new_buff);
		free(new_buff);
		if (ft_strchr(buffer, '\n') != NULL)
		{
			line = fill_line(&buffer);
			return (line);
		}
		new_buff = find_line(fd);
	}
	if (buffer && *buffer)
		return (fill_line(&buffer));
	return (NULL);
}
