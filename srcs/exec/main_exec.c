/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:44:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/11 14:17:34 by hrecolet         ###   ########.fr       */
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


int	ft_fill_params(t_node *params, int size)
{
	params->nb = size;
	if (ft_init_pipe(params) == -1)
		return (-1);
	if (ft_init_pid(params) == -1)
		return (-1);
	return (0);
}

int	ft_prepare_io(t_list **lst, t_node *params)
{
	t_list *tmp;

	tmp = (*lst);
	if (ft_fill_params(params, ft_lstsize(tmp)) == -1)
		return (-1);
	if (ft_init_io(&tmp, params) == -1)
		return (-1);
	if (ft_prepare_to_execute(&tmp) == -1)
		return (-1);
	return (0);
}

int	ft_exec_one(t_list **lst, char **env, t_node *params)
{
	t_list	*tmp;

	tmp = (*lst);
	//ft_fill_params(params, 1);
	params->pid[0] = fork();
	if (ft_init_io(&tmp, params) == -1)
		return (-1);
	if (params->pid[0] == 0)
	{
		//if (ft_prepare_to_execute(&tmp) == -1)
			//return (-1);
		//if (ft_open_io(lst, params) == -1)
			//return (-1);
		if (ft_dup_io(params) == -1)
			return (-1);
		tmp->cmd = ft_to_str(tmp->token);
		if (!tmp->cmd)
			return (-1);
		if (ft_execute(ft_split_space(tmp->cmd), env) == -1)
			return (-1);
		ft_close_total(params, &tmp);
	}
	return (0);
}

int	ft_wait_all_pid(t_node *params)
{
	int	i;
	int	status;

	i = 0;
	while (i < params->nb)
	{
		if (waitpid(params->pid[i], &status, 0) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_exec_bin(t_list **lst, char **env, t_node *params)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*lst);
	if (ft_lstsize(tmp) == 1)
	{
		if (ft_exec_one(lst, env, params) == -1)
			return (-1);
	}
	else
	{
		ft_prepare_io(&tmp, params);
		//if (ft_fill_params(params, ft_lstsize(tmp)) == -1)
			//return (-1);
		//if (ft_init_io(&tmp, params) == -1)
			//return (-1);
		//if (ft_prepare_to_execute(&tmp) == -1)
			//return (-1);
		tmp->cmd = ft_to_str(tmp->token);
		if (!tmp->cmd)
			return (-1);
	}
	return (0);
}

int	ft_main_exec(t_list **lst, char **env, t_node *params)
{
	t_list *tmp;

	tmp = (*lst);
	while (tmp)
	{
		ft_prepare_io(&tmp, params);
		if (ft_is_builtin(tmp->token[0]) == 1)
		{
			if (ft_exec_builtin(params, tmp->token, env) == -1)
				return (-1);
			else if (ft_exec_builtin(tmp->token) == -2)
				return (/*ft_quit(),*/ 0);
			tmp->is_builtin = 1;
		}
		else
		{
			if (ft_exec_bin(tmp, env, params) == -1)
				return (-1);
		}
		tmp->next;
	}
	ft_child_exec(params, lst, env);
	//ft_close_total(&params, lst);
}
