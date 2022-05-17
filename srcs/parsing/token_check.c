/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:37:01 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/17 10:08:01 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
first token can't be a | 

if first token is an operator the second can't be one too

*/
//
/*
static int	ft_theres_two_types(char *token)
{
	int	i;
	int	sgle;
	int	dble;

	i = 0;
	sgle = 0;
	dble = 0;
	while (token[i])
	{
		if (token[i] == '"')
			dble++;
		if (token[i] == '\'')
			sgle++;
		i++;
	}
	if (!(dble % 2) && !(sgle % 2) && dble && sgle)
		return (2);
	if (!(dble % 2) && !(sgle % 2) && (dble || sgle))
		return (1);
	return (0);
}

int	ft_theres_quotes(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\'' || token[i] == '"')
			return (1);
		++i;
	}
	return (0);
}

static int	ft_check_end(char *token, int *i, char c, char b)
{
	int	count;

	count = 0;
	while (token[(*i)] != c && token[(*i)])
	{
		if (token[(*i)] == b)
			count++;
		++(*i);
	}
	if (count % 2)
		return (-1);
	return (0);
}

static int	ft_check(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '"')
		{
			if (ft_check_end(token, &i, '"', '\'') == -1)
				return (-1);
		}
		else if (token[i] == '\'')
		{
			if (ft_check_end(token, &i, '\'', '"') == -1)
				return (-1);
		}
		++i;
	}
	return (0);
}*/

int	ft_check_quote(char *token)
{
	int		i;
	t_token	qt_helper;

	i = 0;
	while (token[i])
	{
		ft_quoted_expand(&qt_helper, token[i]);
		i++;
	}
	return (0);
}

/*
int	ft_check_quote(char *token)
{
	if (ft_theres_quotes(token))
	{
		if (ft_theres_two_types(token) == 2)
		{
			if (ft_check(token) == -1)
				return (-1);
		}
		else if (ft_theres_two_types(token) == 0)
			return (-1);
	}
	return (1);
}
*/
int	ft_is_operator(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return (1);
	else if (ft_strcmp(token, "<<") == 0)
		return (1);
	else if (ft_strcmp(token, ">>") == 0)
		return (1);
	else if (ft_strcmp(token, ">") == 0)
		return (1);
	else if (ft_strcmp(token, "<") == 0)
		return (1);
	else
		return (-1);
}

int	ft_check_token(t_token *token)
{
	int	i;

	i = 0;
	if (!token->token)
		return (-1);
	if (!ft_strcmp(token->token[i], "|"))
		return (ft_print_error(token->token[i]), -1);
	while (token->token[i])
	{
		if (ft_is_operator(token->token[i]) == 1 && token->token[i + 1] && 
				ft_is_operator(token->token[i + 1]) == 1)
		{
			if (!ft_strcmp(token->token[i], token->token[i + 1]))
				return (ft_print_error(token->token[i + 1]), -1);
		}
		++i;
	}
	return (1);
}
