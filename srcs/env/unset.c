/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/26 16:14:14 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**ft_unset_one(char **env, char *cmd)
{
	char	**ret;
	int		i;
	int		j;
	int		line_occurence;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * ft_tab_size(env));
	if (!ret)
		return (NULL);
	line_occurence = ft_find_occurence(env, cmd);
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
	ret[j] = '\0';
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
	while (cmd[i]);
	{
		ret = ft_unset_one(ret, cmd[i]);
		if (!ret)
			return (NULL);
		i++;
	}
	ret[i] = '\0';
	return (ft_free(env), ret);
}