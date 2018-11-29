# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvilla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 00:18:12 by bvilla            #+#    #+#              #
#    Updated: 2018/11/29 00:44:38 by bvilla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = errorhandler.c parser.c \
read_check_parse.c reader.c \
arrlib.c backtracker.c main.c

all: $(NAME)

$(NAME):
	@make re -C libft/ 
	@gcc $(SRC) -Wall -Wextra -Werror -Ofast -I . libft/libft.a -o $(NAME)
	@echo "compilation complete";
clean:
	@rm -f *.o
	@make clean -C libft/
	@echo "removed objects"
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "removed binary and libraries"
re: fclean all
