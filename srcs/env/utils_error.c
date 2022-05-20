/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:11:50 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/20 16:51:13 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strlen_exp(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i + 1] == '=')
			break ;
		++i;
	}
	return (i);
}

int	ft_strcmp_exp(char *s1, char *s2)
{
	int	i;
	int	size;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	if (ft_strlen_exp(s1) > ft_strlen_exp(s2))
		size = ft_strlen_exp(s1);
	else
		size = ft_strlen_exp(s2);
	while (s1[i] && s2[i] && size - 1)
	{
		--size;
		++i;
	}
	return (s1[i] - s2[i]);
}


