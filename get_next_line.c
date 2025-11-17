/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:57:39 by eina              #+#    #+#             */
/*   Updated: 2025/11/14 10:43:08 by eina             ###   ########.fr       */
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
	size_t	i;

	newline = ft_strchr(*databasin, '\n');
	if (!*databasin || **databasin == '\0')
		return (NULL);
	if (newline)
	{
		len = newline - *databasin;
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		i = 0;
		ft_memcpy(line, *databasin, len);
		line[len] = '\0';
		leftover = ft_strjoin(NULL, newline + 1);
		free(*databasin);
		*databasin = leftover;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	size_t		read_bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*databasin;

	if (fd < 0 && buffer <= 0)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(databasin, '\n'))
	{
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		databasin = ft_strjoin(databasin, buffer);
	}
	return (get_line(&databasin));
}
