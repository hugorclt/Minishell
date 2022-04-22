/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:13:18 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 13:42:32 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_dup_tab(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * ft_tab_size(tab));
	if (!ret)
		return (ft_free(tab), NULL);
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	return (ret);
}

void	print_pwd()
{
	printf("%s\n", get_pwd());
}

char	*get_pwd()
{
	char *buffer;

	buffer = getcwd(NULL, 0);
	if (!buffer)
		return (NULL);
	else
		printf("%s\n", buffer);
	return (0);
		return (NULL);
	return (buffer);
} 
