/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:51:34 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/17 00:22:25 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_dblstrarrclr(char ***arr, int size, int ret)
{
	int		i;

	i = 0;
	while (i < size)
		free((*arr)[i++]);
	free(*arr);
	*arr = NULL;
	return (ret);
}
