/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:58:11 by eina              #+#    #+#             */
/*   Updated: 2025/11/19 06:53:45 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef SIZE_MAX
# define SIZE_MAX __SIZE_MAX__
#endif

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total;

	total = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		ptr[i] = 0;
		i++;
		total--;
	}
	return (ptr);
}

static size_t	checktotalstrlen(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	int		count;

	if (s1)
	{
		count = 0;
		while (s1[count])
			count++;
		s1_len = count;
	}
	else
		s1_len = 0;
	if (s2)
	{
		count = 0;
		while (s2[count])
			count++;
		s2_len = count;
	}
	else
		s2_len = 0;
	return (s1_len + s2_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	newstr = ft_calloc(checktotalstrlen(s1, s2) + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (!dest || !src)
		return (NULL);
	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	while (n--)
	{
		*dptr = *sptr;
		dptr++;
		sptr++;
	}
	return (dest);
}
