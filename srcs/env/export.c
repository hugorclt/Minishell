/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:26:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/03 15:40:56 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_find_occurence(char **env, char *cmd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], cmd, ft_strlen(env[i])))
			return (i);
		i++;
	}
	return (-1);
}
/*
static char	**ft_export_line(char **env, char *cmd)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * ft_tab_size(env) + 2);
	if (!ret)
		return (NULL);
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
	ret[i] = NULL;
	return (ft_free(env), ret);
}

static void	ft_print_export_alpha(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("declare -x %s\n", tab[i]);
		i++;
	}
}
*/
static int	ft_find_small(char **export, int cmp)
{
	int	i
}
int	ft_export_alph(char **env)
{
	char	**export;
	int		i;
	int		j;

	export = ft_dup_tab(env);
	if (!export)
		return (-1);
	i = 0;
	while (env[i])
	{
		j = i + 1;
		while (j < ft_tab_size(env) - 1)
		{
		}
	}
}
/*
char	**ft_export_main(char **env, char **cmd)
{
	char	**ret;
	
	ret = NULL;
	if (!cmd[1])
	{
		if (ft_export_alph(env) == -1)
			return (NULL);
	}
	else
	{
		ret = ft_export_line(env, cmd[]);
		if (!ret)
			return (NULL);
		return (ret);
	}
	return (env);
}*/

