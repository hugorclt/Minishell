/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:17:12 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/24 23:41:23 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sign_handle(int signo)
{
	if (signo == SIGINT)
	{
		rl_replace_line("\n", 0);
		write(1, "\nMinishell$>", 13);
		g_last_status = 131;
	}
}

void	sig_choice()
{
	signal(SIGQUIT, ft_sign_handle);
	signal(SIGINT, SIG_IGN);
}
