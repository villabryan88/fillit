/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:35:48 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/13 22:00:28 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"


int		reader(int	fd, char **tetris)
{
	char	*pcs;
	int		red;

	pcs = (char*)malloc(sizeof(char) * 22);
	red = read(fd, pcs, 21);
	if (red == 20)
	{
		pcs[red] = '\n';
		pcs[21] = '\0';
	}
	else
		pcs[red] = '\0';
	*tetris = pcs;
	return (red);
}

int		main()
{
	char	*tetris;
	int		red;
	int		i;
	int 	fd;

	fd = open("sample.txt", O_RDONLY);
	i = 0;
	while ((red = reader(fd, &tetris)) > 0)
	{
			printf("ret: %d\n%s", red, tetris);
	}



	return(0);
}
