/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:36:08 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/03 02:29:19 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_from_fd(int fd)
{
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(temp);
		return (NULL);
	}
	temp[bytes_read] = '\0';
	return (temp);
}

static char	*update_buffer(char **buffer, char *temp)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(*buffer, temp);
	free(*buffer);
	*buffer = new_buffer;
	return (*buffer);
}

static char	*read_to_buffer(int fd, char **buffer)
{
	char	*temp;

	while (!ft_strchr(*buffer, '\n'))
	{
		temp = read_from_fd(fd);
		if (!temp)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		if (*temp == '\0')
		{
			free(temp);
			break ;
		}
		update_buffer(buffer, temp);
		free(temp);
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer[fd] = read_to_buffer(fd, &buffer[fd]);
	if (!(buffer[fd]))
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = new_line(buffer[fd]);
	return (line);
}
