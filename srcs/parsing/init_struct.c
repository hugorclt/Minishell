/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:46:12 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 10:00:15 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_pwd(t_token *var)
{
	var->current_wdir = ft_get_pwd();
}

void	ft_init_env(t_token *var, char **env)
{
	var->env = env;
}
