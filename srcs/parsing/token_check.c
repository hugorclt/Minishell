/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:37:01 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/04/27 17:12:47 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
first token can't be a | 

if first token is an operator the second can't be one too

*/
//
static void	ft_print_error(char *token)
{
	printf("bash: syntax error near unexpected token `%s'\n", token);
}

static int	ft_theres_two_types(char *token)
{
}

static int	ft_theres_quotes(char *token)
{
}

static int	ft_check_quote(char *token)
{
}

int	ft_check_token(t_token *token)
{
	int	i;

	i = 0;
	if (is_operator(token->token[i]) == 1 && token->token[i + 1] && 
			is_operator(token->token[i + 1]))
		return (ft_print_error(token->token[i + 1]), -1);
	while (token->token[i])
	{
		if (is_operator(token->token[i]) == 1 && token->token[i + 1] && 
				is_operator(token->token[i + 1]))
		{
			if (ft_strcmp(token->token[i], token->token[i + 1]))
				return (ft_print_error(token->token[i + 1]), -1)
		}
		++i;
	}
}
