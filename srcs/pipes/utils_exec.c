/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/26 13:47:01 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_forked(t_node *params, t_list **lst)
{
	ft_close_redirect(lst);
	close(params->save_in);
	close(params->save_out);
}

int	ft_execute(t_node *params, t_list **lst, t_list **lst_to_free)
{
	char	*path;

	sig_choice(2);
	if ((*lst)->token[0] == NULL)
	{
		ft_close_forked(params, lst);
		ft_exit(params, lst_to_free, 1);
	}
	if (ft_is_builtin((*lst)->token[0]) == 1)
	{
		ft_close_redirect(lst);
		if (ft_exec_builtin(params, (*lst)->token, lst_to_free) == -1)
			return (-1);
		ft_exit(params, lst_to_free, 1);
	}
	else
	{
		path = check_path(get_path_lst(params->env), (*lst)->token[0]);
		ft_close_forked(params, lst);
		if (!path)
		{
			free(path);
			ft_exit(params, lst_to_free, 127);
			return (-1);
		}
		if (execve(path, (*lst)->token, params->env) == -1)
			return (free(path), ft_exit(params, lst_to_free, 1), -1);
	}
	return (1);
}

int	ft_init_pipe(t_node *params)
{
	int	i;

	i = 0;
	params->fd = malloc(sizeof(int) * (params->nb - 1) * 2);
	if (!params->fd)
		return (-1);
	while (i < params->nb - 1)
	{
		if (pipe(params->fd + i * 2) < 0)
			return (-1);
		++i;
	}
	return (1);
}
