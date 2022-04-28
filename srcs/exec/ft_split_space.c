/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:15:03 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/28 21:28:09 by hrecolet         ###   ########.fr       */
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
<<<<<<< HEAD

static int	ft_strlen_split_space(char *cmd, t_token *token)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i] && cmd[i] != ' ' && token->nb_dquotes % 2 != 0 && token->nb_quotes % 2 != 0)
	{
		ft_quoted(token);
		i++;
	}
	return (i);
}

static char	*ft_dfill(t_token *token, char *cmd, char c)
{
	
}

char	**ft_split_space(t_token *token, char *cmd, char c)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * ft_count(token, cmd, c));
	while (i < ft_count(token, cmd, c))
	{
		ft_reset_quotes(token);
		ret[i] = ft_dfill(token, cmd, c);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
=======
>>>>>>> hugo
