/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/25 10:28:16 by yobougre         ###   ########.fr       */
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

static int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (-1);
}

static void	ft_count_quotes(char c, t_token *token)
{
	if (c == '"')
		token->nb_dquotes++;
	if (c == '\'')
		token->nb_quotes++;
}

static void	ft_init_token(t_token *token)
{
	token->nb_dquotes = 0;
	token->nb_quotes = 0;
	token->token = NULL;
}

static void	ft_token_count(char *cmd, int *i, int *total)
{
	if (cmd[(*i) + 1] && cmd[(*i) + 1] == cmd[(*i)])
	{
		(*i) += 2;
		(*total)++;
	}
	else
	{
		(*i)++;
		(*total)++;
	}
}

static int	ft_total_token(char *cmd)
{
	int		total;
	int		i;
	t_token	token;

	total = 0;
	i = 0;
	ft_init_token(&token);
	while (cmd[i])
	{
		ft_count_quotes(cmd[i], &token);
		if (is_operator(cmd[i]) == 1 && token.nb_dquotes % 2 == 0
			&& token.nb_quotes % 2 == 0)
			ft_token_count(cmd, &i, &total);
		i++;
	}
	total++;
	return (total);
}

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
