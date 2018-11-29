NAME = fillit

SRC = errorhandler.c parser.c \
read_check_parse.c reader.c \
arrlib.c backtracker.c main.c

all: $(NAME)

$(NAME):
	gcc -c $(SRC) -I . libft/libft.a -o fillit
	# ar rc libft.a *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
