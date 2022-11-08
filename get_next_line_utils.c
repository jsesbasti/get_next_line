/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:12:53 by jsebasti          #+#    #+#             */
/*   Updated: 2022/11/07 17:45:43 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *buf, char c)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != c)
		i++;
	if (buf[i] == '\0')
		return (NULL);
	return (&buf[i]);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
	{
		if (!s1)
			return (s2);
		if (!s2)
			return (s1);
	}
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		res[i] = s1[i];
	while (++j <= ft_strlen(s2))
	{
		res[i] = s2[j];
		i++;
	}
	return (res);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (0);
	if (start > ft_strlen(str))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(str) && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
