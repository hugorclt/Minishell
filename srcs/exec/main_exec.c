/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:44:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 14:39:30 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_binaries(t_list **lst)
{
	t_list	*tmp;
	int		ret;

	tmp = (*lst);
	ret = 0;
	while (tmp)
	{
		if (ft_is_builtin(tmp->token[0]))
			ret++;
		tmp = tmp->next;
	}
	return (ret);
}

int	ft_execute_one_fork_builtin(t_node *params, t_list **lst)
{
	ft_init_pid(params);
	params->pid[0] = fork();
	if (params->pid[0] == 0)
	{
		if (ft_open_io(lst) == -1)
			return (-1);
		ft_dup2((*lst)->last_infile, (*lst)->last_outfile);
		if (ft_exec_builtin(params, (*lst)->token, params->env) == -1)
			return (-1);
	}
	return (0);
}

int	ft_execute_one_builtin(t_node *params, t_list **lst)
{
	params->have_pid = 0;
	if (ft_open_io(lst) == -1)
		return (-1);
	ft_dup2((*lst)->last_infile, (*lst)->last_outfile);
	if (ft_exec_builtin(params, (*lst)->token, params->env) == -1)
		return (-1);
	return (0);
}

int	ft_execute_one_binaries(t_node *params, t_list **lst)
{
	ft_init_pid(params);
	params->pid[0] = fork();
	if (params->pid[0] == 0)
	{
		if (ft_open_io(lst) == -1)
			return (-1);
		ft_dup2((*lst)->last_infile, (*lst)->last_outfile);
		if (ft_execute(params, (*lst)->token, params->env) == -1)
			return (-1);
	}
	return (0);
}

int	ft_exec_one(t_node *params, t_list **lst)
{
	if (ft_is_builtin((*lst)->token[0]) == 1
		&& ft_strcmp((*lst)->token[0], "export") != 0
		&& ft_strcmp((*lst)->token[0], "cd") != 0
		&& ft_strcmp((*lst)->token[0], "unset") != 0)
		{
		if (ft_execute_one_fork_builtin(params, lst) == -1)
			return (-1);
		}
	else if (ft_strcmp((*lst)->token[0], "export") == 0
		&& ft_strcmp((*lst)->token[0], "cd") == 0
		&& ft_strcmp((*lst)->token[0], "unset") == 0)
		{
		if (ft_execute_one_builtin(params, lst) == -1)
			return (-1);
		}
	else
	{
		if (ft_execute_one_binaries(params, lst) == -1)
			return (-1);
	}
	return (0);
}

int	ft_prepare_cmd(t_list **lst)
{
	t_list *tmp;

	tmp = (*lst);
	if (ft_save_file(&tmp) == -1)
		return (-1);
	tmp->token = ft_clean_redirection(&tmp);
	if (!tmp->token)
		return (-1);
	tmp->token = ft_split_space(ft_to_str(tmp->token));
	if (!tmp->token)
		return (-1);
	if (ft_total_unquote(&tmp) == -1)
		return (-1);
	return (0);
}

int	ft_main_exec(t_node *params, t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = (*lst);
	params->nb = ft_lstsize(tmp);
	if (params->nb == 0)
		return (-1);
	i = 0;
	while (i < params->nb)
	{
		if (ft_prepare_cmd(&tmp) == -1)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	if (params->nb == 1)
		ft_exec_one(params, lst);
	else if (ft_child_exec(params, lst) == -1)
		return (-1);
	return (0);
}
