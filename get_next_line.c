/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:48:30 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/10 14:39:07 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_null(char **pt)
{
	if (*pt != NULL)
	{
		free(*pt);
		pt = NULL;
	}
}

static char	*join_line(int nl_index, char **buffer)
{
	char	*result;
	char	*tmp;

	tmp = NULL;
	if (nl_index <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		result = *buffer;
		*buffer = NULL;
		return (result);
	}
	tmp = ft_substr(*buffer, nl_index, BUFFER_SIZE);
	result = *buffer;
	result[nl_index] = 0;
	*buffer = tmp;
	return (result);
}

static char	*ft_read(int fd, char **buf, char *aux)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buf, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buf));
		aux[bytes_read] = 0;
		tmp = ft_strjoin(*buf, aux);
		ft_free_null(buf);
		*buf = tmp;
		nl = ft_strchr(*buf, '\n');
	}
	return (join_line(nl - *buf + 1, buf));
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*aux;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	aux = (char *)malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	if (!buf)
		buf = ft_strdup("");
	line = ft_read(fd, &buf, aux);
	ft_free_null(&aux);
	return (line);
}
