/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:19:51 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/10 12:10:08 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_reset_quotes(t_token *token)
{
	token->nb_dquotes = 0;
	token->nb_quotes = 0;
	token->old_first_quotes = 0;
}

void	ft_pass_space_reverse(char *cmd, int *new_j)
{
	if (cmd[(*new_j) - 1] && cmd[(*new_j) - 1] == ' ')
	{
		(*new_j)--;
		if (cmd[*new_j] && cmd[*new_j] == ' ')
		{
			while (cmd[*new_j] == ' ')
				(*new_j)--;
			(*new_j)++;
		}
	}
}