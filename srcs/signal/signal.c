/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:17:12 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/25 01:30:47 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sign_handle(int signo)
{
	(void)signo;
	write(1, "\nMinishell$>", 13);
	g_last_status = 131;
}

void	sig_choice()
{
	signal(SIGINT, ft_sign_handle);
	signal(SIGQUIT, SIG_IGN);
}
