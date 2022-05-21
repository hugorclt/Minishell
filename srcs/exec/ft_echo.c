/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:41:39 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/21 09:57:35 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_echo_n(char **cmd)
{
	int	i;
	int	len_cmd;

	i = 2;
	len_cmd = ft_tab_size(cmd);
	while (i < len_cmd - 1)
	{
		printf("%s ", cmd[i]);
		i++;
	}
	printf("%s", cmd[i]);
}

void	ft_echo(t_node *params, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[1])
		return ;
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		ft_echo_n(cmd);
	}
	else
	{
		while (cmd[i])
		{
			printf("%s ", cmd[i]);
			i++;
		}
		printf("\n");
	}
	params->last_status = 0;
}
