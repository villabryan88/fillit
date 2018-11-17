/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:30:13 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/15 20:31:48 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	ft_charcheck(char c, int *x, int *y, int *count)
{
	*count = (c == '#' ? *count + 1 : *count);
	if (c != '\n')
		(*x)++;
	if (c == '\n' && *x != 4)
		return (1);
	if ((c != '#' && c != '.' && c != '\n') || (c == '\n' && *x != 4))
		return (1);
	if (c == '\n')
	{
		(*y)++;
		*x = 0;
	}
	return (0);
}

int			preparse_errorcheck(char *piece)
{
	int x;
	int y;
	int count;
	int i;

	i = 0;
	count = 0;
	y = 0;
	x = 0;
	if (ft_strlen(piece) != 21)
		return (1);
	while (i < 20)
	{
		if (ft_charcheck(piece[i], &x, &y, &count))
			return (1);
		i++;
	}
	if (y != 4 || count != 4 || piece[19] != '\n' || piece[20] != '\n')
		return (1);
	return (0);
}
