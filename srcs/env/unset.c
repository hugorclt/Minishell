/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/06 17:14:14 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
char	**ft_unset(char **env, char **cmd)
{
	char	**ret;
	int		i;

	i = 1;
	if (!cmd[1])
		return (env);
	ret = ft_dup_tab(env);
	if (!ret)
		return (NULL);
	while (cmd[i])
	{
		ret = ft_unset_one(ret, cmd[i], 0);
		if (!ret)
			return (NULL);
		i++;
	}
	ret[i] = 0;
	return (ft_free(env), ret);
}*/
