/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:51:33 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/26 16:17:12 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_iamcrying(t_list **lst, char **line_ex, char *line, t_node *params)
{
	if (do_expandable((*lst)->limiter) == 0)
		ft_verif_dollars(line_ex, line, params);
	else
		*line_ex = ft_strdup(line);
}

int	init_heredoc(int *fd, char **line_expand)
{
	*line_expand = NULL;
	*fd = open(".heredoc_temp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (*fd < 0)
		return (perror(".heredoc_temp"), -1);
	return (0);
}

static void	ft_refacto_exit(t_node *params, t_list **lst_to_free, int fd)
{
	close(fd);
	unlink(".heredoc_temp");
	ft_close_all(params);
	ft_exit(params, lst_to_free, 0);
}

int	ft_refacto_rl(t_list **lst, int *i, t_node *params, t_list **lst_to_free)
{
	char	*line;
	char	*line_expand;
	int		fd;

	sig_choice(1);
	if (init_heredoc(&fd, &line_expand) == -1)
		return (-1);
	while (1)
	{	
		line = readline("> ");
		if (!line)
			ft_refacto_exit(params, lst_to_free, fd);
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
	return (0);
}
