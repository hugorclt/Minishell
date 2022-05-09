/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:58:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/09 14:58:46 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_init_pid(t_node *params)
{
	params->pid = malloc(sizeof(pid_t) * params->nb);
	if (!params->pid)
		return (-1);
	return (1);
}

int	ft_norme(t_node *params, char **av, int ac, int j)
{
	char	**tmp;
	int		i;

	i = 0;
	while (i < ac - 3 - params->heredoc)
	{
		if (!av[j])
		{
			params->cmd[i] = NULL;
			return (-1);
		}
		tmp = ft_split(av[j], ' ');
		if (!tmp)
			return (-1);
		params->cmd[i] = ft_strdup(tmp[0]);
		if (!params->cmd[i])
			return (ft_free(tmp), -1);
		ft_free(tmp);
		++i;
		++j;
	}
	params->cmd[i] = NULL;
	return (1);
}

int	ft_fill_cmd_name(t_node *params, char **av, int ac)
{
	int		j;

	j = 2;
	if (params->heredoc)
		j = 3;
	params->cmd = malloc(sizeof(char *) * ((ac - 3 - params->heredoc) + 1));
	if (!params->cmd)
		return (-1);
	if (ft_norme(params, av, ac, j) < 0)
		return (-1);
	return (1);
}

int	ft_init_in_file(t_node *params, t_list *lst)
{
	int	i;

	i = 0;
	if (lst->nb_infile == 0)
	{
		params->infile = 0;
		return (0);
	}
	while (i < lst->nb_infile)
	{
		//if (params->infile_name)
		//	free(params->infile_name);
		params->infile_name = ft_strdup(lst->infile_name[i]);
		if (!params->infile_name)
			return (-1);
		params->infile = open(params->infile_name, O_RDONLY, 0644);
		if (params->infile < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_init_out_file(t_node *params, t_list *lst)
{
	int	i;

	i = 0;
	if (lst->nb_outfile == 0)
	{
		params->outfile = 1;
		return (0);
	}
	while (i < lst->nb_outfile)
	{
		//if (params->outfile_name)
		//	free(params->outfile_name);
		params->outfile_name = ft_strdup(lst->outfile_name[i]);
		if (!params->infile_name)
			return (-1);
		params->outfile = open(params->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (params->outfile < 0)
			return (-1);
		i++;
	}
	return (0);
}
	

int	ft_open_io(t_node *params, t_list *lst)
{
	if (ft_init_in_file(params, lst) == -1)
		return (-1);
	if (ft_init_out_file(params, lst) == -1)
		return (-1);
	return (0);
}

void	ft_free_io(t_node *params)
{
	free(params->outfile_name);
	free(params->infile_name);
}

int	ft_child_exec(t_node *params, t_list **lst, char **envp)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*lst);
	params->index = 0;
	//if (params->heredoc)
	//	i = 0;
	while (params->index < params->nb)
	{
		if (ft_open_io(params, tmp) == -1)
			return (-1);
		printf("%d, %s\n", params->outfile, tmp->token);
		if (ft_fork(params, envp, tmp->token) < 0)
		{
			ft_close();
			ft_free_struct(params);
			return (-1);
		}
		tmp = tmp->next;
		params->index++;
		i++;
	}
	return (1);
}