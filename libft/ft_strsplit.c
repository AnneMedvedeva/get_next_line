/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:10:49 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/23 14:36:37 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	strcount(char const *s, char c)
{
	size_t	i;
	int		ds;

	ds = 0;
	i = 0;
	while (*s != '\0')
	{
		if (ds == 1 && *s == c)
			ds = 0;
		if (ds == 0 && *s != c)
		{
			ds = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static	size_t	strcountlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	count;

	i = 0;
	if (!s || !c)
		return (NULL);
	count = strcount(s, c);
	str = (char**)malloc(sizeof(str) * (count + 1));
	if (!str)
		return (NULL);
	while (count--)
	{
		while (*s == c && *s != '\0')
			s++;
		len = strcountlen(s, c);
		str[i] = ft_strsub(s, 0, len);
		if (!str[i])
			return (NULL);
		s = s + len;
		i++;
	}
	str[i] = NULL;
	return (str);
}
