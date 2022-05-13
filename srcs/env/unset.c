/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/13 12:31:26 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_in(char **var_lst, char *var)
{
	int	i;

	i = 1;
	while (var_lst[i])
	{
		if (!ft_strncmp(var_lst[i], var, ft_strlen(var)))
			return (1);
		++i;
	}
	return (0);
}

int	ft_need(char **env, char **var_lst)
{
	int	i;
	int	j;

	i = 1;
	while (var_lst[i])
	{
		j = 0;
		while (env[j])
		{
			if (ft_strncmp(env[j], var_lst[i], ft_strlen(var_lst[i])) == 0)
			{
				printf("enculer\n");
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

char	**ft_unset(char **env, char **var)
{
	char	**output;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (!ft_need(env, var))
		return (env);
	output = malloc(sizeof(char *) * (ft_tab_size(env) + 1 - (ft_tab_size(var) - 1)));
	if (!output)
		return (NULL);
	while (env[i])
	{
		if (ft_is_in(var, env[i]) == 1)
		{
			printf("je passe bien ici\n");
			++i;
		}
		else
		{
			output[j] = ft_strdup(env[i]);
			if (!output[j])
				return (ft_free(output), NULL);
			ft_increm(&i, &j);
		}
	}
	output[j] = NULL;
	return (ft_free(env), output);
}
