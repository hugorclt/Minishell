/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:33:01 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/10 16:12:47 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_command_nt_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(COMMAND_NOT_FOUND, 2);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s2[i] && s2[i])
	{
		if (s1[i + 1] == '\n')
			break ;
		++i;
	}
	return (s1[i] - s2[i]);
}

void	ft_close(void)
{
	close(1);
	close(2);
	close(0);
}

void	ft_heredoc_infile(t_node *params)
{
	params->infile = open(".heredoc_temp", O_RDONLY, 0644);
	params->infile_name = ft_strdup(".heredoc_temp");
}
