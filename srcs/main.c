/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 10:41:04 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_lst(t_list *lst)
 {
 	t_list	*tmp;
 	int		i;

 	tmp = lst;
 	while (tmp)
 	{
 		i = 0;
 		while (tmp->token[i])
 		{
 			printf("%s", tmp->token[i]);
 			i++;
 		}
 		printf("\n");
 		tmp = tmp->next;
 	}
 }
/*
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
		printf("%st\n", tokens[i++]);
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

static int	ft_init_env(char **env, t_node *params)
{
	params->env = ft_dup_tab(env);
	if (!params->env)
		return (-1);
	return (0);
}

static int	ft_exec_parsing(t_token *token, char *cmd)
{
	if (ft_parse_tokens(token, cmd) == -1)
		return (ft_free(token->token), -1);
	if (ft_check_token(token) == -1)
		return (ft_free(token->token), -1);
	if (ft_expand_var(token, token->env) == -1)
		return (ft_free(token->token), -1);
	return (0);
}
/*
static int check_export(t_token *token)
{
	if (ft_export(&token, token->token[0]) < 0)
		return (-1);
	return (0);
}

static void	ft_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_check_equal(env[i]))
			printf("%s\n", env[i]);
		++i;
	}
}
*/
int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_token token;
	t_list	*lst;
	t_node	params;
	(void)av;

	token.token = NULL;
	lst = NULL;
	if (ac == 1)
	{
		if (ft_init_env(env, &params) < 0)
			return (1);
		using_history();
		while (1)
		{
			//signal(SIGINT, ft_sign_handle);
			cmd = readline(ft_get_last_dir(get_pwd()));
			if (!cmd)
				return (free(cmd), 1);
			if (cmd[1] == '\0')
			{
				free(cmd);
				continue ;
			}
			if (ft_exec_parsing(&token, cmd) == -1)
				return (free(cmd), 1);
			//ft_print_tab(token.token);
			lst = init_lst(&token);
			if (!lst)
				return (free(cmd), 1);
			//ft_print_lst(lst);
			ft_main_exec(&params, &lst);
			//if (ft_wait_all_pid(&params, &lst) == -1)
			//	return (-1);
			rl_on_new_line();
			rl_redisplay();
			//token.token[0] = ft_unquoting(&token, token.token[0]);
			add_history(cmd);

		}
	}
	return (0);
}
