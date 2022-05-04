/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:00:57 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/04 19:37:37 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_new_env(char **env)
{
}

char	**ft_add_var(char *var, char **env)
{
	char **output;
	int	i;

	size = ft_tab_size(env);
	output = malloc(sizeof(char *) * (size + 2));
	if (!output)
		return (NULL);
	i = 0;
	while (env[i])
	{
		output[i] = ft_strdup(env[i]);
		if (!output[i])
			return (ft_free(output), NULL);
		i++;
	}	
	output[i] = ft_strdup(var);
	if (!output[i])
		return (ft_free(output), NULL);
	output[i + 1] = NULL;
	return (ft_free(env), output);
}

int	ft_find_occ(char **env, char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], var, ft_strlen(env[i])))
			return (i);
		++i;
	}
	return (-1);
}

char	**ft_change_var(char **env, char *var, int j)
{
	char **output;
	int	i;
	int	p;

	output = malloc(sizeof(char *) * (ft_tab_size(env) + 1));
	if (!output)
		return (NULL);
	i = 0;
	p = 0;
	while (env[i])
	{
		if (i == j)
		{
			output[i] = ft_strdup(var);
			if (!output[i])
				return (ft_free(output), NULL);
			++i;
		}
		output[i] = ft_strdup(env[p++]);
		if (!output[i])
			return (ft_free(output), NULL);
		i++;
	}
	output[i] = NULL;
	return (ft_free(env), output);
}
