/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:34:27 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/19 11:43:00 by hrecolet         ###   ########.fr       */
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
