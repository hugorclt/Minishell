/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/12 11:02:48 by hrecolet         ###   ########.fr       */
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
	t_list *tmp;

	tmp = (*lst);
	if (ft_strcmp(tmp->token[*i], ">") == 0)
	{
		tmp->file_out[*j].file = ft_strdup(tmp->token[(*i) + 1]);
		if (!tmp->file_out[*j].file)
			return (-1);
		tmp->file_out[*j].flag = 0;
		(*j)++;
	}
	if (ft_strcmp(tmp->token[*i], ">>") == 0)
	{
		tmp->file_out[*j].file = ft_strdup(tmp->token[(*i) + 1]);
		if (!tmp->file_out[*j].file)
			return (-1);
		tmp->file_out[*j].flag = 1;
		(*j)++;
	}
	return (0);
}

static int	ft_save_in(t_list **lst, int *i, int *j)
{
	t_list *tmp;

	tmp = (*lst);
	if (ft_strcmp(tmp->token[*i], "<") == 0)
	{
		tmp->file_in[*j].file = ft_strdup(tmp->token[(*i) + 1]);
		if (!tmp->file_in[*j].file)
			return (-1);
		tmp->file_in[*j].flag = 0;
		(*j)++;
	}
	if (ft_strcmp(tmp->token[*i], "<<") == 0)
	{
		tmp->file_in[*j].file = ft_strdup(tmp->token[(*i) + 1]);
		if (!tmp->file_in[*j].file)
			return (-1);
		tmp->file_in[*j].flag = 1;
		(*j)++;
	}
	return (0);
}

int	ft_save_file(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tmp = (*lst);
	if (ft_prepare_file(&tmp))
		return (-1);
	while (tmp->token[i])
	{
		if (ft_prepare_file(&tmp) == -1)
			return (-1);
		if (ft_save_in(&tmp, &i, &j) == -1)
			return (-1);
		if (ft_save_out(&tmp, &i, &k) == -1)
			return (-1);
		i++;	
	}
	return (0);
}