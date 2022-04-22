/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:38:11 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 13:39:49 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_get_last_word(char *str, int len)
{
	int	i;

	i = 0;
	while (str[len] != '/')
	{
		len--;
		i++;
	}
	return (i);
}

char	*ft_get_last_dir(char *str)
{
	int	i;
	int	j;
	char *ret;

	j = 0;
	i = ft_strlen(str);
	ret = malloc(sizeof(char) * ft_get_last_word(str, i) + 3);
	if (!ret)
		return (NULL);
	i = i - ft_get_last_word(str, i) + 1;
	while (str[i])
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ret[j] = '$';
	ret[j + 1] = '>';
	ret[j + 2] = '\0';
	return (ret);
}
