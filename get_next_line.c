/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:57:39 by eina              #+#    #+#             */
/*   Updated: 2025/11/24 11:47:40 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*ft_freemultiple(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

static char	*get_line(char **databasin)
{
	char	*newline;
	char	*line;
	char	*leftover;
	size_t	len;

	if (!databasin || !*databasin || **databasin == '\0')
		return (NULL);
	newline = ft_strchr(*databasin, '\n');
	if (newline)
	{
		len = (size_t)(newline - *databasin) + 1;
		line = (char *)malloc(len + 1);
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
	ssize_t		read_bytes;
	char		*buffer;
	char		*joined;
	static char	*databasin;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_strchr(databasin, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_freemultiple(buffer, databasin));
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		joined = ft_strjoin(databasin, buffer);
		if (!joined)
			return (ft_freemultiple(buffer, databasin));
		free(databasin);
		databasin = joined;
	}
	free(buffer);
	return (get_line(&databasin));
}
