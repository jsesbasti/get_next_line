/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:05:15 by jsebasti          #+#    #+#             */
/*   Updated: 2022/11/10 13:51:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_buf(char *buf)
{
	char	*new_buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buf, '\n');
	if (!ptr)
	{
		new_buf = NULL;
		return (ft_free(&buf));
	}
	else
		len = (ptr - buf) + 1;
	if (!buf[len])
		return (ft_free(&buf));
	new_buf = ft_substr(buf, len, ft_strlen(buf) - len);
	ft_free(&buf);
	if (!new_buf)
		return (NULL);
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
	int		rd;
	char	*tmp;

	rd = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free(&buf));
	tmp[0] = '\0';
	while (rd > 0 && !ft_strchr(tmp, '\n'))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd > 0)
		{
			tmp[rd] = '\0';
			buf = ft_strjoin(buf, tmp);
		}
	}
	free(tmp);
	if (rd == -1)
		return (ft_free(&buf));
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buf[fd] || (buf[fd] && !ft_strchr(buf[fd], '\n')))
		buf[fd] = ft_read(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = new_line(buf[fd]);
	if (!line)
		return (ft_free(&buf[fd]));
	buf[fd] = clean_buf(buf[fd]);
	return (line);
}
