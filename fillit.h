/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:16:07 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/14 00:13:14 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

int     preparse_errorcheck(char *piece);
int		reader(int	fd, char **tetris);
int		read_check_parse(int fd, int (*pcs)[26][4][2]);
int		ft_parse(char *s, int (*pcs)[26][4][2]);

#endif
