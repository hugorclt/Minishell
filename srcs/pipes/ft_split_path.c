/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:49:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/26 17:22:15 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_count(char const *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			size++;
		}
		else
			i++;
	}
	return (size);
}

static char	*ft_fill(char const *s, int size, int *index)
{
	char	*output;
	int		i;

	output = malloc(sizeof(char) * (size + 2));
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = s[*index];
		i++;
		*index += 1;
	}
	output[i] = '/';
	output[i + 1] = 0;
	return (output);
}

static char	**ft_dfill(char **output, char const *s, char c)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			output[p] = ft_fill(s, j, &i);
			if (!output[p])
				return (ft_free(output), NULL);
			p++;
		}
		else
			i++;
	}
	output[p] = NULL;
	return (output);
}

char	**ft_split_path(char const *s, char c)
{
	char	**output;

	if (!s)
		return (NULL);
	printf("%s\n", s);
	output = malloc(sizeof(char *) * ((ft_count(s, c) + 1)));
	if (!output)
		return (NULL);
	return (ft_dfill(output, s, c));
}
