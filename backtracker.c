/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:59:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/16 19:16:25 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cleanup(

int		place_block(char **board, int **tetri, int x, int y)
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
			if (board[y + y2][x + x2] == '.')
				board[y + y2][x + x2] = ltr;
			else
			{
				cleanup();
				return (0);
			}
	}
	return (1);
}
