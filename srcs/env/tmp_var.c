/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:40:03 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/05 19:03:04 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_count_w(char *s, int limite)
{
	int	total;
	int	i;

	i = 0;
	while (i < limite)
	{
		if (ft_isspace(s[i]) != 1)
			total++;
		while (ft_isspace(s[i]) != 1)
			++i;
		else
			++i;
	}
	return (total);
}

static int	ft_malloc_tmpvar(t_token *token, int size)
{
	if (!token->tmp_var)
	{
		token->tmp_var = malloc(sizeof(char *) * (size + 1));
		if (!token->tmp_var)
			return (-1);
	}
	else if (ft_tab_size(token->tmp_var) < size)
	{
	}
	return (0);
}

int	ft_count_tmpvar(t_token *token)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (token->token[i])
	{
		j = 0;
		while (token->token[i][j])
		{
			if (token->token[i][j] == '=')
			{
				if (ft_count_w(token->token[i], j) == 1)
				{
					count++;
					break ;
				}
			}
			++j;
		}
		++i;
	}
	return (count);
}

int	ft_parse_tmpvar(t_token *token)
{
	int	i;
	int	j;

	i = 0;
	if (ft_malloc_tmpvar(token))
	while (token->token[i])
	{
		j = 0;
		while (token->token[i][j])
		{
			if (token->token[i][j] == '=')
			{
				if (ft_count_w(token->token[i], j) == 1)
			}
		}
	}
}
