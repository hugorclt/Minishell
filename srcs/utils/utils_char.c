/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:34:27 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/18 13:59:01 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(1, str, i);
}

void	ft_print_char_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
	}
}

char	*get_last_dir(char *str)
{
	int	i;
	int	j;
	char *ret;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (str[i] != '/')
	{
		i--;
		j++;
	}
	ret = malloc(sizeof(char) * j + 1);
	if (!ret)
		return (NULL);
	while (str[i++])
		ret[k++] = str[i];
	k--;
	ret[k] = '>';
	return (ret);
}
