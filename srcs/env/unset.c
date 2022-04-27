/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/27 15:39:52 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**ft_unset_one(char **env, char *cmd, int j)
{
	char	**ret;
	int		i;
	int		line_occurence;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * ft_tab_size(env));
	line_occurence = ft_find_occurence(env, cmd);
	if (line_occurence == -1 || !ret)
		return (NULL);
	while (env[i])
	{
		if (i == line_occurence)
		{
			i++;
			continue ;
		}
		ret[j] = ft_strdup(env[i]);
		if (!ret)
			return (NULL);
		i++;
		j++;
	}
	ret[j] = 0;
	return (ft_free(env), ret);
}

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
}