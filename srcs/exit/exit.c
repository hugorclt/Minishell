/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:24:13 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/25 05:30:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_params_2(t_node *params, int flag)
{
	if (params->limiter)
	{
		free(params->limiter);
		params->limiter = NULL;
	}
	if (params->fd)
	{
		free(params->fd);
		params->fd = NULL;
	}
	if (params->root && flag == 0)
	{
		free(params->root);
		params->root = NULL;
	}
	if (params->io_env)
	{
		ft_free(params->io_env);
		params->io_env = NULL;
	}
}

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
	ft_free_params_2(params, flag);
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
	int		i;
	t_list	*tmp;

	tmp = (*start);
	i = 0;
	while (tmp)
	{
		if (sizeof(tmp->token))
			ft_free(tmp->token);
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
		i++;
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

void	ft_exit(t_node *params, t_list **start, int value)
{
	if (params->save_in)
		close(params->save_in);
	if (params->save_out)
		close(params->save_out);
	ft_free_params(params, 0);
	if (start)
	{
		ft_free_list(start);
		ft_free_lst(start);
	}
	if (params->have_pid == 0)
		write(1, "exit\n", 6);
	g_last_status = value;
	exit(value);
}

void	ft_free_after_cmd(t_node *params, t_list **start, int flag)
{
	if (params->save_in)
		close(params->save_in);
	if (params->save_out)
		close(params->save_out);
	ft_free_params(params, flag);
	if (start)
	{
		ft_free_list(start);
		ft_free_lst(start);
	}
}
