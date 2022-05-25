/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:27:57 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 05:43:32 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	skip_io_filename(t_list **lst, int *i)
{
	t_list	*tmp;

	tmp = (*lst);
	if (ft_strcmp(tmp->token[*i], ">") == 0
		|| ft_strcmp(tmp->token[*i], ">>") == 0
		|| ft_strcmp(tmp->token[*i], "<") == 0
		|| ft_strcmp(tmp->token[*i], "<<") == 0)
		(*i) += 2;
	return (0);
}

int	is_redirect(t_list **lst, int *i)
{
	t_list	*tmp;

	tmp = (*lst);
	if (ft_strcmp(tmp->token[*i], ">") == 0
		|| ft_strcmp(tmp->token[*i], ">>") == 0
		|| ft_strcmp(tmp->token[*i], "<") == 0
		|| ft_strcmp(tmp->token[*i], "<<") == 0)
		return (1);
	return (0);
}

char	**ft_clean_redirection(t_list **lst)
{
	int		i;
	char	**ret;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * (ft_tab_size((*lst)->token)
				- (((*lst)->nb_infile + (*lst)->nb_outfile) * 2) + 1));
	if (!ret)
		return (NULL);
	while ((*lst)->token[i])
	{
		skip_io_filename(lst, &i);
		if (!(*lst)->token[i])
			break ;
		if (is_redirect(&(*lst), &i) == 0)
		{
			ret[j] = ft_strdup((*lst)->token[i]);
			ft_increm(&i, &j);
		}
		else
			i += 2;
	}
	ret[j] = 0;
	return (ft_free((*lst)->token), ret);
}
