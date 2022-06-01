/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:26:48 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/01 11:40:13 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_free_t(t_tok *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i]->tk)
		{
			free(token[i]->tk);
			token[i]->tk = NULL;
		}
		if (token[i]->before_expand)
		{
			free(token[i]->before_expand);
			token[i]->tk = NULL;
		}
		++i;
	}
}

char	**ft_tab_exec(t_tok *token)
{
	int		i;
	char	*output;

	i = 0;
	outp
	while (token[i]->tk)
	{

	}
}
