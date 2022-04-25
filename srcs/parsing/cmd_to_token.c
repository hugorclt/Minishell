/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:53:42 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/25 10:28:17 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
static int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (-1);
}

static t_token	ft_init_token(void)
{
	t_token	token;

	token.nb_dquotes = 0;
	token.nb_quotes = 0;
	token.token = NULL;
	return (token);
}

static void	ft_count_quotes(char c, t_token *token)
{
	if (c == '"')
		token->nb_dquotes++;
	if (c == '\'')
		token->nb_quotes++;
}

static void	ft_add_token(t_list **lst, char *cmd, int *i, t_token *token)
{
//	printf("token in add token : %s\n", token->token);
	ft_lstadd_back(lst, ft_lstnew(token));
	(*token) = ft_init_token();
	if (cmd[(*i) + 1] && cmd[(*i) + 1] == cmd[(*i)])
	{
		token->token = ft_strjoin_char(token->token, cmd[(*i)]);
		token->token = ft_strjoin_char(token->token, cmd[(*i)]);
	//	printf("token in add token : %s\n", token->token);
		ft_lstadd_back(lst, ft_lstnew(token));
		(*i) += 2;
	}
	else
	{
		token->token = ft_strjoin_char(token->token, cmd[(*i)]);
	//	printf("token in add token : %s\n", token->token);
		ft_lstadd_back(lst, ft_lstnew(token));
		(*i)++;
	}
	(*token) = ft_init_token();
}

void	ft_tokenization(t_list **lst, char *cmd)
{
	int		i;
	t_token	token;

	i = 0;
	token = ft_init_token();
	while (cmd[i])
	{
		ft_count_quotes(cmd[i], &token);
		if (is_operator(cmd[i]) == 1 && token.nb_dquotes % 2 == 0
			&& token.nb_quotes % 2 == 0)
			ft_add_token(lst, cmd, &i, &token);
		token.token = ft_strjoin_char(token.token, cmd[i]);
		i++;
	}
	//printf("token in add token : %s\n", token.token);
	ft_lstadd_back(lst, ft_lstnew(&token));
}*/
