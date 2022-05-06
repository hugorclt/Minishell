/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:51:57 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/06 19:30:24 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_var(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '"')
		{
			++i;
			while (token[i] != '"' && token[i])
				++i;
		}
		if (token[i] == '\'')
		{
			++i;
			while (token[i] != '\'' && token[i])
				++i;
		}
		if (token[i] == '=')
			return (1);
	}
	return (0);
}

int	ft_verif_token(char *token)
{
	char	**tmp;
	int		i;

	tmp = ft_split_space(token);
	if (!tmp)
		return (-1);
	if (ft_is_builtin(tmp[0]))
	{
		if (!ft_strcmp(tmp[0], "export"))
	}
	while (tmp[i])
	{

	}
}
