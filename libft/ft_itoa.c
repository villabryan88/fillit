/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 01:12:08 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 21:13:42 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		neg;
	int		place;
	int		i;

	place = n >= 10 || n <= -10 ? 10 : 1;
	neg = n < 0 ? -1 : 1;
	len = n >= 10 || n <= -10 ? 2 : 1;
	while (n / place * neg >= 10 && ++len)
		place *= 10;
	if (!(num = (char*)malloc(neg < 0 ? len + 2 : len + 1)))
		return (NULL);
	i = 0;
	if (neg == -1)
		num[i++] = '-';
	while (place > 0)
	{
		num[i++] = n / place * neg + '0';
		n %= place * neg;
		place /= 10;
	}
	num[i] = '\0';
	return (num);
}
