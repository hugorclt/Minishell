/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:13:18 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/23 23:17:56 by hrecolet         ###   ########.fr       */
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
	return (buffer);
} 

char	*ft_strjoin_char(char *cmd, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!cmd)
	{
		ret = malloc(sizeof(char) * 2);
		if (!ret)
			return (free(cmd), NULL);
	}
	else
	{
		ret = malloc(sizeof(char) * ft_strlen(cmd) + 2);
		if (!ret)
			return (free(cmd), NULL);
		while (cmd[i])
		{
			ret[i] = cmd[i];
			i++;
		}
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	return (free(cmd), ret);
}
