/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:02:10 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/03 21:44:56 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ret;

	ret = s1;
	while (*s1)
		s1++;
	while (*s2 != '\0')
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (ret);
}
