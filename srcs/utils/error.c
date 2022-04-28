/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:55:01 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/04/28 15:17:48 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_error(char *token)
{
	printf("bash: syntax error near unexpected token `%s'\n", token);
}

void	ft_print_ofpc(void)
{
	printf("déso on gere pas les quotes pas fermées\n");
}
