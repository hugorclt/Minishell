/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:54:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/11 18:27:26 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next_line(char *line)
{
	char	*output;
	size_t	i;
	size_t	j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	if (!line[i] || !line[i + 1])
		return (free(line), NULL);
	if (line[i])
		++i;
	output = malloc(sizeof(char) * (ft_strlen(line + i) + 1));
	if (!output)
		return (free(line), NULL);
	j = 0;
	while (line[i])
	{
		output[j] = line[i];
		++i;
		++j;
	}
	output[j] = 0;
	return (free(line), output);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*output;
	char		*buf;
	int			read_file;

	if (BUFFER_SIZE <= 0 && fd <= 0)
		return (NULL);
	read_file = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read_file && (!(ft_strchr_pimp(line, '\n'))))
	{
		read_file = read(fd, buf, BUFFER_SIZE);
		buf[read_file] = 0;
		if (read_file <= 0)
			break ;
		line = ft_strjoin_pimp(line, buf);
	}
	output = ft_strdup_pimp(line);
	line = ft_next_line(line);
	return (free(buf), output);
}
