/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:21:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/06 19:08:36 by hrecolet         ###   ########.fr       */
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

int	ft_main_exec(t_list *lst, char **env)
{
	t_list	*tmp;
	(void)env;

	tmp = lst;
	while (tmp->next)
	{	
		tmp = tmp->next;
	}
	return (0);
}


