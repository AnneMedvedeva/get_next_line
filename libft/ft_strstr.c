/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:20:36 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/21 15:20:09 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmph;
	char *tmpn;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tmph = (char *)haystack + 1;
			tmpn = (char *)needle + 1;
			while (*tmph && *tmpn && *tmph == *tmpn)
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
