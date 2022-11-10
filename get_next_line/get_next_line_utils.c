/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:15:17 by mel-mars          #+#    #+#             */
/*   Updated: 2022/11/09 14:14:35 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_check_line(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_calloc(size_t count, size_t size)
{
	char		*pn;
	size_t		i;

	i = 0;
	if (size > 0 && count >= (SIZE_T_MAX / size))
		return (NULL);
	pn = malloc(count * size);
	if (pn == 0)
		return (0);
	while (i < count * size)
	{
		pn[i] = '\0';
		i++;
	}
	return (pn);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	i = 0;
	if (dstsize == 0 || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	d = ft_strlen(dst);
	s = ft_strlen(src);
	while (i < dstsize - d - 1 && src[i] != '\0')
	{
		dst[d + i] = src[i];
		i++;
	}
	return (d + s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	strjoin = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (strjoin == 0)
		return (0);
	ft_strlcat(strjoin, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(strjoin, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (strjoin);
}
