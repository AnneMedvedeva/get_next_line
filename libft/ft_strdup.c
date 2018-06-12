/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:09:03 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/23 13:17:51 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (tmp != NULL)
	{
		return (ft_strcpy(tmp, s1));
	}
	else
		return (NULL);
}
