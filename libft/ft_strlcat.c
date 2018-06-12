/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:58:59 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/20 16:24:18 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*tmpdst;
	const char	*tmpsrc;
	size_t		len;
	size_t		dlen;

	tmpdst = dst;
	tmpsrc = src;
	len = dstsize;
	while (len-- != 0 && *tmpdst != '\0')
		tmpdst++;
	dlen = tmpdst - dst;
	len = dstsize - dlen;
	if (len == 0)
		return (dlen + ft_strlen(tmpsrc));
	while (*tmpsrc != '\0')
	{
		if (len != 1)
		{
			*tmpdst++ = *tmpsrc;
			len--;
		}
		tmpsrc++;
	}
	*tmpdst = '\0';
	return (dlen + (tmpsrc - src));
}
