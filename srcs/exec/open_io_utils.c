/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:54:40 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/27 13:34:35 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_print_file_access(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("permission denied: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_print_file_not_found(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_last_status = 2;
}

void	ft_print_io_error_choice(char *str)
{
	g_last_status = 1;
	if (errno == 13)
		ft_print_file_access(str);
	else
		ft_print_file_not_found(str);
}
