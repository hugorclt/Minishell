/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:45:28 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/17 16:51:32 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_theres_backslash(char *token)
{
	int	i;

	i = 0;
	if (!token)
		return (0);
	while (token[i] && token[i] != '=')
		++i;
	if (token[i] == '=')
		++i;
	if (token[i])
	{
		while (token[i])
		{
			if (token[i] == '$' || token[i] == '"')
				return (1);
			++i;
		}
	}
	return (0);
}

int	ft_nb_bs(char *token)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (token[i])
	{
		if (token[i] == '"' || token[i] == '$')
			nb++;
		++i;
	}
	return (nb);
}

void	ft_add_backslash(char *output, char *token, int *i, int *j)
{
	output[*j] = token[*i];
	ft_increm(i, j);
	output[*j] = '\\';
	++*j;
	if (token[*i] == '$' || token[*i] == '"')
	{

	}
}

char	*ft_backslash(char *token)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	output = malloc(sizeof(char) * (ft_strlen(token) + ft_nb_bs(token) + 1));
	if (!output)
		return (NULL);
	j = 0;
	while (token[i])
	{
		if (token[i + 1] == '$' || token[i + 1] == '"')
		{
		}
		output[j] = token[i];
		ft_increm(&i, &j);
	}
	output[j] = 0;
	return (free(token), output);
}
