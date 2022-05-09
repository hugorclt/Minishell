/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquoting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:19:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/09 15:03:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_is_trimeable(t_token *token, char c, char *set)
{
	int			i;

	i = 0;
	(void)token;
	while (set[i])
	{
		if (c == set[i])
		{
			if (c == token->first_quotes
				|| (token->old_first_quotes && token->old_first_quotes == c))
			{
				token->old_first_quotes = c;
				return (1);
			}
			return (0);
		}
		i++;
	}
	return (0);
}

static void	ft_reset(t_token *token, char c)
{
	ft_quoted(token, c);
	if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 == 0)
		ft_reset_quotes(token);
}

char	*ft_strtrim_quoted(t_token *token, char *str, char *set)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ft_reset(token, str[i]);
		while (ft_is_trimeable(token, str[i], set) == 1)
		{
			i++;
			ft_reset(token, str[i]);
		}
		if (!str[i])
			break ;
		ret[j] = str[i];
		j++;
		i++;
	}
	ret[j] = 0;
	return (ret);
}

char	*ft_unquoting(t_token *token, char *str)
{
	char	*ret;

	ft_reset_quotes(token);
	ret = ft_strtrim_quoted(token, str, "\"'");
	if (!ret)
		return (NULL);
	ft_reset_quotes(token);
	return (ret);
}
