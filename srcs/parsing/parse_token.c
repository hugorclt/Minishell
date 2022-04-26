/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:31:42 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/04/26 16:09:22 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_add_operator(char **token_lst, char *cmd, int *i, int *j)
{
	if (cmd[(*j) + 1] && cmd[(*j) + 1] == cmd[(*j)])
	{
		token_lst[(*i)] = ft_substr(cmd, *j, 2);
		if (!token_lst[(*i)])
			return (-1);
		(*j)++;
	}
	else
	{
		token_lst[(*i)] = ft_substr(cmd, *j, 1);
		if (!token_lst[(*i)])
			return (-1);
	}
	return (0);
}

static int	ft_init_n_malloc(char **token_lst, char *cmd, int *i, int *j)
{
	token_lst = malloc(sizeof(char *) * (ft_total_token(cmd) + 1));
	if (!token_lst)
		return (-1);
	(*i) = 0;
	(*j) = 0;
	return (0);
}

static int	ft_add_cmd(char **token_lst, char *cmd, int *i, int *j)
{
	
}

static void	ft_incremente(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

static int	ft_sweep(char **token_lst, char *cmd, int *i, int *j)
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
		}
		else if (is_operator(cmd[k] == 1))
		{
			if (ft_add_operator(token_lst, cmd, i, &k) == -1)
				return (-1);
			return ();
		}
	}
}

int	ft_parse_tokens(t_token *token, char *cmd)
{
	char	*token_char;
	int		i;
	int		j;

	if (ft_init_n_malloc(token->token, cmd, &i, &j) == -1)
		return (-1);
	while (i < ft_total_token(cmd))
	{
		while (cmd[j])
		{
			if (is_operator(cmd[j]) == 1)
			{
				if (ft_add_operator(token->token, cmd, &i, &j) == -1)
					return (-1); //TODO return with free everything
				++i;
			}
			else if (is_operator(cmd[j]) == -1)
			{
			}
		}
	}
}
