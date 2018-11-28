/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:59:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/27 23:01:02 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cleanup(char **board, int tetri[6][2], int x, int y)
{
	int 	x2;
	int		y2;
	int		pc;
	int		size;
	char	ltr;

	y2 = 0;
	while (board[y2])
		y2++;
	size = y2;
	ltr = board[y2 + 1][0];
	pc = 0;
	while (pc < 4)
	{
		x2 = tetri[pc][0];
	   	y2 = tetri[pc][1];
		if (y + y2 < size && x + x2 < size)
			if (board[y + y2][x + x2] == ltr)
				board[y + y2][x + x2] = '.';
		pc++;
	}
}


		
int		place_block(char **board, int tetri[6][2], int x, int y)
{
	int 	x2;
	int		y2;
	int		pc;
	int		size;
	char	ltr;

	y2 = 0;
	while (board[y2])
		y2++;
	size = y2;
	ltr = board[y2 + 1][0];
	pc = 0;
	while (pc < 4)
	{
		x2 = tetri[pc][0];
	   	y2 = tetri[pc][1];
		if (y + y2 < size && x + x2 < size)
		{
			if (board[y + y2][x + x2] == '.')
				board[y + y2][x + x2] = ltr;
			else
			{
				cleanup(board, tetri, x, y);
				return (0);
			}
		}
		else
		{
			cleanup(board, tetri, x, y);
			return (y + y2 >= size ? -2 : -1);
		}
		pc++;
	}
	return (1);
}

int		init_board(char ***board, int size)
{
	int	i;
	int	j;

	if(!(*board = (char**)malloc(sizeof(char*)*(size + 2))))
		return (0);
	i = 0;
	j = 0;
	while(i < size)
	{
		if(!((*board)[i] = (char*)malloc(sizeof(char)*(size + 1))))
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

int		backtracer(int pcs[26][6][2], int ttl, int pc, char **board)
{
	int		*i;
	int		*k;
	int		size;
	int		oflo;

	size = 0;
	while (board[size])
		size++;
	i = pcs[pc][4] + 1;
	k = pcs[pc][4];

	if ((*(int**)pcs[pc][5]))
	{
		*i = (*(int**)pcs[pc][5])[1];
		*k = (*(int**)pcs[pc][5])[0] + 1;
	}

	board[size + 1][0] = pc + 'A';

	while(*i < size)
	{
		while (*k < size)
		{
			if((oflo = place_block(board, pcs[pc], *k, *i)) > 0)
			{

				if (pc == ttl - 1)
					return (1);
				if(backtracer(pcs, ttl, pc + 1, board))
					return (1);
				board[size + 1][0] = pc + 'A';
				cleanup(board, pcs[pc], *k, *i);
			}
			*k += 1;
			if (oflo < 0)
				*k = size;
		}
		*k = 0;
		*i += 1;
		if (oflo == -2)
			*i = size;
	}
	if (pcs[pc][4][0] == 0)
		*i = 0;
	return (0);
}
