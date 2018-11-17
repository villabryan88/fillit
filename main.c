/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:12:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/17 01:18:11 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>
int		main()
{
	int		pcs[26][4][2];
	int 	fd;
	int		ttl;
	char	**board;
	int		size;
	int		i;

	fd = open("sample.txt", O_RDONLY);
	ttl = read_check_parse(fd, &pcs);
	if (ttl == -1)
	{
		ft_putstr("error");
		return (0);
	}
	size = 0;
	while (size * size < ttl * 4)
		size++;
	ft_putnbrendl(size);
	init_board(&board, size);
//backtracer(pcs, ttl, 0, board);
	while (!backtracer(pcs, ttl, 0, board))
		init_board(&board, ++size);

	


	i = 0;
	while (i < size)
		ft_putendl(board[i++]);
	ft_putendl(board[i+1]);

/*	while (i < ttl)
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
*/	
	return(0);
}

