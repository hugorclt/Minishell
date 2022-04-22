/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:53:42 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 11:59:03 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
