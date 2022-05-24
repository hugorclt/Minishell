/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/25 00:42:51 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_execute(t_node *params, t_list **lst, t_list **lst_to_free)
{
	char	*path;

	if (ft_is_builtin((*lst)->token[0]) == 1)
	{
		ft_close_redirect(lst);
		if (ft_exec_builtin(params, (*lst)->token, lst_to_free) == -1)
			return (-1);
		ft_exit(params, lst_to_free, 1);
	}
	else
	{
		path = check_path(get_path_lst(params->env), (*lst)->token[0]);
		ft_close_redirect(lst);
		if (!path)
		{
			free(path);
			ft_exit(params, lst_to_free, 127);
			return (-1);
		}
		close(params->save_in);
		close(params->save_out);
		if (execve(path, (*lst)->token, params->env) == -1)
			return (free(path), ft_exit(params, lst_to_free, 1), -1);
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

int	do_expandable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	ft_heredoc(t_list **lst, int *i, t_node *params)
{
	int		fd;
	char	*line;
	char	*line_after_expand;

	fd = open(".heredoc_temp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		return (perror(".heredoc_temp"), -1);
	while (1)
	{
		ft_putstr_fd("heredoc$>", 1);
		line = get_next_line(0);
		line = ft_cut_tail(line);
		if (do_expandable((*lst)->limiter) == 0)
			ft_verif_dollars(&line_after_expand, line, params);
		else
			line_after_expand = ft_strdup(line);
		if (!line_after_expand)
			ft_putstr_fd("\n", 1);
		if (!ft_strcmp(line_after_expand, (*lst)->limiter) || !line_after_expand)
			break ;
		line_after_expand = ft_strjoin_char(line_after_expand, '\n');
		if (!line_after_expand)
			return (free(line), -1);
		ft_putstr_fd(line_after_expand, fd);
		free(line);
		free(line_after_expand);
	}
	if (ft_heredoc_help(&fd, lst, i) == -1)
		return (free(line), free(line_after_expand), -1);
	if (line)
		free(line);
	if (line_after_expand)
		free(line_after_expand);
	if ((*lst)->file_in[*i].fd < 0)
		return (unlink(".heredoc_temp"), perror(".heredoc_temp"), -1);
	return (1);
}
