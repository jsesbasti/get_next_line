/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:12:53 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/16 03:41:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *buf, int c)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == (char)c)
			return (&((char *)buf)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)buf)[i]);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_strjoinif(char *buf)
{
	buf = malloc(sizeof(char) + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

char	*ft_strjoin(char *buf, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!buf)
		buf = ft_strjoinif(buf);
	res = (char *)malloc(ft_strlen(buf) + ft_strlen(buffer) + 1);
	if (!res)
	{
		free(buf);
		return (0);
	}
	i = -1;
	while (buf[++i])
		res[i] = buf[i];
	j = 0;
	while (buffer[j])
	{
		res[i + j] = buffer[j];
		j++;
	}
	res[i + j] = '\0';
	free(buf);
	return (res);
}

char	*ft_substr(char *buf, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!buf)
		return (0);
	if (start > ft_strlen(buf))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(buf) - start < len)
		len = ft_strlen(buf) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(buf) && i < len && buf[start])
		res[i++] = buf[start++];
	res[i] = '\0';
	return (res);
}
