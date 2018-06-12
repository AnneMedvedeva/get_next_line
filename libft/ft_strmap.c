/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:13:18 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/21 14:57:32 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	map = ft_stralloc(s);
	if (map)
	{
		while (s[i])
		{
			map[i] = f(s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
