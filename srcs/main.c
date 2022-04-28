/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/28 16:35:12 by hrecolet         ###   ########.fr       */
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
void	ft_print_tab(char **tokens)
{
	int	i;

	i = 0;
	if (!*tokens)
		return ;
	while (tokens[i])
		printf("%s\n", tokens[i++]);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_list	*lst;
	t_token token;
	(void)av;
	(void)env;

	lst = malloc(sizeof(t_list));
	lst = NULL;
	(void)lst;
	token.token = NULL;
	if (ac == 1)
	{
		using_history();
		while (1)
		{
			//signal(SIGINT, ft_sign_handle);
			cmd = readline(ft_get_last_dir(get_pwd()));
			if (!cmd)
				return (0);
			//printf("total token : %d\n", ft_total_token(cmd));
			if (ft_parse_tokens(&token, cmd) == -1)
				continue ;
			if (ft_check_token(&token) == -1)
			{
				ft_free(token.token);
				continue ;
			}
			token.nb_dquotes = 0;
			token.nb_quotes = 0;
			ft_expand_var(&token, env);
			ft_print_tab(token.token);
			add_history(cmd);
		}
	}
	return (0);
}
