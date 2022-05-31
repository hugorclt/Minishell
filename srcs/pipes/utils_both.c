/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:58:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/31 21:47:28 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_init_pid(t_node *params)
{
	params->pid = malloc(sizeof(pid_t) * params->nb);
	if (!params->pid)
		return (-1);
	params->have_pid = 1;
	return (1);
}
/*
int	ft_open_heredoc(t_node *params, t_list **lst, t_list **lst_to_free)
{
	int	i;

	i = 0;
	while (i < (*lst)->nb_infile)
	{
		if ((*lst)->file_in[i].flag == 1)
		{
			(*lst)->limiter = ft_strdup((*lst)->file_in[i].file);
			if (!(*lst)->limiter)
				return (-1);
			ft_heredoc(lst, &i, params, lst_to_free);
		}
		i++;
	}
	return (0);
}*/

int	ft_child_exec(t_node *params, t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*lst);
	params->index = 0;
	ft_init_pid(params);
	ft_init_pipe(params);
	while (tmp)
	{
		if (ft_fork(params, &tmp, lst) < 0)
		{
			ft_close();
			ft_exit(params, lst, 0);
		}
		params->index++;
		i++;
		tmp = tmp->next;
	}
	return (1);
}
