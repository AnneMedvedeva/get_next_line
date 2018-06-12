/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:53:56 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/23 14:29:37 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	countlen(size_t len, int negnum, int n)
{
	while (n /= 10)
		len++;
	len += negnum;
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 2;
	neg = 0;
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	len = countlen(len, neg, n);
	if (!(str = ft_strnew(len - 1)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
