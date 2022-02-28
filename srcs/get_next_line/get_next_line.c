/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:57:38 by hrecolet          #+#    #+#             */
/*   Updated: 2021/11/30 14:38:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_left(char *left_str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == 0)
	{
		free(left_str);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		ret[j++] = left_str[i++];
	ret[j] = '\0';
	free(left_str);
	return (ret);
}

char	*get_line(char *left_str)
{
	int		i;
	char	*ret;

	i = 0;
	if (*left_str == 0)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		ret[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*read_left(int fd, char *left_str)
{
	char	*buffer;
	int		b_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b_read = 1;
	while (b_read != 0 && !(ft_strchr(left_str, '\n')))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[b_read] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = read_left(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_line(left_str);
	left_str = next_left(left_str);
	return (line);
}
