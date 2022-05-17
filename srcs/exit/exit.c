/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:24:13 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/17 21:55:47 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_params(t_node *params, int flag)
{
	if (flag == 0)
	{
		if (params->env)
			ft_free(params->env);
	}
	if (params->pid)
	{
		free(params->pid);
		params->pid = NULL;
	}
	if (params->limiter)
		free(params->limiter);
	if (params->fd)
		free(params->fd);
	if (params->prompt)
		free(params->prompt);
}

void	ft_free_infile(t_list *tmp)
{
	int	i;

	i = 0;
	while (i < tmp->nb_infile)
		free(tmp->file_in[i++].file);
}

void	ft_free_outfile(t_list *tmp)
{
	int	i;

	i = 0;
	while (i < tmp->nb_outfile)
		free(tmp->file_out[i++].file);
}

void	ft_free_list(t_list **start)
{
	t_list	*tmp;

	tmp = (*start);
	while (tmp)
	{
		if (tmp->token)
			ft_free(tmp->token);
		if (tmp->cmd)
			free(tmp->cmd);
		if (tmp->file_in)
		{
			ft_free_infile(tmp);
			free(tmp->file_in);
		}
		if (tmp->file_out)
		{
			ft_free_outfile(tmp);
			free(tmp->file_out);
		}
		tmp = tmp->next;
	}
}

void	ft_free_lst(t_list **start)
{
	t_list	*tmp;
	
	while ((*start))
	{
		tmp = (*start);
		(*start) = (*start)->next;
		free(tmp);
	}
	free(*start);
}

void	ft_exit(t_node *params, t_list **start)
{
	ft_free_params(params, 0);
	if (start)
	{
		ft_free_list(start);
		ft_free_lst(start);
	}
	exit(errno);
}

void	ft_free_after_cmd(t_node *params, t_list **start)
{
	ft_free_params(params, 1);
	if (start)
	{
		ft_free_list(start);
		ft_free_lst(start);
	}
}