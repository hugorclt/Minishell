/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:21:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/27 15:42:14 by hrecolet         ###   ########.fr       */
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
	{
		if (print_pwd() == -1)
			return (-1);
	}
	/*else if (ft_strncmp(cmd[0], "export", ft_strlen(cmd[0]) == 0))
	{
		//remplacer env par le retour de export main !
		//t_(NOM DE LA STRUCT)->env = ft_export_main(env, cmd);
		//if (!t_(NOM_STRUCT)->env)
		//	return (-1);
		if (!ft_export_main(env, cmd))
			return (-1);
	}
	else if (ft_strncmp(cmd[0], "unset", ft_strlen(cmd[0]) == 0))
	{
		//remplacer env par le retour ft_unset !
		//t_(NOM DE LA STRUC)->env = ft_unset(env, cmd);
		//if (!t_(NOM_STRUCT)->env)
		//	return (-1);
		if (!ft_unset(env, cmd))
			return (-1);
	}*/
	else if (ft_strncmp(cmd[0], "env", ft_strlen(cmd[0]) == 0))
		ft_print_tab(env);
	else if (ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0]) == 0))
		return (-2);
	return (1);
}