/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:37:26 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/18 21:19:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_pwd()
{
	printf("%s\n", ft_get_pwd());
}

char	*ft_get_pwd()
{
	char *buffer;

	buffer = getcwd(NULL, 0);
	if (!buffer)
		return (NULL);
	return (buffer);
}