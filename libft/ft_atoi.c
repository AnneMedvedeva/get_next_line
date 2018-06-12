/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:05:10 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/16 15:59:51 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				ng;
	unsigned long	total;

	ng = 1;
	total = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ng = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		total = (*str - '0') + total * 10;
		if (total > 9223372036854775807 && ng == -1)
			return (0);
		else if (total >= 9223372036854775807 && ng == 1)
			return (-1);
		str++;
	}
	return ((int)total * ng);
}
