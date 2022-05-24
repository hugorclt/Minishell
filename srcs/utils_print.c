/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:54:54 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/24 23:14:28 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_lst(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (tmp->token[i])
		{
			printf("%s", tmp->token[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void	ft_print_tab(char **tokens)
{
	int	i;

	i = 0;
	if (!*tokens)
		return ;
	while (tokens[i])
		dprintf(2, "|%s|\n", tokens[i++]);
}

void	ft_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_check_equal(env[i]))
			printf("%s\n", env[i]);
		++i;
	}
	g_last_status = 0;
}
