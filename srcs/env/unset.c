/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:48 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/10 15:18:43 by yuro4ka          ###   ########.fr       */
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
	while (env[i])
	{
		if (i == ft_find_occurence(env, var))
			++i;
		output[j] = ft_strdup(env[i]);
		if (!output[j])
			return (ft_free(output), NULL);
		ft_increm(&i, &j);
	}
	output[j] = NULL;
	return (ft_free(env), output);
}
