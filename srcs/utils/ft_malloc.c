/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:43:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/18 21:29:45 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_malloc(void **malloc_collector, size_t size, size_t count)
{
	void *alloc;

	alloc = malloc(size * count);
	if (!alloc)
		return (1);
	ft_lstadd_front(malloc_collector, ft_lstnew(alloc));
	return (alloc);
}