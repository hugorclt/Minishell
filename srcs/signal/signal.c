/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:17:12 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/27 10:53:49 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sign_handle(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		g_last_status = 130;
	}
	else if (signo == SIGQUIT)
	{
		g_last_status = 131;
	}
}

void	sig_choice(int a)
{
	if (a == 1)
	{
		signal(SIGINT, ft_sign_handle);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (a == 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (a == 2)
	{
		signal(SIGINT, ft_sign_handle);
		signal(SIGQUIT, ft_sign_handle);
	}
}
