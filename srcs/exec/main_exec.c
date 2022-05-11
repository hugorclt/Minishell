/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:44:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/11 12:55:55 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_cut_tab(char **tab, int start, int end)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * ft_tab_size(tab) - 1);
	i = 0;
	if (!ret)
		return (NULL);
	while (i < start)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	while (tab[end])
	{
		ret[i] = ft_strdup(tab[end]);
		i++;
		end++;
	}
	ret[i] = 0;
	return (ret);
}

int	ft_count_in(char **cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "<") == 0 || ft_strcmp(cmd[i], "<<") == 0)
			ret++;
		i++;
	}
	return (ret);
}

int	ft_count_out(char **cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], ">") == 0 || ft_strcmp(cmd[i], ">>") == 0)
			ret++;
		i++;
	}
	return (ret);
}

int	ft_prepare_to_execute(t_list **lst)
{
	(*lst)->token = ft_split_space(ft_to_str((*lst)->token));
	if (ft_get_input(lst, (*lst)->token) == -1)
		return (-1);
	(*lst)->token = ft_cut_io(lst);
	if (!(*lst)->token)
		return (-1);
	return (0);
}

int	ft_close_total(t_node *params, t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*lst);
	while (i < tmp->nb_infile)
	{
		close(params->infile[i]);
		i++;
	}
	i = 0;
	while (i < tmp->nb_outfile)
	{
		close(params->outfile[i]);
		i++;
	}
	return (0);
}

int	ft_exec_one(t_list **lst, char **env)
{
	int		pid;
	t_node	params;
	t_list	*tmp;

	tmp = (*lst);
	pid = fork();
	if (ft_init_io(&tmp, &params) == -1)
		return (-1);
	if (pid == 0)
	{
		if (ft_prepare_to_execute(&tmp) == -1)
			return (-1);
		if (ft_open_io(lst, &params) == -1)
			return (-1);
		if (ft_dup_io(&params) == -1)
			return (-1);
		tmp->cmd = ft_to_str(tmp->token);
		if (!tmp->cmd)
			return (-1);
		if (ft_execute(ft_split_space(tmp->cmd), env) == -1)
			return (-1);
		ft_close_total(&params, &tmp);
	}
	return (0);
}

int	ft_fill_params(t_node *params, int size)
{
	params->nb = size;
	if (ft_init_pipe(params) == -1)
		return (-1);
	if (ft_init_pid(params) == -1)
		return (-1);
	return (0);
}

int	ft_wait_all_pid(t_node *params)
{
	int	i;
	int	status;

	i = 0;
	while (i < params->nb - 1)
	{
		if (waitpid(params->pid[i], &status, 0) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_main_exec(t_list **lst, char **env)
{
	t_list	*tmp;
	t_node	params;

	tmp = (*lst);
	if (ft_lstsize(tmp) == 1)
	{
		if (ft_exec_one(lst, env) == -1)
			return (-1);
	}
	else
	{
		if (ft_fill_params(&params, ft_lstsize(tmp)) == -1)
			return (-1);
		while (tmp)
		{
			if (ft_init_io(&tmp, &params) == -1)
				return (-1);
			if (ft_prepare_to_execute(&tmp) == -1)
				return (-1);
			tmp->cmd = ft_to_str(tmp->token);
			if (!tmp->cmd)
				return (-1);
			tmp = tmp->next;
		}
		if (ft_child_exec(&params, lst, env) == -1)
			return (-1);
		if (ft_wait_all_pid(&params) == -1)
			return (-1);
		//ft_close_total(&params, lst);
	}
	return (0);
}
