/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:12:41 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/13 23:50:27 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main()
{
	char	*tetris;
	int		red;

	int 	fd;
	int		error;
	char *tetridup = NULL;


	error = 0;
	fd = open("sample.txt", O_RDONLY);
	read_check_parse(fd);
	
	return(0);
}

