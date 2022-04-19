/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:46:12 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/18 21:20:06 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_pwd(t_env *var)
{
	var->current_wdir = ft_get_pwd();
}

void	ft_init_env(t_env *var, char **env)
{
	var->env = env;
}
