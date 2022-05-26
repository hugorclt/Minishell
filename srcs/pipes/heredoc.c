/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:36:31 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/26 13:42:34 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_heredoc_help(int	*fd, t_list **lst, int *i)
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

static void	ft_free_heredoc(char *line, char *line_after_expand)
{
	if (line)
	{
		free(line);
	}
	if (line_after_expand)
	{
		free(line_after_expand);
	}
}

static int	ft_heredoc_help_2(char *line, char *line_after_expand, int fd)
{
	line_after_expand = ft_strjoin_char(line_after_expand, '\n');
	if (!line_after_expand)
		return (free(line), -1);
	ft_putstr_fd(line_after_expand, fd);
	ft_free_heredoc(line, line_after_expand);
	return (0);
}

int	ft_heredoc(t_list **lst, int *i, t_node *params, t_list **lst_to_free)
{
	int		fd;
	char	*line;
	char	*line_expand;

	sig_choice(1);
	if (init_heredoc(&fd, &line_expand) == -1)
		return (-1);
	while (1)
	{	
		line = readline("> ");
		if (!line)
		{
			close(fd);
			unlink(".heredoc_temp");
			ft_close_all(params);
			ft_exit(params, lst_to_free, 0);
		}
		ft_iamcrying(lst, &line_expand, line, params);
		if (!line_expand)
			ft_putstr_fd("\n", 1);
		if (!ft_strcmp(line_expand, (*lst)->limiter) || !line_expand)
			break ;
		if (ft_heredoc_help_2(line, line_expand, fd) == -1)
			return (-1);
	}
	if (ft_heredoc_help(&fd, lst, i) == -1)
		return (free(line), free(line_expand), -1);
	ft_free_heredoc(line, line_expand);
	if ((*lst)->file_in[*i].fd < 0)
		return (unlink(".heredoc_temp"), perror(".heredoc_temp"), -1);
	sig_choice(0);
	return (1);
}
