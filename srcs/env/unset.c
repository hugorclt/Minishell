/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/11 12:39:35 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_unset(char **env, char *var)
{
	char	**output;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (ft_find_occurence(env, var) == -1)
		return (ft_free(env), env);
	output = malloc(sizeof(char *) * (ft_tab_size(env)));
	if (!output)
		return (NULL);
	printf("var : %s\n", var);
	while (env[i])
	{
		printf("env[i] : %s\n", env[i]);
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
		{
			printf("je passe bien ici\n");
			++i;
		}
		output[j] = ft_strdup(env[i]);
		if (!output[j])
			return (ft_free(output), NULL);
		ft_increm(&i, &j);
	}
	output[j] = NULL;
	return (ft_free(env), output);
}
