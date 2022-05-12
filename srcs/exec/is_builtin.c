/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:21:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 15:42:46 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	ft_exec_builtin(t_node *params, char **cmd)
{
	if (ft_strcmp(cmd[0], "cd") == 0)
		ft_change_dir(cmd[1]);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
	{
		if (print_pwd() == -1)
			return (-1);	
	}
	else if (ft_strcmp(cmd[0], "export") == 0)
	{
		if (ft_export(params, ft_to_str(cmd)) == -1)
			return (-1);
	}
	else if (ft_strcmp(cmd[0], "unset") == 0)
	{
		params->env = ft_unset(params->env, cmd);
		if (!params->env)
			return (-1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_print_env(params->env);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (-2);
	return (1);
}





