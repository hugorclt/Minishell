/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:26:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/26 15:33:43 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_find_occurence(char **env, char *cmd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], cmd, ft_strlen(env[i])))
			return (i);
		i++;
	}
}

char	**ft_export(char **env, char *cmd)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * ft_tab_size(env) + 2);
	if (!ret)
		return (NULL);
	while (*cmd != '=')
		cmd++;
	cmd++;
	while (ret[i])
	{
		ret[i] = ft_strdup(env[i]);
		if (!ret[i])
			return (NULL);
		i++;
	}
	ret[i] = ft_strdup(cmd);
	if (!ret[i])
		return (NULL);
	ret[i] = '\0';
	return (ft_free(env), ret);
}

char	**ft_unset_one(char **env, char *cmd)
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
			return (ft_free(env), NULL);
		i++;
	}
	ret[i] = '\0';
	return (ft_free(env), ret);
}