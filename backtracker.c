/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:59:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/17 01:20:47 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cleanup(char **board, int tetri[4][2], int x, int y)
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


		
int		place_block(char **board, int tetri[4][2], int x, int y)
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
			return (0);
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

int		backtracer(int pcs[26][4][2], int ttl, int pc, char **board)
{
	int		i;
	int		k;
	int		size;

	i = 0;
	while (board[i])
		i++;
	size = i;
	i = 0;
	k = 0;
	board[size + 1][0] = pc + 'A';
	while(i < size)
	{
		k = 0;
		while (k < size)
		{
			if(place_block(board, pcs[pc], k, i))
			{
				if (pc == ttl - 1)
					return (1);
				if(backtracer(pcs, ttl, pc + 1, board))
					return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}
