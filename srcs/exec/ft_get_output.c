/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:07:24 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/31 21:09:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_get_output(t_list **lst, char **tab, int *k, int i)
{
	t_list	*tmp;

	tmp = (*lst);
	if (ft_strcmp(tab[i], ">>") == 0)
	{
		tmp->file_out[*k].file = ft_strdup(tab[i + 1]);
		if (!tmp->file_out[*k].file)
			return (-1);
		tmp->file_out[*k].flag = 1;
		(*k)++;
	}
	else if (ft_strcmp(tab[i], ">") == 0)
	{
		tmp->file_out[*k].file = ft_strdup(tab[i + 1]);
		if (!tmp->file_out[*k].file)
			return (-1);
		tmp->file_out[*k].flag = 0;
		(*k)++;
	}
	return (0);
}

int	ft_add_file_in(t_list **lst, int i, int *j, char **tab)
{
	t_list	*tmp;

	tmp = (*lst);
	tmp->file_in[*j].file = ft_strdup(tab[i + 1]);
	if (!tmp->file_in[*j].file)
		return (-1);
	tmp->file_in[*j].flag = 0;
	(*j)++;
	return (0);
}

int	ft_get_input(t_list **lst, char **tab)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		k;

	tmp = (*lst);
	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "<") == 0)
			ft_add_file_in(lst, i, &j, tab);
		else if (ft_strcmp(tab[i], "<<") == 0)
		{
			tmp->file_in[j++].limiter = ft_strdup(tab[i + 1]);
			if (!tmp->file_in[j].file)
				return (-1);
			tmp->file_in[j].flag = 1;
		}
		if (ft_get_output(lst, tab, &k, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
