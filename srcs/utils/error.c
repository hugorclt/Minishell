/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:55:01 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/20 17:49:00 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_error(char *token)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

void	ft_print_ofpc(void)
{
	ft_putstr_fd("déso on gere pas les quotes pas fermées\n", 2);
}
