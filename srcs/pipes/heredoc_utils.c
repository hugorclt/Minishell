/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:51:33 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 04:51:52 by hrecolet         ###   ########.fr       */
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
