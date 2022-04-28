/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:33:01 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/28 12:12:34 by hrecolet         ###   ########.fr       */
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

void	ft_heredoc_infile(t_node *params)
{
	params->infile = open(".heredoc_temp", O_RDONLY, 0644);
	params->infile_name = ft_strdup(".heredoc_temp");
}
