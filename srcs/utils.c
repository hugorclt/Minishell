/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:13:18 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 13:17:07 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_dup_tab(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * ft_tab_size(tab));
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	return (ret);
}
