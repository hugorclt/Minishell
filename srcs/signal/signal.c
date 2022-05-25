/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:17:12 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/25 05:00:16 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sign_handle(int signo)
{
	(void)signo;
	rl_on_new_line();
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_redisplay();
	g_last_status = 130;
}

void	sig_choice(void)
{
	signal(SIGINT, ft_sign_handle);
	signal(SIGQUIT, SIG_IGN);
}
