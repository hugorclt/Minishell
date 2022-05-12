/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:27:57 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 11:48:14 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	skip_io_filename(t_list **lst, int *i)
{
	t_list *tmp;

	tmp = (*lst);
	if (ft_strcmp(tmp->token[*i], ">") == 0
		|| ft_strcmp(tmp->token[*i], ">>") == 0
		|| ft_strcmp(tmp->token[*i], "<") == 0
		|| ft_strcmp(tmp->token[*i], "<<") == 0)
		(*i) += 2;
	return (0);
}

static int	is_redirect(t_list **lst, int *i)
{
	t_list *tmp;

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
	t_list	*tmp;
	int		i;
	char	**ret;
	int		j;

	tmp = (*lst);
	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * (ft_tab_size(tmp->token) - ((tmp->nb_infile + tmp->nb_outfile) * 2) + 1));
	if (!ret)
		return (NULL);
	while (tmp->token[i])
	{
		skip_io_filename(&tmp, &i);
		if (!tmp->token[i])
			break;
		if (is_redirect(&tmp, &i) == 0)
		{
			ret[j] = ft_strdup(tmp->token[i]);
			j++;
		}
		i++;
	}
	ret[j] = 0;
	return (free(tmp->token), ret);
}
