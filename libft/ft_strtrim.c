/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:41:15 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/20 12:43:08 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len_wo_sp(const char *str)
{
	int trimlen;
	int j;

	trimlen = ft_strlen(str);
	j = -1;
	while (str[trimlen - 1] == ' ' || str[trimlen - 1] == '\n' ||
			str[trimlen - 1] == '\t')
		trimlen--;
	while (str[++j] == ' ' || str[j] == '\n' || str[j] == '\t')
		trimlen--;
	if (trimlen <= 0)
		trimlen = 0;
	return (trimlen);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		count;
	int		len;
	char	*trim;

	if (!s)
		return (NULL);
	len = len_wo_sp(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	trim = ft_strnew(len);
	if (!trim)
		return (NULL);
	count = -1;
	s = s + i;
	while (++count < len)
	{
		trim[count] = *s++;
	}
	trim[count] = '\0';
	return (trim);
}
