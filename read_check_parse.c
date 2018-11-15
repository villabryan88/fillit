/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:19:05 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/15 13:18:34 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		read_check_parse(int fd, int (*pcs)[26][4][2])
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
            break;
		 ttl = ft_parse(tetris, pcs);
		 if (ttl == -1 && (error = ttl))
			 break;
    }
    if (error || !last)
    {
        ft_putstr("error");
        return (-1);
    }
    return(ttl);
}
