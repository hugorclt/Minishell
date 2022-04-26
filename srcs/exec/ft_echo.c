/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:41:39 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/26 14:54:10 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_echo_n(char **cmd)
{
	int	i;
	int	len_cmd;

	i = 2;
	len_cmd = ft_tab_size(cmd) - 2;
	while (i < len_cmd - 1)
	{
		printf("%s ", cmd[i]);
		i++;
	}
	printf("%s", cmd[i]);
}

void	ft_echo(char **cmd)
{
	int	i;
	int	len_cmd;

	i = 1;
	len_cmd = ft_tab_size(cmd) - 1;
	if (ft_strncmp(cmd[1], "-n", 2))
	{
		ft_echo_n(cmd);
	}
	else
	{
		while (i < len_cmd - 1)
		{
			printf("%s ", cmd[i]);
			i++;
		}
		printf("%s\n", cmd[i]);
	}
}