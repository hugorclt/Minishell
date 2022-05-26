/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:36:31 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/26 15:49:05 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_free_heredoc(char *line, char *line_after_expand)
{
	if (line)
		free(line);
	if (line_after_expand)
		free(line_after_expand);
}

int	ft_heredoc_help_2(char *line, char *line_after_expand, int fd)
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
	if (ft_refacto_rl(lst, i, params, lst_to_free) < 0)
		return (-1);
	if ((*lst)->file_in[*i].fd < 0)
		return (unlink(".heredoc_temp"), perror(".heredoc_temp"), -1);
	sig_choice(0);
	return (1);
}
