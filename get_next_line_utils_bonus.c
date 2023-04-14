/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:12:53 by jsebasti          #+#    #+#             */
/*   Updated: 2022/11/10 13:40:58 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_hudston(char *s1, char *s2, char *res)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	j = -1;
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (ft_free(&s1));
	while (++i < len1)
		res[i] = s1[i];
	while (++j <= len2)
		res[i + j] = s2[j];
	free(s1);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	res = NULL;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	res = ft_hudston(s1, s2, res);
	return (res);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	char	*res;

	lens = ft_strlen(str);
	i = 0;
	if (!str)
		return (0);
	if (start > lens)
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (lens - start < len)
		len = lens - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < lens && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
