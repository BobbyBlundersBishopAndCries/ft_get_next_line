/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:36:08 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/02 05:58:48 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_to_buffer(int fd, char **buffer)
{
	char	*temp;
	int		bytes_read;
	char	*new_buffer;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		new_buffer = ft_strjoin(*buffer, temp);
		*buffer = new_buffer;
	}
	free(temp);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[_SC_OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer[fd] = read_to_buffer(fd, &buffer[fd]);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = new_line(buffer[fd]);
	return (line);
}
