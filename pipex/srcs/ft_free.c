/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:26:48 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/10 13:31:01 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_struct(t_node *params)
{
	ft_close_all(params);
	close(params->infile);
	close(params->outfile);
	free(params->fd);
	free(params->pid);
	if (params->infile_name)
		free(params->infile_name);
	if (params->outfile_name)
		free(params->outfile_name);
	ft_free(params->cmd);
}

int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
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
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
