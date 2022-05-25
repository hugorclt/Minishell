/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:27:42 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/25 20:20:34 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_next(t_token *token, int i)
{
	if (ft_is_operator(token->token[i]) == 1)
	{
		if (token->token[i + 1] && ft_is_operator(token->token[i + 1]))
		{
			if (!ft_strcmp(token->token[i], token->token[i + 1]))
				return (ft_print_error(token->token[i + 1]), -1);
		}
	}
	else if (!ft_strcmp(token->token[i], ">") || !ft_strcmp(token->token[i],
		">>"))
	{
		if (!token->token[i + 1])
			return (ft_print_error("\n"), -1);
	}
	return (0);
}
