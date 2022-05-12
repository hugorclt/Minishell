/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 14:17:30 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_prepare_file(t_list **lst)
{
	t_list *tmp;

	tmp = (*lst);
	ft_count_in(tmp->token, &tmp);
	ft_count_out(tmp->token, &tmp);
	tmp->file_in = malloc(sizeof(t_files) * tmp->nb_infile);
	tmp->file_out = malloc(sizeof(t_files) * tmp->nb_outfile);
	if (!tmp->file_in || !tmp->file_out)
		return (-1);
	return (0);
}

static int	ft_save_out(t_list **lst, int *i, int *j)
{
	if (ft_strcmp((*lst)->token[*i], ">") == 0)
	{
		(*lst)->file_out[*j].file = ft_strdup((*lst)->token[(*i) + 1]);
		if (!(*lst)->file_out[*j].file)
			return (-1);
		(*lst)->file_out[*j].flag = 0;
		(*j)++;
	}
	if (ft_strcmp((*lst)->token[*i], ">>") == 0)
	{
		(*lst)->file_out[*j].file = ft_strdup((*lst)->token[(*i) + 1]);
		if (!(*lst)->file_out[*j].file)
			return (-1);
		(*lst)->file_out[*j].flag = 1;
		(*j)++;
	}
	return (0);
}

static int	ft_save_in(t_list **lst, int *i, int *j)
{
	if (ft_strcmp((*lst)->token[*i], "<") == 0)
	{
		(*lst)->file_in[*j].file = ft_strdup((*lst)->token[(*i) + 1]);
		if (!(*lst)->file_in[*j].file)
			return (-1);
		(*lst)->file_in[*j].flag = 0;
		(*j)++;
	}
	if (ft_strcmp((*lst)->token[*i], "<<") == 0)
	{
		(*lst)->file_in[*j].file = ft_strdup((*lst)->token[(*i) + 1]);
		if (!(*lst)->file_in[*j].file)
			return (-1);
		(*lst)->file_in[*j].flag = 1;
		(*j)++;
	}
	return (0);
}

int	ft_save_file(t_list **lst)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (ft_prepare_file(lst))
		return (-1);
	while ((*lst)->token[i])
	{
		if (ft_save_in(lst, &i, &j) == -1)
			return (-1);
		if (ft_save_out(lst, &i, &k) == -1)
			return (-1);
		i++;	
	}
	return (0);
}
