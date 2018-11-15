/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:17:50 by amohamed          #+#    #+#             */
/*   Updated: 2018/11/15 14:44:16 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_postparse_check(int (*tet)[4][2])
{
	int	b;
	int i;
	int	diff;
	int	match;

	b = 0;
	match = 0;
	while (b < 3)
	{
		i = b + 1;
		while (i < 4)
		{
			diff = 0;
			if ((*tet)[b][0] == (*tet)[i][0])
				diff = (*tet)[b][1] - (*tet)[i][1];
			else if ((*tet)[b][1] == (*tet)[i][1])
				diff = (*tet)[b][0] - (*tet)[i][0];
			if (diff * diff == 1)
				match++;
			i++;
		}
		b++;
	}
	return (match >= 3 ? 0 : 1);
}

void	ft_adjust_pieces(int (*pcs)[26][4][2], int i)
{
	int	smlx;
	int	smly;
	int pc;

	pc = 0;
	smlx = 0;
	smly = 0;
	while (pc < 4)
	{
		if ((*pcs)[i][pc][0] < smlx)
			smlx = (*pcs)[i][pc][0];
		if ((*pcs)[i][pc][1] < smly)
			smly = (*pcs)[i][pc][1];
		pc++;
	}
	pc = 0;
	while (pc < 4)
	{
		(*pcs)[i][pc][0] -= smlx;
		(*pcs)[i][pc][1] -= smly;
		pc++;
	}
}

void	ft_move_ref_pt(int (*pcs)[26][4][2], int i)
{
	int x_stored;
	int y_stored;
	int first;
	int x;

	x = 0;
	first = 0;
	x_stored = 0;
	y_stored = 0;
	while (x < 4)
	{
		if (!first)
		{
			first = 1;
			x_stored = (*pcs)[i][x][0];
			y_stored = (*pcs)[i][x][1];
		}
		(*pcs)[i][x][0] -= x_stored;
		(*pcs)[i][x][1] -= y_stored;
		x++;
	}
	ft_adjust_pieces(pcs, i);
}

void	ft_read_coord(char *s, int tetri[4][2])
{
	int x;
	int y;
	int b;

	b = 0;
	x = 0;
	y = 0;
	while (*s)
	{
		if (*s == '\n')
		{
			y++;
			x = 0;
		}
		if (*s != '\n')
		{
			if (*s == '#')
			{
				tetri[b][0] = x;
				tetri[b++][1] = y;
			}
			x++;
		}
		s++;
	}
}

int		ft_parse(char *s, int (*pcs)[26][4][2])
{
	static int i = 0;

	if (i > 25)
		return (-1);
	ft_read_coord(s, (*pcs)[i]);
	ft_move_ref_pt(pcs, i);
	if (ft_postparse_check((*pcs) + i))
		return (-1);
	i++;
	return (i);
}
