/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/23 21:38:17 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_list	*lst;
	(void)av;
	(void)env;

	if (ac == 1)
	{
		using_history();
		while (1)
		{
			cmd = readline(ft_get_last_dir(get_pwd()));
			ft_tokenization(&lst, cmd);
			//printf("%s\n", (char *)lst->content->token->token);
			add_history(cmd);
		}
	}
	return (0);
}
