/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 11:46:43 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_token	*var;
	t_cmd	*l_cmd;
	(void)av;
	if (ac == 1)
	{
		using_history();
		ft_init_env(&var, env);
		while (1)
		{
			ft_init_pwd(&var);
			char *cmd = readline(ft_get_last_dir(var->current_wdir));
			ft_main_parse(cmd, &l_cmd, &var);
			add_history(cmd);
		}
	}
	return (0);
}
