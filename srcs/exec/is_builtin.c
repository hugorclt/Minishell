/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:21:59 by hrecolet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/12 11:47:25 by hrecolet         ###   ########.fr       */
=======
/*   Updated: 2022/05/12 11:48:33 by hrecolet         ###   ########.fr       */
>>>>>>> hugo
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

int	ft_exec_builtin(t_node *params, char **cmd, char **env)
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
		if (!ft_export(params, ft_to_str(cmd)))
			return (-1);
	}
	else if (ft_strcmp(cmd[0], "unset") == 0)
	{
		if (!ft_unset(env, cmd))
			return (-1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0)
	{
		ft_print_tab(env);
	}
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (-2);
	return (1);
}





