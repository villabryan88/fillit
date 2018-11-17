/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:16:07 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/17 00:54:29 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

int		preparse_errorcheck(char *piece);
int		reader(int fd, char **tetris);
int		read_check_parse(int fd, int (*pcs)[26][4][2]);
int		ft_parse(char *s, int (*pcs)[26][4][2]);
int		ft_dblstrarrclr(char ***arr, int size, int ret);
int		backtracer(int pcs[26][4][2], int ttl, int pc, char **board);
int		init_board(char ***board, int size);
int		place_block(char **board, int tetri[4][2], int x, int y);
void	cleanup(char **board, int tetri[4][2], int x, int y);

#endif
