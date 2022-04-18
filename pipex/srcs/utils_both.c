/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:58:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/10 16:22:13 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

int	ft_child_exec(t_node *params, char **av, char **envp)
{
	int	i;

	i = 2;
	params->index = 0;
	if (params->heredoc)
		i = 3;
	while (params->index < params->nb)
	{
		if (ft_fork(params, envp, av[i]) < 0)
		{
			ft_close();
			ft_free_struct(params);
			return (-1);
		}
		params->index++;
		i++;
	}
	return (1);
}
