/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:27:57 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 11:20:50 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	skip_io_filename(t_list **lst, int *i)
{
	t_list *tmp;

	tmp = (*lst);
	if (ft_strcmp(tmp->token[*i], ">") == 0
		|| ft_strcmp(tmp->token[*i], ">") == 0
		|| ft_strcmp(tmp->token[*i], ">") == 0
		|| ft_strcmp(tmp->token[*i], ">") == 0)
		(*i) += 2;
	return (0);
}

char	**ft_clean_redirection(t_list **lst)
{
	t_list	*tmp;
	int		i;
	char	**ret;

	tmp = (*lst);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_tab_size(tmp->token) - ((tmp->nb_infile + tmp->nb_outfile) * 2) + 1));
	if (!ret)
		return (NULL);
	while (tmp->token[i])
	{
		skip_io_filename(&tmp, &i);
		ret[i] = ft_strdup(tmp->token[i]);
		i++;
	}
	ret[i] = 0;
	return (free(tmp->token), ret);
}