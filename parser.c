/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:17:50 by amohamed          #+#    #+#             */
/*   Updated: 2018/11/13 23:17:53 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_move_ref_pt(char *pcs[26][4][2], int i)
{
	int x_stored;
	int y_stored;
	int first;
	int x = 0;

	first = 0;
	x_stored = 0;
	y_stored = 0;
	while (x < 4)
	{
		if (!first)
		{
			first = 1;
			x_stored = *pcs[i][x][0];
			y_stored = *pcs[i][x][1];
		}
		*pcs[i][x][0] -= x_stored;
		*pcs[i][x][1] -= y_stored;
		x++;
	}
}

int ft_parse(char *s, int *pcs[26][4][2])
{
	int x;
	int y;
	static int idx = 0;

	x = 0;
	y = 0;
	while(*s)
	{
		if (*s == '\n')
		{
			y++;
			x = 0;
		}
		if (*s != '\n')
		{
			x++;
			if (*s == '#')
			{
				if (!first)

				*pcs[i][x][0] = x; 
				*pcs[i][x][1] = y; 	
			}
		}
		s++;
	}	
	ft_move_ref_pt(pcs, i);
	idx++;
	return (i);
}
