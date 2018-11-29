/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:19:05 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/29 00:15:25 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	init_coord(int pcs[26][6][2], int ttl)
{
	int		i;

	i = 0;
	while (i < ttl)
	{
		pcs[i][4][0] = 0;
		pcs[i][4][1] = 0;
		*((int**)pcs[i++][5]) = 0;
	}
}

int		check_match(int pcs[26][6][2], int pc1, int pc2)
{
	int b;
	int match;

	match = 0;
	b = 0;
	while (b < 4)
	{
		if ((pcs[pc1][b][0] == pcs[pc2][b][0]) &&
				(pcs[pc1][b][1] == pcs[pc2][b][1]))
			match = 1;
		else
		{
			match = 0;
			break ;
		}
		b++;
	}
	return (match);
}

void	match(int pcs[26][6][2], int ttl)
{
	int		i;
	int		k;
	int		*last;

	i = 0;
	while (i < ttl)
	{
		if (!*((int**)pcs[i][5]))
		{
			last = pcs[i][4];
			k = i + 1;
			while (k < ttl)
			{
				if (check_match(pcs, i, k))
				{
					*((int**)pcs[k][5]) = last;
					last = pcs[k][4];
				}
				k++;
			}
		}
		i++;
	}
}

int		read_check_parse(int fd, int (*pcs)[26][6][2])
{
	char	*tetris;
	int		red;
	int		last;
	int		error;
	int		ttl;

	ttl = 0;
	error = 0;
	last = 0;
	while ((red = reader(fd, &tetris)) > 0)
	{
		if (red == 20)
		{
			last = 1;
			tetris[20] = '\n';
			tetris[21] = '\0';
		}
		if ((error = preparse_errorcheck(tetris)))
			break ;
		ttl = ft_parse(tetris, pcs);
		if (ttl == -1 && (error = 1))
			break ;
	}
	return (error || !last ? -1 : ttl);
}
