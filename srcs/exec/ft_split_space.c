/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:15:03 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/30 16:57:14 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_count(char *cmd)
{
	int		total;
	int		i;

	i = 0;
	total = 0;
	while (cmd[i])
	{
		if (!ft_isspace(cmd[i]))
		{
			while (!ft_isspace(cmd[i]) && cmd[i])
			{
				if (ft_is_quote(cmd[i]))
					ft_pass_quote(cmd, &i);
				else
					++i;
			}
			total++;
		}
		else
			++i;
	}
	return (total);
}

static void	ft_pass_quote_sp(char *cmd, int i, int *j)
{
	char	c;

	c = ft_is_quote(cmd[i + (*j)]);
	(*j)++;
	while (cmd[i + (*j)] != c && cmd[i + (*j)])
		(*j)++;
}

static char	*ft_fill(char *s, int size, int *index)
{
	char	*output;
	int		i;

	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = s[*index];
		i++;
		*index += 1;
	}
	printf("help : %d\n", *index);
	output[i] = 0;
	return (output);
}

static char	**ft_dfill(char ***output, char *cmd, char c)
{
	t_help	help;

	help.i = 0;
	help.p = 0;
	while (cmd[help.i])
	{
		if (cmd[help.i] != c)
		{
			help.j = 0;
			while (cmd[help.i + help.j] != c && cmd[help.i + help.j])
			{
				if (ft_is_quote(cmd[help.i + help.j]))
					ft_pass_quote_sp(cmd, help.i, &help.j);
				++help.j;
			}
			(*output)[help.p] = ft_fill(cmd, help.j, &help.i);
			if (!(*output))
				return (ft_free((*output)), NULL);
			help.p++;
		}
		else
			help.i++;
	}
	(*output)[help.p] = NULL;
	return ((*output));
}

char	**ft_split_space(char *cmd)
{
	char	**output;

	if (!cmd)
		return (NULL);
	output = malloc(sizeof(char *) *(ft_count(cmd) + 1));
	if (!output)
		return (NULL);
	return (free(cmd), ft_dfill(&output, cmd, ' '));
}
