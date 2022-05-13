/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:29:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/13 10:54:49 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_all(t_node *params)
{
	int	i;

	i = 0;
	while (i < (params->nb - 1) * 2)
	{
		close(params->fd[i++]);
	}
}

int	ft_fork(t_node *params, char **envp, t_list **lst)
{
	params->pid[params->index] = fork();
	if (params->pid[params->index] == 0)
	{
		ft_open_io(lst);
		if (params->index == 0)
		{
			if (params->last_infile < 0)
				return (perror(params->infile_name), -1);
			ft_dup2((*lst)->last_infile, params->fd[1]);
		}
		else if (params->index == params->nb - 1)
			ft_dup2(params->fd[2 * params->index - 2], (*lst)->last_outfile);
		else
			ft_dup2(params->fd[2 * params->index - 2],
				params->fd[2 * params->index + 1]);
		ft_close_all(params);
		if (ft_execute(params, (*lst)->token, envp) < 0)
			return (-1);
	}
	return (1);
}

void	ft_dup2(int in, int out)
{
	dup2(in, 0);
	dup2(out, 1);
}

int	ft_cmp_heredoc(char **av, char *heredoc, t_node *params, int ac)
{
	if (ft_strcmp(av[1], heredoc))
	{
		params->nb = ac - 3;
		params->limiter = NULL;
		return (0);
	}
	else
	{
		params->nb = ac - 4;
		params->limiter = ft_strdup(av[2]);
		return (1);
	}
}

void	ft_wrong_args(void)
{
	ft_putstr_fd("wrong arguments\n", 2);
	ft_close();
	exit(EXIT_FAILURE);
}
