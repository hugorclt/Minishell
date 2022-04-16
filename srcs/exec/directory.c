/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:37:26 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/16 09:39:45 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_pwd()
{
	char *buffer;

	buffer = getcwd(NULL, 0);
	if (!buffer)
		return (1);
	else
		printf("%s\n", buffer);
	return (0);
}