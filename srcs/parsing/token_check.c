/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:37:01 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/06/01 11:24:00 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_main_check(t_tok *token)
{
	int	i;

	i = 0;
	while (token[i]->tk)
	{
		if (ft_check_quote(token[i]->tk) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_quote(char *token)
{
	int		i;
	char	c;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\'' || token[i] == '"')
		{
			c = token[i];
			i++;
			while (token[i] != c)
			{
				if (!token[i])
					return (ft_print_error_c(c), -1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

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
	if (!token->token->tk)
		return (-1);
	if (!ft_strcmp(token->token[i]->tk, "|"))
		return (ft_print_error(token->token[i]->tk), -1);
	if (is_dpipe(token) < 0)
		return (ft_print_error("||"), -1);
	while (token->token[i]->tk)
	{
		if (ft_check_next(token, i) < 0)
			return (-1);
		++i;
	}
	return (1);
}
