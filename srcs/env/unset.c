/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/11 15:42:04 by hrecolet         ###   ########.fr       */
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

char	**ft_unset(char **env, char **var)
{
	char	**output;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (ft_is_in(env, var) == -1)
		return (ft_free(env), env);
	output = malloc(sizeof(char *) * (ft_tab_size(env)));
	if (!output)
		return (NULL);
	while (env[i])
	{
		if (ft_is_in(var, env[i]))
			++i;
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
