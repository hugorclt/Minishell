/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:11:13 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 16:20:11 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_close_redirect(t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*lst);
	if (tmp->nb_infile > 0)
	{
		if (tmp->file_in[i].fd != -1)
		{
			if (close(tmp->file_in[i].fd) == -1)
				return (-1);
			if (tmp->file_in[i].flag == 1)
				unlink(tmp->file_in[i].file);
		}
		i++;
	}
	i = 0;
	if (tmp->nb_outfile > 0)
	{
		if (tmp->file_out[i].fd != -1)
		{
			if (close(tmp->file_out[i++].fd) == -1)
				return (-1);
		}
	}
	tmp = tmp->next;
	return (0);
}

void	ft_quoted(t_token *token, char c)
{
	if (c == '\'')
		token->nb_quotes++;
	else if (c == '"')
		token->nb_dquotes++;
	if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 != 0)
		token->first_quotes = '\'';
	else if (token->nb_dquotes % 2 != 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = '"';
}
