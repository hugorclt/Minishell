/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:33:04 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/18 11:35:56 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char *str)
{
	//PEUT ETRE PRENDRE UN **tab, car essaie de faire echo "a" "b" == ca print "a b" donc peut etre boucle!
	printf("%s\n", str);
}

void	ft_echo_n(char *str)
{
	//PEUT ETRE PRENDRE UN **tab, car essaie de faire echo "a" "b" == ca print "a b" donc peut etre boucle!
	printf("%s", str);
}
