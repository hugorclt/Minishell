/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:31:42 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/04/26 19:29:13 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_add_operator(char ***token_lst, char *cmd, int *i, int *j)
{
	if (cmd[(*j)] == '|' && *j == 0)
		return (-1);
	if (cmd[(*j) + 1] && cmd[(*j) + 1] == cmd[(*j)])
	{
		*token_lst[(*i)] = ft_substr(cmd, *j, 2);
		if (!*token_lst[(*i)])
			return (-1);
		(*i)++;
		(*j)++;
	}
	else
	{
		*token_lst[(*i)] = ft_substr(cmd, *j, 1);
		if (!*token_lst[(*i)])
			return (-1);
		(*i)++;
	}
	return (0);
}

static int	ft_init_n_malloc(t_token *token, char *cmd, int *i, int *j)
{
	token->token = malloc(sizeof(char *) * (ft_total_token(cmd) + 1));
	if (!token->token)
		return (-1);
	(*i) = 0;
	(*j) = 0;
	return (0);
}

static int	ft_add_cmd(char **token_lst, char *cmd, int *i, int *j)
{
	int start;
	int	len;

	start = *i;
	len = *j;
	(*token_lst) = ft_substr(cmd, start, len);
	if (!(*token_lst))
		return (-1);
	(*i)++; 
	return (0);
}

static void	ft_incremente(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

int	ft_sweep(char **token_lst, char *cmd, int *i, int *j)
{
	int	size;
	int	k;

	size = 0;
	k = (*j);
	while (cmd[k])
	{
		if (ft_is_quote(cmd[k]))
		{
			ft_incremente(&k, &size);
			while (!ft_is_quote(cmd[k]) && cmd[k])
				ft_incremente(&k, &size);
			if (is_operator(cmd[k] == 1))
			{
				if (ft_add_cmd(&token_lst[(*i)], cmd, j, &k - 1) == -1)
					return (-1);
				if (ft_add_operator(&token_lst, cmd, i, &k) == -1)
					return (-1);
				return (0);
			}
		}
		ft_incremente(&k, &size);
	}
	if (ft_add_cmd(&token_lst[(*i)], cmd, i, &k) == -1)
		return (-1);
	*j += k - 1;
	printf("je passe bien la\n");
	printf("i : %d\n", *i);
	printf("token_total : %d\n", ft_total_token(cmd));
	printf("token : %s\n", token_lst[(*i) - 1]);
	return (0);
}

int	ft_parse_tokens(t_token *token, char *cmd)
{
	int		i;
	int		j;

	if (ft_init_n_malloc(token, cmd, &i, &j) == -1)
		return (-1);
	while (i < ft_total_token(cmd))
	{
		while (cmd[j])
		{
			if (is_operator(cmd[j]) == 1)
			{
				if (ft_add_operator(&token->token, cmd, &i, &j) == -1)
					return (-1); //TODO return with free everything
			}
			else if (is_operator(cmd[j]) == -1)
			{
				if (ft_sweep(token->token, cmd, &i, &j) == -1)
					return (-1);
			}
			++j;
		}
	}
	token->token[i] = NULL;
	return (0);
}
