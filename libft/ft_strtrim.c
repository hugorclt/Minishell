/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:24:12 by yobougre          #+#    #+#             */
/*   Updated: 2021/11/24 15:40:42 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j && ft_is_set(s1[j], set))
		j--;
	if (!j)
		return (ft_substr(s1, 0, j));
	else
		return (ft_substr(s1, i, j - i + 1));
}
