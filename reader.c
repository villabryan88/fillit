/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:35:48 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/15 18:50:58 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		reader(int fd, char **tetris)
{
	char	*pcs;
	int		red;

	pcs = (char*)malloc(sizeof(char) * 22);
	red = read(fd, pcs, 21);
	pcs[red] = '\0';
	*tetris = pcs;
	return (red);
}
