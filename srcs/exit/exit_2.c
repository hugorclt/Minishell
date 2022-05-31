/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:33:19 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/31 18:59:49 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_infile(t_list *tmp)
{
	int	i;

	i = 0;
	while (i < tmp->nb_infile)
	{
		if (tmp->file_in[i].limiter)
			free(tmp->file_in[i].limiter);
		free(tmp->file_in[i].file);
		++i;
	}
}

void	ft_free_outfile(t_list *tmp)
{
	int	i;

	i = 0;
	while (i < tmp->nb_outfile)
		free(tmp->file_out[i++].file);
}

void	ft_free_lst(t_list **start)
{
	t_list	*tmp;

	while ((*start))
	{
		tmp = (*start);
		(*start) = (*start)->next;
		free(tmp);
	}
	free(*start);
}
