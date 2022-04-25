/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_token_youri.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:33:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/25 10:28:16 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	token.nb_dquotes = 0;
	token.nb_quotes = 0;
	token->token = NULL;
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
			total++;
		i++;
	}
	total++;
	return (total);
}

int	ft_tokenization(t_token *token, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_token(token);
	while (cmd[i])
	{
		ft_count_quotes(cmd[i], token);
		if (is_operator(cmd[i]) == 1 && token.nb_dquotes % 2 == 0
			&& token.nb_quotes % 2 == 0)
	}
}
