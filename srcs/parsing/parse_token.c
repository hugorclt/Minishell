/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:31:42 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/09 13:27:36 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_init_n_malloc(t_token *token, char *cmd, int *i, int *j)
{
	if (ft_total_token(cmd) == -1)
		return (-1);
	token->token = malloc(sizeof(char *) * (ft_total_token(cmd) + 1));
	if (!token->token)
		return (-1);
	(*i) = 0;
	(*j) = 0;
	return (0);
}

static void	ft_pass_quote(char *cmd, int *j)
{
	(*j)++;
	while (ft_is_quote(cmd[(*j)]) != 1 && cmd[(*j)])
		(*j)++;
}

static int	ft_dup_token(t_token *token, char *cmd, int *i, int *j)
{
	int	new_j;

	new_j = (*j);
	while (cmd[new_j])
	{
		if (ft_is_quote(cmd[new_j]) == 1)
			ft_pass_quote(cmd, &new_j);
		if (is_operator(cmd[new_j]) == 1 && cmd[new_j])
		{
			token->token[(*i)] = ft_substr(cmd, *j, new_j - (*j));
			if (!token->token[(*i)])
				return (-1);
			(*i)++;
			(*j) += new_j - (*j);
			return (0);
		}
		new_j++;
	}
	token->token[(*i)] = ft_substr(cmd, *j, new_j - (*j));
	if (!token->token[(*i)])
		return (-1);
	(*i)++;
	(*j) += new_j - (*j);
	return (0);
}

static void	ft_pass_space(char *cmd, int *j)
{
	while (ft_isspace(cmd[(*j)]) == 1 && cmd[(*j)])
		(*j)++;
}

static int	ft_get_operator(t_token *token, char *cmd, int *i, int *j)
{
	if (cmd[(*j) + 1] && cmd[(*j + 1)] ==  cmd[(*j)])
	{
		token->token[(*i)] = ft_substr(cmd, *j, 2);
		token->token[(*i)] = ft_strjoin_pimp(token->token[*i], " ");
		if (!token->token[(*i)])
			return (-1);
		(*i)++;
		(*j) += 2;
	}
	else
	{
		token->token[(*i)] = ft_substr(cmd, *j, 1);
		token->token[(*i)] = ft_strjoin_pimp(token->token[*i], " ");
		if (!token->token[(*i)])
			return (-1);
		(*i)++;
		(*j)++;
	}
	ft_pass_space(cmd, j);
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
		if (ft_isspace(cmd[j]) == 1)
			ft_pass_space(cmd, &j);
		if (is_operator(cmd[j]) == 1)
		{
			if (ft_get_operator(token, cmd, &i, &j) == -1)
				return (-1);
		}
		else if (is_operator(cmd[j]) != 1 && ft_isspace(cmd[j]) != 1)
		{
			if (ft_dup_token(token, cmd, &i, &j) == -1)
				return (-1);
		}
	}
	token->token[i] = NULL;
	return (0);
}
