/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/06 17:13:57 by yuro4ka          ###   ########.fr       */
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

int	ft_test_export(t_token *token)
{
	if (token->token[0])
	{
		if (ft_strcmp(token->token[0], "export") == 0)
		{
			if (ft_export_alph(token->env) < 0)
				return (-1);
		}
	}
	return (0);
}

static int	ft_init_env(char **env, t_token *token)
{
	token->token = NULL;
	token->env = NULL;
	token->tmp_var = NULL;
	token->env = ft_dup_tab(env);
	if (!token->env)
		return (-1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_token token;
	(void)av;

	if (ac == 1)
	{
		if (ft_init_env(env, &token) < 0)
			return (1);
		using_history();
		while (1)
		{
			//signal(SIGINT, ft_sign_handle);
			cmd = readline(ft_get_last_dir(get_pwd()));
			if (!cmd)
				return (0);
			if (ft_parse_tokens(&token, cmd) == -1)
				continue ;
			if (ft_check_token(&token) == -1)
			{
				ft_free(token.token);
				continue ;
			}
			ft_print_tab(token.token);
			add_history(cmd);
		}
	}
	return (0);
}
