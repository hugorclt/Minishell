/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:21:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/26 15:09:11 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtin(char **cmd, char **env)
{
	if (ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])) == 0)
		ft_change_dir(cmd[1]);
	else if (ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])) == 0)
		print_pwd();
	else if (ft_strncmp(cmd[0], "export", ft_strlen(cmd[0]) == 0))
		ft_export(env, cmd);
	else if (ft_strncmp(cmd[0], "unset", ft_strlen(cmd[0]) == 0))
		ft_unset(env, cmd);
	else if (ft_strncmp(cmd[0], "env", ft_strlen(cmd[0]) == 0))
		ft_print_tab(env);
	else if (ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0]) == 0))
		ft_exit();
}