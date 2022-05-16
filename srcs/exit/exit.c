/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:24:13 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/16 16:10:39 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_free_params(t_node *params)
{
	if (params->env)
		ft_free(env);
	if (params->infile_name)
		free(params->infile_name);
	if (params->outfile_name)
		free(params->outfile_name);
	if (params->cmd)
		ft_free(cmd);
	if (params->cmd_args)
		ft_free(cmd_args);
	if (params->pid)
		free(params->pid);
	if (params->limiter)
		free(params->limiter);
	if (params->fd)
		free(params->fd);
}

static void	ft_free_list(t_list **start)
{
	t_list	*tmp;

	tmp = (*start);
	while (tmp)
	{
		if (tmp->token)
			ft_free(token);
		if (tmp->cmd)
			free(cmd);
		if (tmp->file_in)
			free(tmp->file_in);
		if (tmp->file_out)
			free(tmp->file_out);
		tmp = tmp->next;
	}
}

static void	ft_free_lst(t_list **start)
{
	t_list	*tmp;

	while ((*start))
	{
		tmp = (*start);
		(*start) = (*start)->next;
		free(tmp);
	}
	free((*start));
}

void	ft_exit(t_node *params, t_list *start, int errno)
{
	ft_free_params(params);
	if (start)
	{
		ft_free_list(&start);
		ft_lstclear(&start);
	}
	exit(errno);
}
