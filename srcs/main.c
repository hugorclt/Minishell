/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/05 19:02:14 by hrecolet         ###   ########.fr       */
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

static int	ft_exec_parsing(t_token *token, char *cmd, char **env)
{
	if (ft_parse_tokens(token, cmd) == -1)
		return (ft_free(token->token), -1);
	if (ft_check_token(token) == -1)
		return (ft_free(token->token), -1);
	if (ft_expand_var(token, env) == -1)
		return (ft_free(token->token), -1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_token token;
	(void)av;

	token.token = NULL;
	if (ac == 1)
	{
		using_history();
		while (1)
		{
			//signal(SIGINT, ft_sign_handle);
			cmd = readline(ft_get_last_dir(get_pwd()));
			if (!cmd)
				return (free(cmd), 1);
			if (ft_exec_parsing(&token, cmd, env) == -1)
				return (free(cmd), 1);
			//token.token = ft_split_space(&token, token.token[0], ' ');
			//token.token[0] = ft_unquoting(&token, token.token[0]);
			ft_print_tab(token.token);
			add_history(cmd);
		}
	}
	return (0);
}
