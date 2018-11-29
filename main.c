/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:12:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/29 00:16:03 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int		init_board(char ***board, int size)
{
	int	i;
	int	j;

	if (!(*board = (char**)malloc(sizeof(char*) * (size + 2))))
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (!((*board)[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (ft_dblstrarrclr(board, i, 0));
		j = 0;
		while (j < size)
		{
			(*board)[i][j] = '.';
			j++;
		}
		(*board)[i][j] = '\0';
		i++;
	}
	(*board)[i++] = NULL;
	if (!((*board)[i] = (char*)malloc(sizeof(char))))
		return (ft_dblstrarrclr(board, i, 0));
	(*board)[i][0] = 'A';
	return (1);
}

void	disp_board(char **board, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putendl(board[i++]);
}

void	logic(int pcs[26][6][2], char ***board, int ttl)
{
	int		size;

	size = 2;
	match(pcs, ttl);
	while (size * size < ttl * 4)
		size++;
	init_board(board, size);
	while (!backtracer(pcs, ttl, 0, *board))
		init_board(board, ++size);
	disp_board(*board, size);
}

int		main(int ac, char **av)
{
	int		pcs[26][6][2];
	int		fd;
	int		ttl;
	char	**board;
	int		size;

	if (!(ac == 2))
	{
		ft_putstr("fillit target_file");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	ttl = read_check_parse(fd, &pcs);
	if (ttl == -1)
	{
		ft_putstr("error");
		return (0);
	}
	logic(pcs, &board, ttl);
	return (0);
}
