/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:15:03 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/06 19:22:34 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_quoted(t_token *token, char c)
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

static int	is_quoted(char *cmd, int i)
{
	int	j;
	int	count_d;
	int	count;

	count_d = 0;
	count = 0;
	j = 0;
	if (!cmd)
		return (0);
	while (j < i)
	{
		if (cmd[j] == '"')
			count_d++;
		else if (cmd[j] == '\'')
			count++;
		j++;
	}
	if (count_d % 2 != 0 || count % 2 != 0)
		return (1);
	else
		return (0);
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
	output[i] = '\0';
	return (output);
}

static char	**ft_dfill(char **output, char *s, char c)
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
			while ((s[i + j] && s[i + j] != c) || (s[i + j] == c && is_quoted(s, i + j) == 1))
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

char	**ft_split_space(char *cmd)
{
	char	**ret;
	t_token	token;

	ft_reset_quotes(&token);
	ret = malloc(sizeof(char *) * ft_count(&token, cmd, ' ') + 10);
	ft_reset_quotes(&token);
	if (!ret)
		return (NULL);
	ft_reset_quotes(&token);
	return (ft_dfill(ret, cmd, ' '));
}
