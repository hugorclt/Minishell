/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/17 10:07:03 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_execute(t_node *params, char **av, char **envp)
{
	char	*path;

	if (ft_is_builtin(av[0]) == 1)
	{
		if (ft_exec_builtin(params, av) == -1)
			return (-1);
		ft_exit(params, NULL);
	}
	else
	{
		path = check_path(get_path_lst(envp), av[0]);
		if (!path)
			return (ft_free(av), -1);
		if (execve(path, av, envp) == -1)
			return (ft_free(av), free(path), -1);
	}
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

int	ft_heredoc_help(int	*fd, t_list **lst, int *i)
{
	close(*fd);
	if (ft_heredoc_infile(lst, i) == -1)
		return (-1);
	free((*lst)->limiter);
	(*lst)->limiter = NULL;
	return (0);
}

int	ft_heredoc(t_list **lst, int *i)
{
	int		fd;
	char	*line;

	fd = open(".heredoc_temp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		return (perror(".heredoc_temp"), -1);
	while (1)
	{
		ft_putstr_fd("heredoc$>", 1);
		line = get_next_line(0);
		if (!line)
			ft_putstr_fd("\n", 1);
		if (!ft_strcmp(line, (*lst)->limiter) || !line)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	if (ft_heredoc_help(&fd, lst, i) == -1)
		return (free(line), -1);
	if (line)
		free(line);
	if ((*lst)->file_in[*i].fd < 0)
		return (unlink(".heredoc_temp"), perror(".heredoc_temp"), -1);
	return (1);
}
