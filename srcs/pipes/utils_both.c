/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:58:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/18 14:14:10 by hrecolet         ###   ########.fr       */
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

int	ft_child_exec(t_node *params, t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*lst);
	params->index = 0;
	ft_init_pid(params);
	ft_init_pipe(params);
	//if (params->heredoc)
	//	i = 0;
	while (tmp)
	{
		if (ft_fork(params, params->env, &tmp, lst) < 0)
		{
			ft_close();
			ft_exit(params, lst, 0);
		}
		params->index++;
		i++;
		tmp = tmp->next;
	}
	//ft_close_total(params, lst);
	return (1);
}
