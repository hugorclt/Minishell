/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:33:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/26 11:29:02 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (-1);
}

static void	ft_init_token(t_token *token) {
	token->nb_dquotes = 0;
	token->nb_quotes = 0;
	token->token = NULL;
}

static void	ft_token_count(char *cmd, int *i, int *total)
{
	if (cmd[(*i) + 1] && cmd[(*i) + 1] == cmd[(*i)])
	{
		(*i)++;
		(*total)++;
		printf("je passe pour un double\n");
	}
	else
	{
		printf("je passe pour un simple operator\n");
		(*total)++;
	}
}

static int  ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

static void	ft_sweep(char *cmd, int *i, int *total)
{
	while (cmd[(*i)])
	{
		if (ft_is_quote(cmd[(*i)]))
		{
			(*i)++;
			while (!ft_is_quote(cmd[(*i)]) && cmd[(*i)])
				(*i)++;
		}
		if (is_operator(cmd[(*i)]) == 1)
			return (ft_token_count(cmd, i, total));
		(*i)++;
	}
}

int	ft_total_token(char *cmd)
{
	int		total;
	int		i;
	t_token	token;

	total = 0;
	i = 0;
	ft_init_token(&token);
	while (cmd[i])
	{
		if (is_operator(cmd[i]) == 1 )
				ft_token_count(cmd, &i, &total);
		else if (is_operator(cmd[i]) == -1)
		{
			ft_sweep(cmd, &i, &total);
//			if (cmd[i] == ' ' && cmd [i + 1])
			printf("je passe pour une commande\n");
			total++;
		}
		++i;
	}
	return (total);
}
