/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:26:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/25 20:42:29 by hrecolet         ###   ########.fr       */
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

static void	ft_skip_to_space(char *cmd)
{
	while (*cmd != " ")
		cmd++;
	cmd++;
}

char	**ft_unset(char **env, char *cmd)
{
	char	**ret;
	int		i;
	int		line_to_del;
	
	ret = malloc(sizeof(char *) * ft_tab_size(env));
	if (!ret)
		return (NULL);
	i = 0;
	ft_skip_to_space(cmd);
	line_to_del = ft_find_occurence(env, cmd);
	while (env[i])
	{
		if (i == line_to_del)
		{
			i++;
			continue ;
		}
		ret[i] = ft_strdup(env[i]);
		if (!ret[i])
			return (NULL);
		i++;
	}
	ret[i] = '\0';
	return (ft_free(env), ret);
}