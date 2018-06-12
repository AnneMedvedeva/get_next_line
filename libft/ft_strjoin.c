/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:38 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/20 13:43:23 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	join = (char *)malloc(sizeof(char) *
			((ft_strlen(s1) + 1) + (ft_strlen(s2) + 1)));
	if (join)
	{
		ft_strcat(ft_strcpy(join, s1), s2);
	}
	return (join);
}
