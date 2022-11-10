/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:50:36 by mel-mars          #+#    #+#             */
/*   Updated: 2022/11/10 10:57:26 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from(int fd, char *src)
{
	char	*str;
	int		d;

	d = 1;
	str = ft_calloc(BUFFER_SIZE + 1, 1);
	while (ft_check_line(src) == 0 && d != 0)
	{
		d = read(fd, str, BUFFER_SIZE);
		if (d == -1)
		{
			free(str);
			free(src);
			return (NULL);
		}
		str[d] = '\0';
		src = ft_strjoin(src, str);
	}
	free(str);
	return (src);
}

char	*before(char *src)
{
	char	*dest;
	int		i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (src[i] == '\n')
		dest = ft_calloc(i + 2, 1);
	else
		dest = ft_calloc(i + 1, 1);
	if (dest == 0)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

char	*after(char *src)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (src[i] == '\0')
	{
		free(src);
		return (NULL);
	}
	tmp = ft_calloc(ft_strlen(src) - i + 1, 1);
	i++;
	while (src[i + j] != '\0')
	{
		tmp[j] = src[i + j];
		j++;
	}
	free(src);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*src[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX
		|| BUFFER_SIZE >= 2147483647)
		return (NULL);
	src[fd] = read_from(fd, src[fd]);
	if (src[fd] == NULL)
	{
		free(src[fd]);
		return (NULL);
	}
	line = before(src[fd]);
	src[fd] = after(src[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
