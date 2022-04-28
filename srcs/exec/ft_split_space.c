/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:15:03 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/28 17:24:34 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_quoted(t_token *token, char c)
{
	if (c == '\'')
		token->nb_quotes++;
	else if (c == '"')
		token->nb_dquotes++;
	if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 != 0)
		token->first_quotes = '\'';
	else if (token->nb_dquotes % 2 != 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = '"';
}

static int	ft_count(t_token *token, char *cmd, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		ft_quoted(token, cmd[i]);
		if (cmd[i] != c)
		{
			while (cmd[i] && cmd[i] != c)
			{
				i++;
				ft_quoted(token, cmd[i]);
			}
			if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 == 0)
				count++;
		}
		else
			i++;
	}
	return (count);
}
