/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:22:40 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/20 11:59:46 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memarea;

	memarea = malloc(size);
	if (!memarea)
		return (NULL);
	else
		ft_bzero(memarea, size);
	return (memarea);
}
