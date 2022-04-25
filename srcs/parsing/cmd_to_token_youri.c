/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_token_youri.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:33:26 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/25 09:35:49 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (-1);
}

static void	ft_count_quotes(char c, t_token *token)
{
	if (c == '"')
		token->nb_dquotes++;
	if (c == '\'')
		token->nb_quotes++;
}
