/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:20:36 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/20 16:45:55 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmph;
	char	*tmpn;
	size_t	tmplen;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			tmplen = len;
			tmph = (char *)haystack + 1;
			tmpn = (char *)needle + 1;
			while (*tmph && *tmpn && *tmph == *tmpn && tmplen--)
			{
				++tmph;
				++tmpn;
			}
			if (!*tmpn)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
