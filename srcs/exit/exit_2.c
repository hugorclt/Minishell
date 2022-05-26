/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:33:19 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 23:37:57 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_infile(t_list *tmp)
{
	int	i;

	i = 0;
	while (i < tmp->nb_infile)
		free(tmp->file_in[i++].file);
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
