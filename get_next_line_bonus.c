/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:57:39 by eina              #+#    #+#             */
/*   Updated: 2025/11/25 08:51:49 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*ft_freeupdate(char **old, char *new, char *extra)
{
	if (old && *old)
		free(*old);
	if (extra)
		free(extra);
	if (new && *new == '\0')
	{
		free(new);
		new = NULL;
	}
	if (old)
		*old = new;
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
		ft_freeupdate(databasin, leftover, NULL);
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
	static char	*databasin[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(databasin[fd] && ft_strchr(databasin[fd], '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_freeupdate(&databasin[fd], NULL, buffer));
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		joined = ft_strjoin(databasin[fd], buffer);
		if (!joined)
			return (ft_freeupdate(&databasin[fd], NULL, buffer));
		ft_freeupdate(&databasin[fd], joined, NULL);
		databasin[fd] = joined;
	}
	free(buffer);
	return (get_line(&databasin[fd]));
}
