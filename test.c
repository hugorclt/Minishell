/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:13:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/30 15:43:43 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_help
{
	int		i;
	int		j;
	int		k;
	int		p;
	char	c;
}	t_help;

int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !tab[0])
		return (i);
	while (tab[i])
		++i;
	return (i);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < ft_tab_size(tab))
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (c);
	return (0);
}

void	ft_pass_quote(char *cmd, int *j)
{
	char	c;

	c = ft_is_quote(cmd[(*j)]);
	(*j)++;
	while (cmd[(*j)] != c && cmd[(*j)])
		(*j)++;
	if (cmd[(*j)] && cmd[(*j)] == c)
		(*j)++;
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

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
				++i;
			}
			total++;
		}
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
//	if (cmd[i + (*j)] && cmd[i + (*j)] == c)
//		(*j)++;
}

static char	*ft_fill(char const *s, int size, int *index)
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

static char	**ft_dfill(char **output, char *cmd, char c)
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
				help.j++;
			}
			output[help.p] = ft_fill(cmd, help.j, &help.i);
			if (!output)
				return (ft_free(output), NULL);
			help.p++;
		}
		else
			help.i++;
	}
	output[help.p] = NULL;
	return (output);
}

char	**ft_split_space(char *cmd)
{
	char	**output;

	if (!cmd)
		return (NULL);
	output = malloc(sizeof(char *) *(ft_count(cmd) + 1));
	if (!output)
		return (NULL);
	return (ft_dfill(output, cmd, ' '));
}

void	ft_print_tab(char **tokens)
{
	int	i;

	i = 0;
	if (!*tokens)
		return ;
	while (tokens[i])
		printf("|%s|\n", tokens[i++]);
}

int main()
{
	ft_print_tab(ft_split_space("echo \"'\" > in"));
}
