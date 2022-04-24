/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/24 13:48:12 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		//printf("%s\n", (char *)lst->content->token);
		lst = lst->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_list	*lst;
	(void)av;
	(void)env;

	lst = malloc(sizeof(t_list));
	lst = NULL;
	if (ac == 1)
	{
		using_history();
		while (1)
		{
			signal(SIGQUIT, SIG_IGN);
			cmd = readline(ft_get_last_dir(get_pwd()));
			ft_tokenization(&lst, cmd);
			//ft_print_lst(lst);
			add_history(cmd);
		}
	}
	return (0);
}
