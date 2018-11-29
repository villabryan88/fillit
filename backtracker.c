/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:59:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/28 22:42:56 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cleanup(char **board, int tetri[6][2], int x, int y)
{
	int		x2;
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
	return (0);
}

int		board_size(char **board)
{
	int		size;

	size = 0;
	while (board[size])
		size++;
	return (size);
}

int		place_block(char **board, int tetri[6][2], int x, int y)
{
	int		x2;
	int		y2;
	int		pc;
	int		size;
	char	ltr;

	size = board_size(board);
	ltr = board[size + 1][0];
	pc = -1;
	while (++pc < 4)
	{
		x2 = tetri[pc][0] + x;
		y2 = tetri[pc][1] + y;
		if ((y2 >= size && (ltr = -2)) ||
				(x2 >= size && (ltr = -1)))
		{
			cleanup(board, tetri, x, y);
			return (ltr);
		}
		if (board[y2][x2] == '.')
			board[y2][x2] = ltr;
		else
			return (cleanup(board, tetri, x, y));
	}
	return (1);
}

void	set_coord(int pcs[26][6][2], int pc, int **i, int **k)
{
	*i = pcs[pc][4] + 1;
	*k = pcs[pc][4];
	if ((*(int**)pcs[pc][5]))
	{
		**i = (*(int**)pcs[pc][5])[1];
		**k = (*(int**)pcs[pc][5])[0] + 1;
	}
	else
		**i = 0;
}

int		backtracer(int pcs[26][6][2], int ttl, int pc, char **board)
{
	int		*i;
	int		*k;
	int		size;
	int		oflo;

	size = board_size(board);
	set_coord(pcs, pc, &i, &k);
	board[size + 1][0] = pc + 'A';
	while (*i < size)
	{
		while (*k < size)
		{
			if ((oflo = place_block(board, pcs[pc], *k, *i)) > 0)
			{
				if (pc == ttl - 1 || backtracer(pcs, ttl, pc + 1, board))
					return (1);
				board[size + 1][0] = pc + 'A';
				cleanup(board, pcs[pc], *k, *i);
			}
			*k = oflo < 0 ? size : *k + 1;
		}
		*k = 0;
		*i = oflo == -2 ? size : *i + 1;
	}
	return (0);
}
