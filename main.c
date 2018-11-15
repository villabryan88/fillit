/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:12:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/14 00:57:16 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>
int		main()
{
	int		pcs[26][4][2];
	int 	fd;
	int		ttl;
	int		i = 0;
	int		k = 0;

	fd = open("sample.txt", O_RDONLY);
	ttl = read_check_parse(fd, &pcs);
	
	while (i < ttl)
	{
		printf("block #%d:\n", i);
		k = 0;
		while (k < 4)
		{
			printf("x: %d, y: %d\n", pcs[i][k][0],  pcs[i][k][1]);
			k++;
		}
		i++;
	}
	
	return(0);
}

