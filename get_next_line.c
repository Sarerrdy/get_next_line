/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:57:39 by eina              #+#    #+#             */
/*   Updated: 2025/11/19 06:55:26 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*get_line(char **databasin)
{
	char	*newline;
	char	*line;
	char	*leftover;
	size_t	len;

	newline = ft_strchr(*databasin, '\n');
	if (!*databasin || **databasin == '\0')
		return (NULL);
	if (newline)
	{
		len = newline - *databasin + 1;
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		ft_memcpy(line, *databasin, len);
		line[len] = '\0';
		leftover = ft_strjoin(NULL, newline + 1);
		free(*databasin);
		*databasin = leftover;
		return (line);
	}
	line = *databasin;
	*databasin = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	size_t		read_bytes;
	char		*buffer;
	static char	*databasin;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(databasin, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		databasin = ft_strjoin(databasin, buffer);
	}
	return (get_line(&databasin));
}
