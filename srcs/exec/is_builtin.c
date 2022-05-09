/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:21:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/09 15:24:31 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd) == 0))
		return (1);
	else if (ft_strncmp(cmd, "unset", ft_strlen(cmd) == 0))
		return (1);
	else if (ft_strncmp(cmd, "env", ft_strlen(cmd) == 0))
		return (1);
	else if (ft_strncmp(cmd, "exit", ft_strlen(cmd) == 0))
		return (1);
	return (0);
}

int	ft_builtin_choice(char **cmd, char **env)
{
	if (ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])) == 0)
		ft_change_dir(cmd[1]);
	else if (ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])) == 0)
	{
		if (print_pwd() == -1)
			return (-1);
	}
	else if (ft_strncmp(cmd[0], "env", ft_strlen(cmd[0]) == 0))
		ft_print_tab(env);
	else if (ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0]) == 0))
		return (-2);
	return (1);
}




