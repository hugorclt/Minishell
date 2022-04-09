/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:20:51 by yobougre          #+#    #+#             */
/*   Updated: 2021/11/22 16:20:52 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*sortie;

	sortie = malloc(sizeof(t_list));
	if (!sortie)
		return (NULL);
	sortie->content = content;
	sortie->next = NULL;
	return (sortie);
}
