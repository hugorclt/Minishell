/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:31:42 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/04/27 13:06:48 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_init_n_malloc(t_token *token, char *cmd, int *i, int *j)
{
	token->token = malloc(sizeof(char *) * (ft_total_token(cmd) + 1));
	if (!token->token)
		return (-1);
	(*i) = 0;
	(*j) = 0;
	return (0);
}

static int	ft_dup_token(t_token *token, char *cmd, int *i, int *j)
{
	int	new_j;

	new_j = (*j);
	while (cmd[new_j])
	{
		if (ft_is_quote(cmd[new_j]) == 1)
		{
			printf("pas ici non plus\n");
			new_j++;
			while (ft_is_quote(cmd[new_j]) != 1)
				new_j++;
		}
		if (is_operator(cmd[new_j]) == 1)
		{
			printf("pas ici\n");
			token->token[(*i)] = ft_substr(cmd, *j - 1, new_j - (*j) - 1);
			if (!token->token[(*i)])
				return (-1);
			(*i)++;
			(*j) += new_j - 1;
			return (0);
		}
		new_j++;
	}
	token->token[(*i)] = ft_substr(cmd, *j, new_j - (*j));
	if (!token->token[(*i)])
		return (-1);
	(*i)++;
	(*j) += new_j;
	return (0);
}

static int	ft_get_operator(t_token *token, char *cmd, int *i, int *j)
{
	if (cmd[(*j) + 1] && cmd[(*j + 1)] ==  cmd[(*j)])
	{
		token->token[(*i)] = ft_substr(cmd, *j, 2);
		if (!token->token[(*i)])
			return (-1);
		(*i)++;
		(*j) += 2;
	}
	else
	{
		token->token[(*i)] = ft_substr(cmd, *j, 1);
		if (!token->token[(*i)])
			return (-1);
		(*i)++;
		(*j)++;
	}
	return (0);
}

int	ft_parse_tokens(t_token *token, char *cmd)
{
	int		i;
	int		j;

	if (ft_init_n_malloc(token, cmd, &i, &j) == -1)
		return (-1);
	while (cmd[j])
	{
		if (is_operator(cmd[j]) == 1)
		{
			if (ft_get_operator(token, cmd, &i, &j) == -1)
				return (-1);
		}
		else
		{
			if (ft_dup_token(token, cmd, &i, &j) == -1)
				return (-1);
		}
	}
	token->token[i] = NULL;
	return (0);
}
