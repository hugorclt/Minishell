/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:10:41 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/16 16:42:46 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_expand_ext(char **ret, char *token, int *i)
{
	(*ret) = ft_strjoin_char((*ret), token[*i]);
	if (!(*ret))
		return (-1);
	(*i)++;
	return (0);
}

static int	ft_expand_line(char *token, char **ret, int *i, t_node *par)
{
	if (token[*i] == '$')
	{
		if (token[(*i) + 1] == '?')
		{
			if (ft_expand_utils(ret, par, i) == -1)
				return (-1);
		}
		else
		{
			if (ft_expand_utils_2(ret, token, i, par) < 0)
				return (-1);
		}
	}
	else
	{
		if (ft_expand_ext(ret, token, i) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_expand_1(char **ret, char *token, t_node *par)
{
	int	i;

	i = 0;
	(*ret) = NULL;
	while (token[i])
	{
		if (ft_expand_line(token, ret, &i, par) == -1)
			return (-1);
	}
	return (0);
}

static void	ft_quoted_expand(t_token *token, char c)
{
	if (c == '\'')
		token->nb_quotes++;
	else if (c == '"')
		token->nb_dquotes++;
	if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 != 0)
		token->first_quotes = '\'';
	else if (token->nb_dquotes % 2 != 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = '"';
	else if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = ' ';
}

int	ft_quote_expand(t_token *token, char **ret, t_node *params, char *cmd)
{
	if ((token->nb_dquotes == 0 && token->nb_quotes == 0)
		|| (token->nb_dquotes % 2 != 0 && token->first_quotes == '"'))
	{
		if (ft_expand_1(ret, cmd, params) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_verif_dollars(char **ret, char *cmd, t_node *params)
{
	int		i;
	t_token	token;
	int		flag;

	i = 0;
	flag = 0;
	ft_reset_quotes(&token);
	while (cmd[i])
	{
		ft_quoted_expand(&token, cmd[i]);
		if (cmd[i] == '$')
		{
			flag = ft_quote_expand(&token, ret, params, cmd);
			if (flag == -1)
				return (-1);
		}
		i++;
	}
	if (flag == 0)
	{
		(*ret) = ft_strdup(cmd);
		if (!(*ret))
			return (-1);
	}
	return (0);
}

char	**ft_expand(t_token *token, t_node *params)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc(sizeof(char *) * (ft_tab_size(token->token) + 1));
	if (!ret)
		return (NULL);
	while (token->token[i])
	{
		if (ft_verif_dollars(&ret[i], token->token[i], params) == -1)
			return (NULL);
		i++;
	}
	ret[i] = NULL;
	return (ft_free(token->token), ret);
}
