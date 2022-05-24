/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:33:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/25 01:16:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (-1);
}

static void	ft_token_count(char *cmd, int *i, int *total)
{
	if (cmd[(*i) + 1] && cmd[(*i) + 1] == cmd[(*i)])
	{
		(*i)++;
		(*total)++;
	}
	else
		(*total)++;
	(*i)++;
	while (ft_isspace(cmd[(*i)]) && cmd[(*i)])
		(*i)++;
	(*i)--;
}

int  ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

static void	ft_sweep(char *cmd, int *i, int *total)
{
	while (cmd[(*i)])
	{
		printf("%c\n", cmd[*i]);
		if (ft_is_quote(cmd[(*i)]))
		{
			(*i)++;
			while (!ft_is_quote(cmd[(*i)]) && cmd[(*i)])
				(*i)++;
			(*i)--;
		}
		if (is_operator(cmd[(*i)]) == 1)
			return (ft_token_count(cmd, i, total));
		(*i)++;
	}
}

int	ft_total_token(char *cmd)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (i < ft_strlen(cmd))
	{
		if (ft_isspace(cmd[i]) == 1)
		{
			while (ft_isspace(cmd[i]))
				++i;
		}
		if (is_operator(cmd[i]) == 1 )
			ft_token_count(cmd, &i, &total);
		else if (is_operator(cmd[i]) == -1)
		{
			ft_sweep(cmd, &i, &total);
			total++;
		}
		++i;
	}
	return (total);
}
