/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:53:42 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/24 10:31:46 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

static void	ft_init_token(t_token **token)
{
	(*token)->nb_dquotes = 0;
	(*token)->nb_quotes = 0;
	(*token)->token = NULL;
}

static void	ft_count_quotes(char c, t_token **token)
{
	if (c == '"')
		(*token)->nb_dquotes++;
	if (c == '\'')
		(*token)->nb_quotes++;
}

static void	ft_add_token(t_list **lst, char *cmd, int i, t_token **token)
{
	ft_lstadd_back(lst, ft_lstnew(token));
	ft_init_token(token);
	if (cmd[i + 1] && cmd[i + 1] == cmd[i])
	{
		(*token)->token = ft_strjoin_char((*token)->token, cmd[i]);
		(*token)->token = ft_strjoin_char((*token)->token, cmd[i]);
		ft_lstadd_back(lst, ft_lstnew(token));
		i++;
	}
	else
	{
		(*token)->token = ft_strjoin_char((*token)->token, cmd[i]);
		ft_lstadd_back(lst, ft_lstnew(token));
	}
	ft_init_token(token);
}

void	ft_tokenization(t_list **lst, char *cmd)
{
	int		i;
	t_token	*token;

	i = 0;
	ft_init_token(&token);
	while (cmd[i])
	{
		ft_count_quotes(cmd[i], &token);
		if (is_operator(cmd[i]) && token->nb_dquotes % 2 == 0 &&
			token->nb_quotes % 2 == 0)
			ft_add_token(lst, cmd, i, &token);
		ft_strjoin_char(token->token, cmd[i]);
		i++;
	}	
	ft_lstadd_back(lst, ft_lstnew(token));
}
