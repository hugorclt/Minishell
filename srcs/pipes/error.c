/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:33:01 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/26 16:17:11 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_nt_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(COMMAND_NOT_FOUND, 2);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_close(void)
{
	close(1);
	close(2);
	close(0);
}

int	ft_heredoc_infile(t_list **lst, int *i)
{
	(*lst)->file_in[*i].fd = open(".heredoc_temp", O_RDONLY, 0644);
	if ((*lst)->file_in[*i].fd == -1)
		return (-1);
	free((*lst)->file_in[*i].file);
	(*lst)->file_in[*i].file = ft_strdup(".heredoc_temp");
	if (!(*lst)->file_in[*i].file)
		return (-1);
	return (0);
}
