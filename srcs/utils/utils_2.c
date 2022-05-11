/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:19:51 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/11 14:27:59 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_reset_quotes(t_token *token)
{
	token->nb_dquotes = 0;
	token->nb_quotes = 0;
	token->old_first_quotes = 0;
}

void	ft_pass_space_reverse(char *cmd, int *new_j)
{
	if (cmd[(*new_j) - 1] && cmd[(*new_j) - 1] == ' ')
	{
		(*new_j)--;
		if (cmd[*new_j] && cmd[*new_j] == ' ')
		{
			while (cmd[*new_j] == ' ')
				(*new_j)--;
			(*new_j)++;
		}
	}
}

char	*ft_to_str(char **str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strdup("\0");
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret = ft_strjoin_pimp(ret, str[i]);
		if (!ret)
			return (NULL);
		ret = ft_strjoin_pimp(ret, " ");
		if (!ret)
			return (NULL);
		i++;
	}
	return (ft_free(str), ret);
}

void	ft_increm(int *i, int *j)
{
	(*i)++;
	(*j)++;
}
