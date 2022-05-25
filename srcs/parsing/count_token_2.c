/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:13:37 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 05:14:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_sweep(char *cmd, int *i, int *total)
{
	while (cmd[(*i)])
	{
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
		if (is_operator(cmd[i]) == 1)
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