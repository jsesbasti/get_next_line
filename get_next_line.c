/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:05:15 by jsebasti          #+#    #+#             */
/*   Updated: 2022/10/16 03:07:36 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_buf(char *buf)
{
	char	*new_buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buf, '\n');
	if (!ptr)
	{
		free(buf);
		new_buf = NULL;
		return (NULL);
	}
	else
		len = (ptr - buf) + 1;
	if (!buf[len])
	{
		free(buf);
		return (NULL);
	}
	new_buf = ft_substr(buf, len, ft_strlen(buf) - len);
	if (!new_buf)
		return (NULL);
	free(buf);
	return (new_buf);
}

char	*new_line(char *buf)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buf, '\n');
	len = (ptr - buf) + 1;
	line = ft_substr(buf, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *buf)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	buffer[0] = '\0';
	while (rd > 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (rd > 0)
		{
			buffer[rd] = '\0';
			buf = ft_strjoin(buf, buffer);
		}
	}
	free(buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buf || (buf && !ft_strchr(buf, '\n')))
		buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = new_line(buf);
	if (!line)
	{
		free(buf);
		return (NULL);
	}
	buf = clean_buf(buf);
	return (line);
}
