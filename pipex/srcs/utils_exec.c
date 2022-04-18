/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/10 14:26:57 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_execute(char **av, char **envp)
{
	char	*path;

	path = check_path(get_path_lst(envp), av[0]);
	if (!path)
		return (ft_free(av), -1);
	if (execve(path, av, envp) == -1)
		return (ft_free(av), free(path), -1);
	return (1);
}

int	ft_init_pipe(t_node *params)
{
	int	i;

	i = 0;
	params->fd = malloc(sizeof(int) * (params->nb - 1) * 2);
	if (!params->fd)
		return (-1);
	while (i < params->nb - 1)
	{
		if (pipe(params->fd + i * 2) < 0)
			return (-1);
		++i;
	}
	return (1);
}

int	ft_open(t_node *params, char *infile, char *outfile, int flag)
{
	if (flag < 1)
	{
		params->infile = open(infile, O_RDONLY, 0644);
		params->infile_name = ft_strdup(infile);
	}
	else
		ft_heredoc(params);
	params->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (params->outfile < 0)
		return (-1);
	params->outfile_name = ft_strdup(outfile);
	if (!params->infile_name || !params->outfile_name)
		return (-1);
	return (1);
}

int	ft_heredoc(t_node *params)
{
	int		fd;
	char	*line;

	fd = open(".heredoc_temp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		return (perror(".heredoc_temp"), -1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			ft_putstr_fd("\n", 1);
		if (!ft_strcmp(line, params->limiter) || !line)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
	ft_heredoc_infile(params);
	free(params->limiter);
	if (line)
		free(line);
	if (params->infile < 0)
		return (unlink(".heredoc_temp"), perror(".heredoc_temp"), -1);
	return (1);
}
