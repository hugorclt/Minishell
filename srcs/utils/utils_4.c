/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:11:13 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 20:56:19 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_close_redirect(t_list **lst)
{
	int		i;

	i = 0;
	while (i < (*lst)->nb_infile)
	{
		printf("test\n");
		if ((*lst)->file_in[i].fd != -1)
		{
			if (close((*lst)->file_in[i].fd) == -1)
				return (-1);
			if ((*lst)->file_in[i].flag == 1)
				unlink((*lst)->file_in[i].file);
		}
		i++;
	}
	i = 0;
	while (i < (*lst)->nb_outfile)
	{
		if ((*lst)->file_out[i].fd != -1)
		{
			if (close((*lst)->file_out[i++].fd) == -1)
				return (-1);
		}
		i++;
	}
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
