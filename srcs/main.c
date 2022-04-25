/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/25 20:30:40 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
void	ft_print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->content->token);
		tmp = tmp->next;
	}
}

void	ft_sign_handle(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("\n", 1);
		rl_clear_history();
	}
	else if (signo == SIGQUIT)
		return ;
}*/
int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_list	*lst;
	(void)av;
	(void)env;

	lst = malloc(sizeof(t_list));
	lst = NULL;
	(void)lst;
	if (ac == 1)
	{
		using_history();
		while (1)
		{
//			signal(SIGINT, ft_sign_handle);
			cmd = readline(ft_get_last_dir(get_pwd()));
			if (!cmd)
				return (0);
			printf("total token : %d\n", ft_total_token(cmd));
//			ft_tokenization(&lst, cmd);
			//ft_print_lst(lst);
			add_history(cmd);
		}
	}
	return (0);
}
