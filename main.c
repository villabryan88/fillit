/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:12:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/27 23:01:37 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

void	print_coord(int pcs[26][6][2], int ttl)
{
	int 	i;
	int		k;
	int		*p;
	
	i = 0;
	while (i < ttl)
	{
		printf("#%d\n", i);
		k = -1;
		while (++k < 4)
			printf("x: %d, y: %d\n", pcs[i][k][0], pcs[i][k][1]);
		p = *(int**)pcs[i][5];
		printf("coord-p: %p, point to: %p \n", pcs[i][4], p);
		i++;
	}
}

void	match(int pcs[26][6][2], int ttl)
{
	int		i;
	int		k;
	int		m;
	int		match;
	int		*last;


	i = 0;
	while (i < ttl)
	{
		pcs[i][4][0] = 0;
		pcs[i][4][1] = 0;
		*((int**)pcs[i++][5]) = 0;
	}
	i = 0;
	
	while (i < ttl)
	{
		if (!*((int**)pcs[i][5]))
		{
			last = pcs[i][4];
			k = i + 1;
			while (k < ttl)
			{
				match = 0;
				m = 0;
				while (m < 4)
				{
					if ((pcs[i][m][0] == pcs[k][m][0]) &&
						   (pcs[i][m][1] == pcs[k][m][1]))
						match = 1;
					else
					{
						match = 0;
						break ;
					}
					m++;
				}
				if (match == 1)
				{
					*((int**)pcs[k][5]) = last;
					last = pcs[k][4];
				//	magic = pcs[k][5];
				//	*((int**)magic) = pcs[i][5];
				}
		 		k++;
			}
  		}
		i++;
	}
}

int		main()
{
	int		pcs[26][6][2];
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
	size = 2;

	match(pcs, ttl);
	print_coord(pcs, ttl);
	while (size * size < ttl * 4)
		size++;

	ft_putnbrendl(size);
	init_board(&board, size);
while (!backtracer(pcs, ttl, 0, board))
{
	init_board(&board, ++size);
	ft_putnbrendl(size);
}
	
//	backtracer(pcs, ttl, 0, board);

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

